#pragma once

#include <chrono>
#include <string>

using time_point_t = std::chrono::system_clock::time_point;
using symbol_t = std::string;
using quantity_t = int;
using price_t = float;

enum order_side_t {
    BUY,
    SELL
};

enum order_type_t {
    LIMIT,
    STOP,
    MARKET
};

enum duration_t {
    DAY,
    GOOD_TILL_CANCELLED
};