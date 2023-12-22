
#include <iostream>
#include <iomanip>

#include <spdlog/spdlog.h>

#include "core/Logger.h"
#include "order/Order.h"
#include "queue/OrderQueue.h"
#include "MasterTable.h"
#include "test/StockGenerator.h"

std::string serializeTimePoint(const order::time_point_t& time);

int main()
{
	// Initialize the logger
	core::Logger::init();

	// Create a list of 50 orders with random prices, quantities, and IDs with 25 buy orders and 25 sell orders
	std::vector<order::Order> orders;
	for (int i = 0; i < 50; i++)
	{
		test::StockGenerator sg("src/test/S&P500_Symbols.txt", 1.0, 100.0, 1, 100);
		orders.push_back(sg.generateRandomOrder());
	}

	MasterTable &mt = MasterTable::getInstance();

	// Enqueue all the orders
	for (auto &o : orders) {
		std::cout << o;
		mt.addOrder(o);
	}




	return 0;
}

/*
std::string serializeTimePoint(const time_point_t& time)
{
	std::string format("%m/%d/%Y %H:%M:%S");
    std::time_t tt = std::chrono::system_clock::to_time_t(time);
    // std::tm tm = *std::gmtime(&tt); //GMT (UTC)
    std::tm tm = *std::localtime(&tt); //Locale time-zone, usually UTC by default.
    std::stringstream ss;
    ss << std::put_time( &tm, format.c_str());
    return ss.str();
}
*/
