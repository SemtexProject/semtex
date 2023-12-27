#pragma once

#include <queue>
#include <string>
#include <unordered_map>

#include "transaction/Transaction.h"
#include "transaction/TransactionManager.h"

#include "queue/OrderQueue.h"
#include "order/Types.h"

/*
 * The Exchange is a singleton responsible for submitting orders to the appropriate order queue.
 * 
 * Functionally speaking, the Exchange is a wrapper around an unordered map of OrderQueues.
 * However, the Exchange is also responsible for matching orders and submitting transactions
 * to the TransactionManager.
 * 
 * Methods:
 *  - submit: submits an order to the appropriate order queue for processing
 */
using namespace order;

class Exchange {

  //so you don't have to type this long ass type
  using OrderQueueMap = std::unordered_map<std::string, queue::OrderQueue>;

public:
  static Exchange &getInstance() {
    static Exchange instance;
    return instance;
  }

  //submit an order to the exchange, make transaction if necessary
  void submit(const order::Order &order) {

    //add the order to the order queue
    std::string symbol = order.getSymbol();
    OrderQueueMap::const_iterator itr = queueMap.find(symbol);
    if (itr == queueMap.end()) queueMap[symbol] = queue::OrderQueue(symbol);
    queueMap[symbol].enqueue(order);


    //try to execute an order
    auto& queue = queueMap[symbol];
    auto& buyQueue = queue.getQueue(side_t::BUY);
    auto& sellQueue = queue.getQueue(side_t::SELL);

    
    if (buyQueue.empty() || sellQueue.empty()) return;

    //get top two orders
    const auto& buy = buyQueue.top(), sell = sellQueue.top();

    //if the highest buy price is >= the lowest sell price
    if (buy.getPrice() >= sell.getPrice()) {
      order::quantity_t fillQuantity = std::min(buy.getQuantity(), sell.getQuantity());
      order::price_t medianPrice = (buy.getPrice() + sell.getPrice()) / 2.0;

      // Create transaction to execute
      transaction::Transaction t(
        buy,
        sell,
        fillQuantity,
        medianPrice
      );

      auto& executor = transaction::TransactionManager::getInstance();
      executor.execute(t);
      
      // Remove old orders from queue and add new orders
      buyQueue.pop();
      sellQueue.pop();

      //if the buy order is larger than the sell order, the buy order is only partially filled
      if (buy.getQuantity() > sell.getQuantity()) {
        buyQueue.push(order::Order(
          buy.getId(),
          buy.getQuantity() - sell.getQuantity(),
          buy.getPrice(),
          buy.getSide(),
          buy.getType(),
          buy.getSymbol(),
          buy.getDuration()
        ));
      //conversely, the sell order is only partially filled
      } else if (buy.getQuantity() < sell.getQuantity()) {
        sellQueue.push(order::Order(
          sell.getId(),
          sell.getQuantity() - buy.getQuantity(),
          sell.getPrice(),
          sell.getSide(),
          sell.getType(),
          sell.getSymbol(),
          sell.getDuration()
        ));
      }
    }


  }
  
private:
  //singleton class member data 
  Exchange() {}
  Exchange(Exchange const &) = delete;
  void operator=(Exchange const &) = delete;

  //k = symbol, v = OrderQueue
  OrderQueueMap queueMap;
};
