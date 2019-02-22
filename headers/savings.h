#ifndef _SAVINGS_H_
#define _SAVINGS_H_
#include "account.h"

class Savings : public Account {
public:
  Savings(Customer* set_customer, int set_a_number, bool type) : Account(set_customer, set_a_number, type) {}
  void deposit(float amount);
  void withdraw(float amount);
  float add_interest();
  float add_charge();
};

#endif