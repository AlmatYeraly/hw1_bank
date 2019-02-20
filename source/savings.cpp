#include "savings.h"
#include <typeinfo>

// TBI
void Savings::deposit(float amount){

}

// TBI
void Savings::withdraw(float amount){

}

void Savings::add_interest(){
  float interest;
  if ( typeid(customer) == typeid(Senior*)){
    interest = static_cast<Senior*>(customer)->get_savings();
  }
  else if ( typeid(customer) == typeid(Adult*)){
    interest = static_cast<Adult*>(customer)->get_savings();
  }
  else if ( typeid(customer) == typeid(Student*)){
    interest = static_cast<Student*>(customer)->get_savings();
  }
  // What if balance is negative (is that a possibility?) //
  deposit(balance * interest);
}