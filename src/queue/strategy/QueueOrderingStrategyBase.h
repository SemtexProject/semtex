#pragma once

#include "order/Order.h"

class QueueOrderingStrategyBase {
public:
  bool operator()(const Order &a, const Order &b) const {
    const int res = comparator(a, b);

    // std::cout << "Comparing " << a.getPrice() << " and " << b.getPrice() << " = " << res << std::endl;

    if (res == 0) {
      return a.getTimeStamp() >
             b.getTimeStamp(); // Earlier timestamp has higher priority
    }

    return std::max(0, res); // Higher price has higher priority
  }

  // The comparator function returns 1 if a is to be ordered above b, 0 if they
  // are logically equal and -1 if b is logically greater than b
  virtual int comparator(const Order &lhs, const Order &rhs) const = 0;

  template <typename T>
  static int compare(const T &a, const T &b, bool asc = true) {
    int modifier = asc ? 1 : -1;

    // std::cout << "Comparing " << a << " and " << b << " = " << (a - b) * modifier << std::endl;

    if (a == b) {
      return 0;
    } else if (a < b) {
      return 1 * modifier;
    } else {
      return -1 * modifier;
    }
  }
};