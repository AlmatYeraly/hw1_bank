#include "account.h"

bool Account::operator==(const int a_num){
  return (account_number == a_num);
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

std::string Account::to_string(){
  return customer->get_name() + " - " + std::to_string(account_number) + " - " + std::to_string(balance);
}