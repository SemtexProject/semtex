#pragma once

#include <stdexcept>

#include "queue/strategy/QueueOrderingStrategyBase.h"

class QueueOrderingStrategy : public QueueOrderingStrategyBase
{
public:
    int comparator(const Order &lhs, const Order &rhs) const
    {
        const order_side_t orderSide = lhs.getOrderSide();


        if (orderSide == order_side_t::BUY)
        {
            return QueueOrderingStrategyBase::compare(lhs.getPrice(), rhs.getPrice());
        }
        else if (orderSide == order_side_t::SELL)
        {
            return QueueOrderingStrategyBase::compare(lhs.getPrice(), rhs.getPrice(), false);
        }

        throw std::runtime_error("Invalid order side");
    }
};