#ifndef _SAVINGS_H_
#define _SAVINGS_H_
#include "account.h"

class Savings : public Account {
public:
  void deposit(float amount);
  void withdraw(float amount);
  void add_interest();
};

#endif