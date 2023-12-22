#pragma once

#include <queue>
#include <string>
#include <queue>

#include "queue/OrderQueue.h"
#include "order/Types.h"

namespace queue
{

  class OrderMasterTable
  {
  public:
    static OrderMasterTable &getInstance()
    {
      static OrderMasterTable instance;
      return instance;
    }

    void enqueue(const Order &order)
    {
      const symbol_t &symbol = order.getSymbol();

      auto it = std::find_if(queueMap.begin(), queueMap.end(), [&symbol](const OrderQueue& queue) {
        return queue.getSymbol() == symbol;
      });

      if (it == queueMap.end()) {
        OrderQueue newQueue(symbol);

        newQueue.enqueue(order);

        queueMap.push_back(newQueue);
      } else {
        it->enqueue(order);
      }
    }

    OrderQueue &getQueue(const symbol_t &symbol)
    {
      auto it = std::find_if(queueMap.begin(), queueMap.end(), [&symbol](const OrderQueue& queue) {
        return queue.getSymbol() == symbol;
      });

      if (it == queueMap.end()) {
        LOG_ERROR("No queue found for symbol {}", symbol);
        throw std::runtime_error("No queue found for symbol " + symbol);
      }

      return *it;
    }

  private:
    OrderMasterTable() {}
    OrderMasterTable(OrderMasterTable const &) = delete;
    void operator=(OrderMasterTable const &) = delete;

    // Map of symbol to queue where the queue is ranekd by potentially matchable, 
    // i.e. the queue with the highest priority is the one with the highest chance of matching
    std::vector<OrderQueue> queueMap;
  };

}