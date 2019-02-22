#include "savings.h"
#include <typeinfo>

// Adds amount into the balance as well as interest for putting it into the account
void Savings::deposit(float amount){
  balance += amount + (amount * add_interest());
  transactions.push_back(new Transaction);
  std::string list_of_fees = "No unusual fees";
  transactions[transactions.size()-1]->process_tran(customer->get_customer_id(), 0, amount, "No fees");
}

// Takes amount in argument out of the accounts' balance as well as a charge
// If user withdraws more than what is in the bank (resulting in a negative balance), an additional overdraft penalty is taken
void Savings::withdraw(float amount){
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
float Savings::add_interest(){
  float interest;
  int age = customer->get_age();
  if (age >=16 && age < 23){
    interest = static_cast<Student*>(customer)->get_savings();
  }
  else if (age >= 23 && age < 65){
    interest = static_cast<Adult*>(customer)->get_savings();
  }
  else if (age >=65){
    interest = static_cast<Senior*>(customer)->get_savings();
  }

  return interest;
}

float Savings::add_charge(){
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