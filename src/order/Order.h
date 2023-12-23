#pragma once

#include <chrono>
#include <string>

#include "Types.h"

class Order {
public:

  //default constructor
  Order(
    long orderId, //individual id for each order
    int orderQuantity, //number of shares
    float orderPrice,
    order_side_t orderSide, //BUY, SELL
    order_type_t orderType, //LIMIT, STOP, MARKET
    std::string orderSymbol, //ticker
    duration_t orderDuration //DAY, GOOD_TILL_CANCELLED
  ) : 
    id(orderId), 
    quantity(orderQuantity), 
    side(orderSide), 
    type(orderType),
    price(orderPrice), 
    symbol(orderSymbol), 
    duration(orderDuration),
    timestamp(std::chrono::system_clock::now()) 
  {}

  friend std::ostream& operator<<(std::ostream& os, const Order& order) {
    std::string side_str = (order.side == order_side_t::BUY) ? "BUY" : "SELL";
    std::string duration_str = (order.duration == duration_t::DAY) ? "DAY" : "GOOD UNTIL CANCELLED";
    std::string nonMarketString = " at $" + std::to_string(order.price);
    os 
      << "[" 
      << order.id 
      << "] " 
      << side_str 
      << " " 
      << order.quantity 
      << " x " 
      << order.symbol 
      << nonMarketString
      << " (" 
      << duration_str 
      << ")" 
    << std::endl;

    return os;
  }
  

  //accessors
  float getQuantity() const { return quantity; }
  order_side_t getOrderSide() const { return side; }
  long getId() const { return id;}
  std::string getSymbol() const { return symbol; }
  duration_t getDuration() const { return duration; }
  time_point_t getTimeStamp() const { return timestamp; }
  float getPrice() const { return price; }
  order_type_t getOrderType() const { return type; }

private:
  long id;
  float price;
  unsigned int quantity;
  time_point_t timestamp;
  order_side_t side;
  order_type_t type;
  duration_t duration;
  std::string symbol;
};

