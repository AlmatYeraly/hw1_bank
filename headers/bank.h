#ifndef _BANK_H_
#define _BANK_H_

#include "savings.h"
#include "checking.h"
#include <vector>
#include <iostream>

class Bank{
private:
  std::vector<Account*> accounts;
public:

  void add_account();
  void make_deposit();
  void make_withdrawal();
  Account* get_account();
};

#endif