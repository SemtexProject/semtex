#pragma once

#include "order/Order.h"
#include "util/Stringify.h"

#include "util/Time.h"


namespace transaction
{
    using namespace order;
    // A transaction is a trade between two orders.

    class Transaction : public util::Stringify<Transaction>
    {
    public:
        Transaction(Order order1, Order order2, quantity_t quantity, price_t price) : order1(order1), order2(order2), quantity(quantity), price(price), timestamp(std::chrono::system_clock::now()) {}

        Order getOrder1() { return order1; }
        Order getOrder2() { return order2; }

        quantity_t getQuantity() { return quantity; }
        price_t getPrice() { return price; }

        // Overload for Stringify interface
        std::string toString() const
        {
            std::stringstream ss;

            ss << "Transaction: \n\t"
               << order1 << "\n\t"
               << order2 << "\n\t"
               << "Quantity: " << quantity << "\n\t"
               << "Price: " << price << "\n\t"
               << "Timestamp: " << util::serializeTimePoint(timestamp);

            return ss.str();
        }

    private:
        Order order1;
        Order order2;

        quantity_t quantity;
        price_t price;
        time_point_t timestamp;
    };

}