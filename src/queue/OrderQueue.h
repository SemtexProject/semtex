#pragma once

#include <queue>
#include <stdexcept>

#include "order/Order.h"


//compares two orders
auto compareOrders = [](const Order& lhs, const Order& rhs) {
  
  //if we have buy orders
  if (lhs.getOrderSide() == order_side_t::BUY && rhs.getOrderSide() == order_side_t::BUY) {
    if (lhs.getPrice() != rhs.getPrice()) return lhs.getPrice() > rhs.getPrice(); //the higher the buy order, the better
    return lhs.getTimeStamp() > rhs.getTimeStamp();
  }
  //if we have sell orders
  else if (lhs.getOrderSide() == order_side_t::SELL && rhs.getOrderSide() == order_side_t::SELL) {
    if (lhs.getPrice() != rhs.getPrice()) return lhs.getPrice() < rhs.getPrice(); //the lower the sell order, the better
    return lhs.getTimeStamp() > rhs.getTimeStamp();
  }
  //order mismatch, throw an error
  throw std::runtime_error("compareOrders function has received two separate sided orders (BUY order compared with SELL order");
  
};

class OrderQueue {

  //define a priority queue that handles the Order type, compares properly using compareOrders
  using PriorityQueue = std::priority_queue<Order, std::vector<Order>, decltype(compareOrders)>;

public:

  //default constructor
  OrderQueue(
    const std::string &symbol = "DEFAULT SYMBOL" //what stock is this queue for? i.e. AAPL has its own OrderQueue
  ) : 
    symbol(symbol),
    buyQueue(compareOrders), //priority queues need to take in a comparator function to know how to sort their type
    sellQueue(compareOrders) //priority queues need to take in a comparator function to know how to sort their type
  {}

  //gets the representative symbol
  const std::string &getSymbol() const { return symbol; }

  //add order to the queue
  void enqueue(const Order &order) {
    const order_side_t &orderSide = order.getOrderSide();

    if (orderSide == order_side_t::BUY) buyQueue.push(order);
    else if (orderSide == order_side_t::SELL) sellQueue.push(order);
  }

  //return the buy/sell queue
  PriorityQueue &getQueue(const order_side_t &orderSide) {
    if (orderSide == order_side_t::BUY) return buyQueue;
    else if (orderSide == order_side_t::SELL) return sellQueue;

    throw std::runtime_error("Invalid order side");
  }

  //return unmodifiable buy/sell queue
  const PriorityQueue &getQueue(const order_side_t &orderSide) const {
    return getQueue(orderSide);
  }

private:
  std::string symbol;
  PriorityQueue buyQueue, sellQueue;
};