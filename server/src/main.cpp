
#include <iostream>
#include <iomanip>

#include <spdlog/spdlog.h>

#include "core/Logger.h"
#include "order/Order.h"
#include "queue/OrderQueue.h"
#include "Exchange.h"
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

	Exchange &ex = Exchange::getInstance();

	// Enqueue all the orders
	for (auto &o : orders) {
		ex.submit(o);
	}

	// Print out the orders in the queue sorted by buy and then price
	std::sort(orders.begin(), orders.end(), [](const order::Order &a, const order::Order &b) {
		if (a.getSide() == order::side_t::BUY && b.getSide() == order::side_t::SELL)
			return true;
		else if (a.getSide() == order::side_t::SELL && b.getSide() == order::side_t::BUY)
			return false;
		else
			return a.getPrice() > b.getPrice();
	});


	for (auto &o : orders) {
		std::cout << o << std::endl;
	}



	return 0;
}

/*

*/
