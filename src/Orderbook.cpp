// #include "Orderbook.h"


// void Orderbook::addBuyOrder(const Order& order) {
//     buyOrders.push(order);
// }

// void Orderbook::addSellOrder(const Order& order) {
//     sellOrders.push(order);
// }

// void Orderbook::printBook() {
//     std::cout << "BUY ORDERS:\n";
//     printBuyOrders(buyOrders);
//     std::cout << "SELL ORDERS:\n";
//     printSellOrders(sellOrders);
// }


// void Orderbook::printBuyOrders(std::priority_queue<Order, std::vector<Order>, BuyOrderComparator> pq) {
//     while (!pq.empty()) {
//         Order topOrder = pq.top();
//         std::cout << topOrder;
//         pq.pop();
//     }
// }

// void Orderbook::printSellOrders(std::priority_queue<Order, std::vector<Order>, SellOrderComparator> pq) {
//     while (!pq.empty()) {
//         Order topOrder = pq.top();
//         std::cout << topOrder;
//         pq.pop();
//     }
// }