#include "customer.h"

void Customer::set_name(std::string new_name){
  name = new_name;
}
void Customer::set_address(std::string new_address){
  address = new_address;
}
void Customer::set_age(int new_age){
  if (new_age >= 0){
    age = new_age;
  }
}

// According to E.164, the maximum allowed plan phone number length is 15 digits
void Customer::set_telephone(long const int new_phone){
  if (new_phone <= 999999999999999){
    telephone_number = new_phone;
  }
}

std::string Customer::get_name(){
  return name;
}
std::string Customer::get_address(){
  return address;
}
int Customer::get_age(){
  return age;
}
long int Customer::get_telephone(){
  return telephone_number;
}

bool Customer::operator==(const int a_num){
  return (customer_number == a_num);
}

// Need to setup some constructors and some tests to ensure the code cannot be abused//