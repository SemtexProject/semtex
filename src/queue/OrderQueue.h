#pragma once

#include <queue>
#include <stdexcept>

#include "order/Order.h"
#include "queue/strategy/QueueOrderingStrategy.h"

class OrderQueue {
  using PriorityQueue =
      std::priority_queue<Order, std::vector<Order>, QueueOrderingStrategy>;
public:
  void enqueue(const Order &order) {
    const order_side_t &orderSide = order.getOrderSide();

    if (orderSide == order_side_t::BUY) {
      buyQueue.push(order);
    } else if (orderSide == order_side_t::SELL) {
      sellQueue.push(order);
    }
  }

  PriorityQueue &getQueue(const order_side_t &orderSide) {
    if (orderSide == order_side_t::BUY) {
      return buyQueue;
    } else if (orderSide == order_side_t::SELL) {
      return sellQueue;
    }

    throw std::runtime_error("Invalid order side");
  }

  const PriorityQueue &getQueue(const order_side_t &orderSide) const {
    return getQueue(orderSide);
  }

  bool potentiallyMatchable() const {
    if (buyQueue.empty() || sellQueue.empty()) {
      return false;
    }

    const Order &buyOrder = buyQueue.top();
    const Order &sellOrder = sellQueue.top();

    return buyOrder.getPrice() >= sellOrder.getPrice();
  }

private:
  PriorityQueue buyQueue, sellQueue;
};