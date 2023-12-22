#pragma once

#include <chrono>
#include <string>

namespace order
{

    using time_point_t = std::chrono::system_clock::time_point;
    using symbol_t = std::string;
    using quantity_t = unsigned int;
    using price_t = float;

    enum side_t
    {
        BUY,
        SELL
    };

    enum type_t
    {
        LIMIT,
        STOP,
        MARKET
    };

    enum duration_t
    {
        DAY,
        GOOD_TILL_CANCELLED
    };

    enum status_t
    {
        OPEN,
        FILLED,
        PARTIALLY_FILLED,
        CANCELLED
    };

}
