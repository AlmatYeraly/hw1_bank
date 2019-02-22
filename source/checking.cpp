#include "checking.h"
#include <typeinfo>

// TBI
void Checking::deposit(float amount){
  balance += amount * (1 + add_interest());
  transactions.push_back(new Transaction);
  std::string list_of_fees = "No unusual fees";
  transactions[transactions.size()-1]->process_tran(customer->get_customer_id(), 0, amount, list_of_fees);
}

// TBI
void Checking::withdraw(float amount){
  balance -= amount * (1 + add_charge());
  transactions.push_back(new Transaction);
  std::string list_of_fees;
  if (balance < 0)
  {
    list_of_fees = "Overdraft penalty";
    int age = customer->get_age();
    if (age >=16 && age < 23){
      balance -= static_cast<Student*>(customer)->get_penalty();
    }
    else if (age >= 23 && age < 65){
      balance -= static_cast<Adult*>(customer)->get_penalty();
    }
    else if (age >=65){
      balance -= static_cast<Senior*>(customer)->get_penalty();
    }
    transactions[transactions.size()-1]->process_tran(customer->get_customer_id(), 1, amount, list_of_fees);
  }
  else
  {
    list_of_fees = "No unusual fees";
    transactions[transactions.size()-1]->process_tran(customer->get_customer_id(), 1, amount, list_of_fees);
  }
}

// Makes a deposit on the account if the balance and interest are greater than 0
float Checking::add_interest(){
  float interest;
  int age = customer->get_age();
  if (age >=16 && age < 23){
    interest = static_cast<Student*>(customer)->get_check();
  }
  else if (age >= 23 && age < 65){
    interest = static_cast<Adult*>(customer)->get_check();
  }
  else if (age >=65){
    interest = static_cast<Senior*>(customer)->get_check();
  }

  return interest;
}

float Checking::add_charge(){
  float charge;
  int age = customer->get_age();
  if (age >=16 && age < 23){
    charge = static_cast<Student*>(customer)->get_charge();
  }
   else if (age >= 23 && age < 65){
    charge = static_cast<Adult*>(customer)->get_charge();
  }
  else if (age >=65){
    charge = static_cast<Senior*>(customer)->get_charge();
  }

  return charge;
}