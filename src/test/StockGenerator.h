#pragma once

#include <fstream>
#include <string>
#include <random>

#include "util/Random.h"
#include "order/Types.h"
#include "order/Order.h"
#include "core/Logger.h"

namespace test
{

    class StockGenerator {
    public:
        StockGenerator(
            std::string symbolsFile, 
            price_t minPrice, 
            price_t maxPrice, 
            quantity_t minQuantity, 
            quantity_t maxQuantity
        );

        Order generateRandomOrder();

        order_side_t generateRandomSide();
        quantity_t generateRandomQuantity();
        price_t generateRandomPrice();

    private:
        std::vector<std::string> symbols;
        float minPrice;
        float maxPrice;
        int minQuantity;
        int maxQuantity;
    };
}