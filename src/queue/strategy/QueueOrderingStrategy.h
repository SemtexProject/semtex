#pragma once

#include <stdexcept>

#include "queue/strategy/QueueOrderingStrategyBase.h"

class QueueOrderingStrategy : public QueueOrderingStrategyBase
{
public:
    int comparator(const Order &lhs, const Order &rhs) const
    {
        const side_t orderSide = lhs.getOrderSide();


        if (orderSide == side_t::BUY)
        {
            return QueueOrderingStrategyBase::compare(lhs.getPrice(), rhs.getPrice());
        }
        else if (orderSide == side_t::SELL)
        {
            return QueueOrderingStrategyBase::compare(lhs.getPrice(), rhs.getPrice(), false);
        }

        throw std::runtime_error("Invalid order side");
    }
};