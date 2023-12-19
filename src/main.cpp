
#include <iostream>
#include "Orderbook.h"
#include "LimitOrder.h"
#include <cstdlib>
#include <ctime>


int main() { 

	std::cout << "Welcome to the trading desk." << std::endl;
	srand (time(NULL));
	Orderbook ob;
	double increment = 0.05;
	int count = 0;
	for (double i = 0; i < 3; i += increment) {
		if (count % 2 == 0) increment += 0.09;
		else increment -= 0.03;
		count += 1;
		int shares = rand() % 100;
		ob.addBuyOrder(LimitOrder(6542654, shares, buy, "AAPL", 150 + i, day));
	}

	for (double i = 0; i < 3; i += increment) {
		if (count % 2 == 0) increment += 0.04;
		else increment -= 0.01;
		count += 1;
		int shares = rand() % 100;
		ob.addSellOrder(LimitOrder(6542654, shares, sell, "AAPL", 150 + i, day));
	}


	ob.printBook();
	


	return 0;
}
