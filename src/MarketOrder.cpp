#include "MarketOrder.h"
#include "Order.h"
#include <string>

//default constructor
    MarketOrder::MarketOrder(
        long orderId, 
        float orderQuantity, 
        OrderSide orderOrderSide, 
        std::string orderSymbol, 
        Duration orderDuration
    )
    : Order(
        orderId, 
        orderQuantity, 
        orderOrderSide, 
        orderSymbol, 
        orderDuration
    ) {}
