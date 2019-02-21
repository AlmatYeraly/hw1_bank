#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include "transaction.h"
#include "senior.h"
#include "adult.h"
#include "student.h"
#include <vector>

class Account {
protected:
  Customer* customer;
  float balance;
  int account_number;
  std::vector<Transaction*> transactions;

public:
  Account(Customer* set_customer, int set_a_number);
  float get_balance();
  Customer* get_customer();
  int get_account_number();
  std::string to_string();
  
  void set_customer(Customer updated_customer);
  void set_balance(float new_balance);

  void virtual  deposit(float amount) = 0;
  void virtual withdraw(float amount) = 0;
};

#endif