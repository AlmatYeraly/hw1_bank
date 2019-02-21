#ifndef _TRANSACTION_H_
#define _TRANSACTION_H_

#include <string>

class Transaction {
private:
  int customer_number;
  // 1 for withdrawal, 0 for deposit transaction types//
  bool transaction_type;
  float amount;
  std::string fees;
public:
  void process_tran(int c_num, bool type, float amount, std::string list_of_fees);
};

#endif