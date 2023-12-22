#include "order/Order.h"

namespace order
{

    std::ostream &operator<<(std::ostream &os, const Order &order)
    {
        std::string side_str = (order.side == side_t::BUY) ? "BUY" : "SELL";
        std::string duration_str = (order.duration == duration_t::DAY) ? "DAY" : "GOOD UNTIL CANCELLED";
        std::string nonMarketString = " at $" + std::to_string(order.price);
        os  << "[" << std::left
            << std::setw(9) << order.id
            << "] "
            << std::setw(4) << side_str
            << " "
            << std::setw(3) << order.quantity
            << " x "
            << std::setw(3) << order.symbol
            << "at $"
            << std::setw(6) << std::setprecision(2) << std::fixed << order.price
            << " ("
            << duration_str
            << ")"
            << std::endl;

        return os;
    }

}