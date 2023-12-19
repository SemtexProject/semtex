#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <queue>
#include <vector>
#include <chrono>
#include <iostream>

#include "Order.h"
#include "LimitOrder.h"

class Orderbook {

public:
	virtual ~Orderbook() {}
    void addBuyOrder(const LimitOrder& order);
    void addSellOrder(const LimitOrder& order);
    void printBook();

private:

    //how should limit orders be sorted in the orderbook? by price and FIFO
    //buy orders are sorted by highest price
    struct BuyOrderComparator {
        bool operator()(const LimitOrder& a, const LimitOrder& b) {
            if (a.getPrice() == b.getPrice()) {
                return a.getTimeStamp() > b.getTimeStamp(); // Earlier timestamp has higher priority
            }
            return a.getPrice() < b.getPrice(); // Higher price has higher priority
        }
    };

    //sell orders are sorted by lowest price
    struct SellOrderComparator {
        bool operator()(const LimitOrder& a, const LimitOrder& b) {
            if (a.getPrice() == b.getPrice()) {
                return a.getTimeStamp() > b.getTimeStamp(); // Earlier timestamp has higher priority
            }
            return a.getPrice() > b.getPrice(); // Lower price has higher priority
        }
    };

    void printBuyOrders(std::priority_queue<LimitOrder, std::vector<LimitOrder>, BuyOrderComparator> pq);
    void printSellOrders(std::priority_queue<LimitOrder, std::vector<LimitOrder>, SellOrderComparator> pq);


    std::priority_queue<LimitOrder, std::vector<LimitOrder>, BuyOrderComparator> buyOrders;
    std::priority_queue<LimitOrder, std::vector<LimitOrder>, SellOrderComparator> sellOrders;
	

};

#endif
