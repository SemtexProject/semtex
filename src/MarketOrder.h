#ifndef MARKETORDER_H
#define MARKETORDER_H

#include "Order.h"
#include <string>

class MarketOrder : public Order {
public:
    //default constructor
    MarketOrder(
        long orderId, 
        float orderQuantity, 
        OrderSide orderOrderSide, 
        std::string orderSymbol, 
        Duration orderDuration
    );

};

#endif