#pragma once

#include <queue>
#include <string>
#include <unordered_map>

#include "queue/OrderQueue.h"
#include "order/Types.h"


class OrderMasterTable {
public:
private:
  std::unordered_map<symbol_t, OrderQueue> orderQueues;
};