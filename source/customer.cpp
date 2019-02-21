#include "customer.h"

Customer::Customer(std::string set_name, std::string set_address, int set_age, long int set_telephone, int set_id){
  name = set_name;
  address=set_address;
  age = set_age;
  telephone_number = set_telephone;
  customer_number = set_id;
}

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
int Customer::get_customer_id(){
  return customer_number;
}