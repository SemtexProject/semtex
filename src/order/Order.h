#ifndef ORDER_H
#define ORDER_H

#include <chrono>
#include <string>

#include "Types.h"

class Order
{
public:
  Order(long orderId, int orderQuantity, float orderPrice,
        order_side_t orderSide, order_type_t orderType, std::string orderSymbol,
        duration_t orderDuration)
      : id(orderId), quantity(orderQuantity), side(orderSide), type(orderType),
        price(orderPrice), symbol(orderSymbol), duration(orderDuration),
        timestamp(std::chrono::system_clock::now()) {}
  
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

#endif
