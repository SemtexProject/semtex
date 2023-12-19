#include <string>
#include "Order.h"

//default constructor
Order::Order(
        long orderId,
        float orderQuantity,
        OrderSide orderSide,
        std::string orderSymbol, 
        Duration orderDuration
    ) : id(orderId),
        quantity(orderQuantity),
        side(orderSide),
        symbol(orderSymbol),
        duration(orderDuration),
        timestamp(std::chrono::steady_clock::now()) 
    {}


//accessors
float Order::getQuantity() const { return quantity; }
OrderSide Order::getOrderSide() const { return side; }
long Order::getId() const { return id; }
std::string Order::getSymbol() const { return symbol; }
Duration Order::getDuration() const { return duration; }
std::chrono::steady_clock::time_point Order::getTimeStamp() const { return timestamp; }

//mutators
bool Order::setQuantity(const float &q) {
    if (q <= 0) return false;
    quantity = q;
    return true;
}

bool Order::setSymbol(const std::string &s) {
    if (s.length() > 5) return false;
    symbol = s;
    return true;
}

bool Order::setOrderSide(const OrderSide &s) {
    side = s; 
    return true;
}
bool Order::setDuration(const Duration& d) {
    duration = d; 
    return true;    
}
