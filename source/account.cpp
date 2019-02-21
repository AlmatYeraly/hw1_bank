#include "account.h"

Account::Account(Customer* set_customer,int set_a_number) {
  customer = set_customer;
  account_number = set_a_number;
}

float Account::get_balance(){
  return balance;
}

void Account::set_customer(Customer updated_customer){
  customer = &updated_customer;
}

void Account::set_balance(float new_balance){
  balance = new_balance;
}

Customer* Account::get_customer(){
  return customer;
}

int Account::get_account_number(){
  return account_number;
}

std::string Account::to_string(){
  return customer->get_name() + " - " + std::to_string(account_number) + " - " + std::to_string(balance);
}