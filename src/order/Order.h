#pragma once

#include <chrono>
#include <string>
#include <iostream>
#include <iomanip>

#include "Types.h"

namespace order 
{

class Order {
public:

  //default constructor
  Order(
    long orderId, //individual id for each order
    quantity_t orderQuantity, //number of shares
    price_t orderPrice,
    side_t orderSide, //BUY, SELL
    type_t orderType, //LIMIT, STOP, MARKET
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

  

  //accessors
  float getQuantity() const { return quantity; }
  side_t getSide() const { return side; }
  long getId() const { return id;}
  std::string getSymbol() const { return symbol; }
  duration_t getDuration() const { return duration; }
  time_point_t getTimeStamp() const { return timestamp; }
  float getPrice() const { return price; }
  type_t getType() const { return type; }

  friend std::ostream& operator<<(std::ostream& os, const Order& order);

private:
  long id;
  float price;
  unsigned int quantity;
  time_point_t timestamp;
  side_t side;
  type_t type;
  duration_t duration;
  std::string symbol;
};

}