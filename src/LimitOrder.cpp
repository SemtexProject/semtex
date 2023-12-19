#include "LimitOrder.h"
#include "Order.h"

#include <string>
#include <iostream>


//default constructor
LimitOrder::LimitOrder(
        long orderId, 
        float orderQuantity, 
        OrderSide orderOrderSide,
        std::string orderSymbol,
        double orderPrice, 
        Duration orderDuration
    ) 
    : Order( //inherits order class
        orderId,
        orderQuantity,
        orderOrderSide,
        orderSymbol,
        orderDuration
    ), 
        price(orderPrice) 
    {}

//accessors
double LimitOrder::getPrice() const { return price; }

//mutators
bool LimitOrder::setPrice(const double &p) {
    if (p <= 0) return false;
    price = p;
    return true;
}

std::ostream& operator<<(std::ostream& os, const LimitOrder& obj) {
    std::string side = (obj.getOrderSide() == buy) ? "BUY" : "SELL";
    std::string duration = (obj.getDuration() == day) ? "DAY" : "GOOD UNTIL CANCELLED";

    os << "[" << obj.getId() << "] " << side << " " << obj.getQuantity() << " x " 
    << obj.getSymbol() << " at $" << obj.getPrice() << "\n";

    return os;
}


