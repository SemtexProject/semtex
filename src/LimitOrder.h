#ifndef LIMITORDER_H
#define LIMITORDER_H

#include "Order.h"
#include <string>

class LimitOrder : public Order {
    public:
        //default constructor
        LimitOrder(
            long orderId, 
            float orderQuantity, 
            OrderSide orderOrderSide, 
            std::string orderSymbol, 
            double orderPrice, 
            Duration orderDuration
        );

        //accessors
        double getPrice() const;

        //mutators
        bool setPrice(const double &p);

    private:
        double price;
    
    //print out limit orders
    friend std::ostream& operator<<(std::ostream& os, const LimitOrder& obj);
};


#endif 