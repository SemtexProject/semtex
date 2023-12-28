#pragma once

#include <queue>
#include <stdexcept>

#include "order/Order.h"

namespace queue
{

  using namespace order;

  struct OrderQueueComparator
  {

    bool operator()(const Order &lhs, const Order &rhs) const
    {

      // if we have buy orders
      if (lhs.getSide() == side_t::BUY && rhs.getSide() == side_t::BUY)
      {
        if (lhs.getPrice() != rhs.getPrice())
          return lhs.getPrice() < rhs.getPrice(); // the higher the buy order, the better
        return lhs.getTimeStamp() < rhs.getTimeStamp();
      }
      // if we have sell orders
      else if (lhs.getSide() == side_t::SELL && rhs.getSide() == side_t::SELL)
      {
        if (lhs.getPrice() != rhs.getPrice())
          return lhs.getPrice() > rhs.getPrice(); // the lower the sell order, the better
        return lhs.getTimeStamp() > rhs.getTimeStamp();
      }
      // order mismatch, throw an error
      const std::string errMsg = "During comparison, received two orders with different sides: " + std::to_string(lhs.getSide()) + " and " + std::to_string(rhs.getSide());

      LOG_ERROR(errMsg);
      throw std::runtime_error(errMsg);
    }
  };

  class OrderQueue
  {

    // define a priority queue that handles the Order type, compares properly using compareOrders
    using PriorityQueue = std::priority_queue<Order, std::vector<Order>, OrderQueueComparator>;

  public:
    // default constructor
    OrderQueue(
        const std::string &symbol = "DEFAULT" // what stock is this queue for? i.e. AAPL has its own OrderQueue
        ) : symbol(symbol)
    {}

    // gets the representative symbol
    const std::string &getSymbol() const { return symbol; }

    // add order to the queue
    void enqueue(const Order &order)
    {
      const side_t &orderSide = order.getSide();

      if (orderSide == side_t::BUY)
        buyQueue.push(order);
      else if (orderSide == side_t::SELL)
        sellQueue.push(order);
    }

    // return the buy/sell queue
    PriorityQueue &getQueue(const side_t &orderSide)
    {
      if (orderSide == side_t::BUY)
        return buyQueue;
      else if (orderSide == side_t::SELL)
        return sellQueue;

      throw std::runtime_error("Invalid order side");
    }

    // return unmodifiable buy/sell queue
    const PriorityQueue &getQueue(const side_t &orderSide) const
    {
      return getQueue(orderSide);
    }

  private:
    std::string symbol;
    PriorityQueue buyQueue, sellQueue;
  };

}