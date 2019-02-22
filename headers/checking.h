#ifndef _CHECKING_H_
#define _CHECKING_H_
#include "account.h"

class Checking : public Account {
public:
  Checking(Customer* set_customer, int set_a_number, bool type) : Account(set_customer, set_a_number, type) {}
  void  deposit(float amount);
  void withdraw(float amount);
  float add_interest();
  float add_charge();
};

#endif