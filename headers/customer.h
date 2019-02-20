#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include <string>

class Customer {
protected:
  std::string name;
  std::string address;
  int age;
  long int telephone_number;
  int customer_number;
public:
  //Set methods
  void set_name(std::string new_name);
  void set_address(std::string new_address);
  void set_age(int new_age);
  void set_telephone(long const int new_phone);
  //Get methods
  std::string get_name();
  std::string get_address();
  int get_age();
  long int get_telephone();

  bool operator==(const int a_num);
};

#endif