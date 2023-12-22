
#include <iostream>
#include <iomanip>
#include <thread>
#include <memory>

#include <spdlog/spdlog.h>

#include "core/Logger.h"
#include "order/Order.h"
#include "queue/OrderQueue.h"
#include "queue/OrderMasterTable.h"
#include "test/StockGenerator.h"

std::string serializeTimePoint(const time_point_t &time);

int main()
{

	// Initialize the logger
	core::Logger::init();

	// Get list of first 5 symbols from S&P500

	// Read in the symbols file
	std::ifstream file("src/test/S&P500_Symbols.txt");

	if (!file.is_open())
		LOG_ERROR("Could not open symbols file {}", "src/test/S&P500_Symbols.txt");

	std::string line;
	std::vector<std::string> symbols;
	for (int i = 0; i < 5 && std::getline(file, line); i++)
	{
		std::cout << line << std::endl;
		symbols.push_back(line);
	}

	// Create a list of 50 orders with random prices, quantities, and IDs with 25 buy orders and 25 sell orders
	std::vector<order::Order> orders;
	for (int i = 0; i < 50; i++)
	{
		test::StockGenerator sg(symbols, 1.0, 100.0, 1, 100);
		orders.push_back(sg.generateRandomOrder());
	}


	// List order for first symbol
	std::cout << "Orders for symbol " << symbols[0] << std::endl;
	std::cout << std::setw(10) << "ID" << std::setw(10) << "Side" << std::setw(10) << "Quantity" << std::setw(10) << "Price" << std::setw(10) << "Type" << std::setw(10) << "Symbol" << std::setw(10) << "Duration" << std::setw(10) << "Time" << std::endl;
	for (auto &o : orders)
		if (o.getSymbol() == symbols[0])
			std::cout << std::setw(10) << o.getId() << std::setw(10) << (o.getOrderSide() == side_t::BUY ? "BUY" : "SELL") << std::setw(10) << o.getQuantity() << std::setw(10) << o.getPrice() << std::setw(10) << (o.getOrderType() == order::type_t::LIMIT ? "LIMIT" : "MARKET") << std::setw(10) << o.getSymbol() << std::setw(10) << (o.getDuration() == order::duration_t::DAY ? "DAY" : "IOC") << std::setw(10) << serializeTimePoint(o.getTimeStamp()) << std::endl;

	auto &queue = mt.getQueue(symbols[0]);
	// Print out top buy and sell orders
	auto buyQueue = queue.getQueue(side_t::BUY);
	auto sellQueue = queue.getQueue(side_t::SELL);

	// Num orders each
	std::cout << "Num buy orders: " << buyQueue.size() << std::endl;
	std::cout << "Num sell orders: " << sellQueue.size() << std::endl;


	return 0;
}

std::string serializeTimePoint(const time_point_t &time)
{
	std::string format("%m/%d/%Y %H:%M:%S");
	std::time_t tt = std::chrono::system_clock::to_time_t(time);
	// std::tm tm = *std::gmtime(&tt); //GMT (UTC)
	std::tm tm = *std::localtime(&tt); // Locale time-zone, usually UTC by default.
	std::stringstream ss;
	ss << std::put_time(&tm, format.c_str());
	return ss.str();
}
