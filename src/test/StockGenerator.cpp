#include "test/StockGenerator.h"

// Use Random.h to generate random numbers
namespace test
{

    StockGenerator::StockGenerator(std::vector<std::string> symbols, price_t minPrice, price_t maxPrice, quantity_t minQuantity, quantity_t maxQuantity)
        : symbols(symbols), minPrice(minPrice), maxPrice(maxPrice), minQuantity(minQuantity), maxQuantity(maxQuantity)
    {}

    Order StockGenerator::generateRandomOrder()
    {
        auto id = static_cast<int>(util::random(0, 999999999));
        auto symbol = symbols.at(util::random(0, static_cast<int>(symbols.size())));

        return Order{id, generateRandomQuantity(), generateRandomPrice(), generateRandomSide(), type_t::LIMIT, symbol, duration_t::DAY};
    }

    side_t StockGenerator::generateRandomSide()
    {
        return std::round(util::random(0, 1)) == 0 ? side_t::BUY : side_t::SELL;
    }

    quantity_t StockGenerator::generateRandomQuantity()
    {
        return util::random(minQuantity, maxQuantity);
    }

    price_t StockGenerator::generateRandomPrice()
    {
        return util::random(minPrice, maxPrice);
    }
}