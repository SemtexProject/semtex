#pragma once

#include <chrono>
#include <string>

#include "Types.h"

using namespace order;

namespace order
{

class Order
{
public:
  Order(long orderId, quantity_t orderQuantity, price_t orderPrice,
        side_t orderSide, type_t orderType, std::string orderSymbol,
        duration_t orderDuration)
      : id(orderId), quantity(orderQuantity), side(orderSide), type(orderType),
        price(orderPrice), symbol(orderSymbol), duration(orderDuration),
        timestamp(std::chrono::system_clock::now()) {}
  
  quantity_t getQuantity() const { return quantity; }
  side_t getOrderSide() const { return side; }
  long getId() const { return id;}
  std::string getSymbol() const { return symbol; }
  duration_t getDuration() const { return duration; }
  time_point_t getTimeStamp() const { return timestamp; }
  float getPrice() const { return price; }
  type_t getOrderType() const { return type; }

  void setQuantity(quantity_t newQuantity) { quantity = newQuantity; }

private:
  long id;
  price_t price;
  quantity_t quantity;
  time_point_t timestamp;
  side_t side;
  type_t type;
  duration_t duration;
  std::string symbol;
};

}
