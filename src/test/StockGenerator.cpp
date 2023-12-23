#include "test/StockGenerator.h"

// Use Random.h to generate random numbers
namespace test
{

    StockGenerator::StockGenerator(
        std::string symbolsFile, 
        price_t minPrice, 
        price_t maxPrice, 
        quantity_t minQuantity, 
        quantity_t maxQuantity
    ) : 
        minPrice(minPrice), 
        maxPrice(maxPrice), 
        minQuantity(minQuantity), 
        maxQuantity(maxQuantity)
    {

        // Read in the symbols file
        std::ifstream file(symbolsFile);

        if (!file.is_open())
            LOG_ERROR("Could not open symbols file {}", symbolsFile);

        std::string line;
        while (std::getline(file, line))
        {
            symbols.push_back(line);
        }
    }

    Order StockGenerator::generateRandomOrder()
    {
        auto id = static_cast<int>(util::random(0, 999999999));
        auto symbol = symbols.at(util::random(0, static_cast<int>(symbols.size()) - 1));

        return Order{
            id, 
            generateRandomQuantity(), 
            generateRandomPrice(), 
            generateRandomSide(), 
            order_type_t::LIMIT, 
            symbol, duration_t::DAY
        };
    }

    order_side_t StockGenerator::generateRandomSide()
    {
        return util::random(0, 1) == 0 ? order_side_t::BUY : order_side_t::SELL;
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