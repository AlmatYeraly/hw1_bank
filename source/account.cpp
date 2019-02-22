#include "account.h"
#include <typeinfo>
#include <iostream>

Account::Account(Customer* set_customer,int set_a_number, bool type) {
  a_type = type;
  balance = 0;
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

bool Account::get_type(){
  return a_type;
}

// Outputs the account's information (including customer and transactions) into a formatted string //
std::string Account::to_string(){
  std::string info;
  int age = customer->get_age();
  info = "\nName: " + customer->get_name() + "\n";

  if (age >=16 && age < 23){
    info += "Customer group: Student \n";
  }
  else if (age >= 23 && age < 65){
    info += "Customer group: Adult \n";
  }
  else if (age >=65){
    info += "Customer group: Senior \n";
  }

  info += 
      "Address: " + customer->get_address() + "\n"
    + "Age: " + std::to_string(customer->get_age()) + "\n"
    + "Phone number: " + std::to_string(customer->get_telephone()) + "\n"
    + "Customer ID: " + std::to_string(customer->get_customer_id()) + "\n"
    + "Account ID: " + std::to_string(get_account_number()) + "\n";

  if ( a_type == 1){
    info += "Account type: Savings \n";
  }
  else if ( a_type == 0){
    info += "Account type: Checking \n";
  }

  info += "Balance: " + std::to_string(get_balance()) + "\n";

  for(int i = 0; i < transactions.size(); i++)
  {
    int transaction_number = i+1;
    info += "Transaction #" + std::to_string(transaction_number) + ": " 
      + std::to_string(customer->get_customer_id())
      + " " + transactions[i]->get_type() 
      + " " + std::to_string(transactions[i]->get_amount())
      + " " + transactions[i]->get_fees() + "\n";
  }
  return info;
}