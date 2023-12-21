
#include <iostream>
#include <iomanip>

#include "order/Order.h"
#include "queue/OrderQueue.h"

std::string serializeTimePoint(const time_point_t& time);

int main()
{

	// Create a list of 50 orders with random prices, quantities, and IDs with 25 buy orders and 25 sell orders
	std::vector<Order> orders;
	for (int i = 0; i < 50; i++)
	{
		Order o = Order(i, rand() % 100, rand() % 100 + (i % 2 == 1) * 1, (i % 2 == 0) ? order_side_t::BUY : order_side_t::SELL, order_type_t::MARKET, "AAPL", duration_t::DAY);
		orders.push_back(o);
	}

	// Create an OrderQueue object
	OrderQueue q;

	// Enqueue all the orders
	for (auto &o : orders)
		q.enqueue(o);

	std::cout << "Is the queue potentially matchable? " << q.potentiallyMatchable() << std::endl;

	auto &buyQueue = q.getQueue(order_side_t::BUY);
	auto &sellQueue = q.getQueue(order_side_t::SELL);

	std::cout << "ID   | Symbol | Price | Quantity | Order Date" << std::endl;
	while (!buyQueue.empty())
	{
		auto &top = buyQueue.top();

		std::cout << std::setw(4) << top.getId() << "    ";
		std::cout << std::setw(4) << top.getSymbol() << "   ";
		std::cout << std::setw(4) << top.getPrice() << "     ";
		std::cout << std::setw(4) << top.getQuantity() << "         ";
		std::cout << std::setw(4) << serializeTimePoint(top.getTimeStamp()) << " " << std::endl;

		buyQueue.pop();
	}

	std::cout << "ID   | Symbol | Price | Quantity | Order Date" << std::endl;
	while (!sellQueue.empty())
	{
		auto &top = sellQueue.top();

		std::cout << std::setw(4) << top.getId() << "    ";
		std::cout << std::setw(4) << top.getSymbol() << "   ";
		std::cout << std::setw(4) << top.getPrice() << "     ";
		std::cout << std::setw(4) << top.getQuantity() << "         ";
		std::cout << std::setw(4) << serializeTimePoint(top.getTimeStamp()) << " " << std::endl;
		
		sellQueue.pop();
	}

	return 0;
}

std::string serializeTimePoint(const time_point_t& time)
{
	std::string format("%m/%d/%Y %H:%M:%S");
    std::time_t tt = std::chrono::system_clock::to_time_t(time);
    // std::tm tm = *std::gmtime(&tt); //GMT (UTC)
    std::tm tm = *std::localtime(&tt); //Locale time-zone, usually UTC by default.
    std::stringstream ss;
    ss << std::put_time( &tm, format.c_str() );
    return ss.str();
}