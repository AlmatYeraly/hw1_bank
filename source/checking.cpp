#include "checking.h"
#include <typeinfo>

// TBI
void Checking::deposit(float amount){
  transactions.push_back(new Transaction);
  std::string list_of_fees = "No unusual fees";
  transactions[transactions.size()-1]->process_tran(customer->get_customer_id(), 0, amount, "No fees");
}

// TBI
void Checking::withdraw(float amount){
  transactions.push_back(new Transaction);
  transactions[transactions.size()-1]->process_tran(customer->get_customer_id(), 1, amount, "No fees");
}

// Makes a deposit on the account if the balance and interest are greater than 0
void Checking::add_interest(){
  float interest;
  if ( typeid(customer) == typeid(Senior*)){
    interest = static_cast<Senior*>(customer)->get_check();
  }
  else if ( typeid(customer) == typeid(Adult*)){
    interest = static_cast<Adult*>(customer)->get_check();
  }
  else if ( typeid(customer) == typeid(Student*)){
    interest = static_cast<Student*>(customer)->get_check();
  }

  if (balance > 0 && interest > 0){
    deposit(balance*interest);
  }
}