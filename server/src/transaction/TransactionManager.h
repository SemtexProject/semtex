#pragma once

#include "order/Order.h"

namespace transaction
{

// The transaction manager is a singleton responsible for submitting transactions for processing.
// TODO: Implement the transaction manager.
class TransactionManager {
public:
  static TransactionManager &getInstance() {
    static TransactionManager instance;
    return instance;
  }

  void execute(const transaction::Transaction &transaction) {
    std::cout << "Executing transaction: " << transaction << std::endl;
  }
};

}