#pragma once

#include <queue>
#include <string>
#include <queue>

#include "queue/OrderQueue.h"
#include "order/Types.h"

namespace queue
{
  struct OrderMasterTableComparator
  {
    bool operator()(const OrderQueue &lhs, const OrderQueue &rhs) const
    {
      return lhs.potentiallyMatchable() < rhs.potentiallyMatchable();
    }
  };

  class OrderMasterTable
  {
  public:
    static OrderMasterTable &getInstance()
    {
      static OrderMasterTable instance;
      return instance;
    }

    void enqueue(const Order &order)
    {
      auto it = std::find_if(queueMap.begin(), queueMap.end(), [&order](const OrderQueue& queue) {
        return queue.getSymbol() == order.getSymbol();
      });

      if (it == queueMap.end()) {
        LOG_INFO("Creating new queue for orderId {} and symbol {}", order.getId(), order.getSymbol());
        queueMap.emplace_back(OrderQueue(order.getSymbol()));
        it = queueMap.end() - 1;
      }

      auto queue = *it;

      LOG_INFO("Enqueuing orderId {} for symbol {}", order.getId(), order.getSymbol());
      queue.enqueue(order);
    }
  private:
    OrderMasterTable() {}
    OrderMasterTable(OrderMasterTable const &) = delete;
    void operator=(OrderMasterTable const &) = delete;

    // Map of symbol to queue where the queue is ranekd by potentially matchable, 
    // i.e. the queue with the highest priority is the one with the highest chance of matching
    std::vector<OrderQueue> queueMap;
  };

}