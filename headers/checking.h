#ifndef _CHECKING_H_
#define _CHECKING_H_
#include "account.h"

class Checking : public Account {
public:
  Checking(Customer* set_customer, int set_a_number) : Account(set_customer, set_a_number) {}
  void deposit(float amount);
  void withdraw(float amount);
  void add_interest();
};

#endif