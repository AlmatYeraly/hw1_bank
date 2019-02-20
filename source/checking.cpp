#include "checking.h"
#include <typeinfo>

// TBI
void Checking::deposit(float amount){

}

// TBI
void Checking::withdraw(float amount){

}

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
  // What if balance is negative (is that a possibility?) //
  deposit(balance*interest);
}