#pragma once

#include <chrono>
#include <string>

//time stamp for an individual order
using time_point_t = std::chrono::system_clock::time_point;

//symbol or ticker
using symbol_t = std::string;

//amount of shares or units
using quantity_t = int;

//price for a limit order
using price_t = float;

//do you want to buy the assets or sell the assets?
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