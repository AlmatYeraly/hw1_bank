#ifndef _CHECKING_H_
#define _CHECKING_H_
#include "account.h"

class Checking : public Account {
public:
  void deposit(float amount);
  void withdraw(float amount);
  void add_interest();
};

#endif