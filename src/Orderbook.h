#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <queue>
#include <vector>
#include <chrono>
#include <iostream>

#include "order/Order.h"

class Orderbook {

public:
	virtual ~Orderbook() {}
    void addBuyOrder(const Order& order);
    void addSellOrder(const Order& order);
    void printBook();

private:

    //how should limit orders be sorted in the orderbook? by price and FIFO
    //buy orders are sorted by highest price
    struct BuyOrderComparator {
        bool operator()(const Order& a, const Order& b) {
            if (a.getPrice() == b.getPrice()) {
                return a.getTimeStamp() > b.getTimeStamp(); // Earlier timestamp has higher priority
            }
            return a.getPrice() < b.getPrice(); // Higher price has higher priority
        }
    };

    //sell orders are sorted by lowest price
    struct SellOrderComparator {
        bool operator()(const Order& a, const Order& b) {
            if (a.getPrice() == b.getPrice()) {
                return a.getTimeStamp() > b.getTimeStamp(); // Earlier timestamp has higher priority
            }
            return a.getPrice() > b.getPrice(); // Lower price has higher priority
        }
    };

    void printBuyOrders(std::priority_queue<Order, std::vector<Order>, BuyOrderComparator> pq);
    void printSellOrders(std::priority_queue<Order, std::vector<Order>, SellOrderComparator> pq);


    std::priority_queue<Order, std::vector<Order>, BuyOrderComparator> buyOrders;
    std::priority_queue<Order, std::vector<Order>, SellOrderComparator> sellOrders;
	

};

#endif
