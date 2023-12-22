#pragma once

#include <queue>
#include <stdexcept>

#include "order/Order.h"
#include "queue/strategy/QueueOrderingStrategy.h"

namespace queue {

class OrderQueue {
  using PriorityQueue =
      std::priority_queue<Order, std::vector<Order>, QueueOrderingStrategy>;
public:
  OrderQueue(const std::string &symbol) : symbol(symbol) {}

  const std::string &getSymbol() const { return symbol; }

  void enqueue(const Order &order) {
    const side_t &orderSide = order.getOrderSide();

    if (orderSide == side_t::BUY) {
      buyQueue.push(order);
    } else if (orderSide == side_t::SELL) {
      sellQueue.push(order);
    }
  }

  PriorityQueue &getQueue(const side_t &orderSide) {
    if (orderSide == side_t::BUY) {
      return buyQueue;
    } else if (orderSide == side_t::SELL) {
      return sellQueue;
    }

    throw std::runtime_error("Invalid order side");
  }

  const PriorityQueue &getQueue(const side_t &orderSide) const {
    return getQueue(orderSide);
  }

  

private:
  std::string symbol;
  PriorityQueue buyQueue, sellQueue;
};

}