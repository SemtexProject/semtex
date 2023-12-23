#pragma once

#include <queue>
#include <string>


#include "queue/OrderQueue.h"
#include "order/Types.h"


class MasterTable {

  //so you don't have to type this long ass type
  using OrderQueueMap = std::unordered_map<std::string, OrderQueue>;

public:
  static MasterTable &getInstance() {
    static MasterTable instance;
    return instance;
  }

  void addOrder(const Order &order) {
    std::string symbol = order.getSymbol();
    OrderQueueMap::const_iterator itr = queueMap.find(symbol);
    if (itr == queueMap.end()) queueMap[symbol] = OrderQueue(symbol);
    queueMap[symbol].enqueue(order);
  }
private:
  MasterTable() {}
  MasterTable(MasterTable const &) = delete;
  void operator=(MasterTable const &) = delete;

  //k=symbol, v=OrderQueue
  OrderQueueMap queueMap;
};
