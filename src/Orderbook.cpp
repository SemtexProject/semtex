#include "Orderbook.h"


void Orderbook::addBuyOrder(const LimitOrder& order) {
    buyOrders.push(order);
}

void Orderbook::addSellOrder(const LimitOrder& order) {
    sellOrders.push(order);
}

void Orderbook::printBook() {
    std::cout << "BUY ORDERS:\n";
    printBuyOrders(buyOrders);
    std::cout << "SELL ORDERS:\n";
    printSellOrders(sellOrders);
}


void Orderbook::printBuyOrders(std::priority_queue<LimitOrder, std::vector<LimitOrder>, BuyOrderComparator> pq) {
    while (!pq.empty()) {
        LimitOrder topOrder = pq.top();
        std::cout << topOrder;
        pq.pop();
    }
}

void Orderbook::printSellOrders(std::priority_queue<LimitOrder, std::vector<LimitOrder>, SellOrderComparator> pq) {
    while (!pq.empty()) {
        LimitOrder topOrder = pq.top();
        std::cout << topOrder;
        pq.pop();
    }
}