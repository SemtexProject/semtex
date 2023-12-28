#include "order/Order.h"

namespace order
{

    std::string Order::toString() const
    {
        std::string side_str = (side == side_t::BUY) ? "BUY" : "SELL";
        std::string duration_str = (duration == duration_t::DAY) ? "DAY" : "GOOD UNTIL CANCELLED";
        std::string nonMarketString = " at $" + std::to_string(price);
        std::stringstream ss;
        ss  << "[" << std::left
            << std::setw(9) << id
            << "] "
            << std::setw(4) << side_str
            << " "
            << std::setw(3) << quantity
            << " x "
            << std::setw(3) << symbol
            << " at $"
            << std::setw(6) << std::setprecision(2) << std::fixed << price
            << " ("
            << duration_str
            << ")";

        return ss.str();
    }

}