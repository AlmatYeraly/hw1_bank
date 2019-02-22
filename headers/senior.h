#ifndef _SENIOR_H_
#define _SENIOR_H_
#include "customer.h"

class Senior : public Customer {
private:
  const float SAVINGS_INTEREST = 0.015;
  const float CHECK_INTEREST = 0.01;
  const float CHECK_CHARGE = 0.02;
  const float OVERDRAFT_PENALTY = 20;
public:
  Senior(std::string set_name, std::string set_address, int set_age, long int set_telephone, int set_id) : Customer(set_name, set_address, set_age, set_telephone, set_id) {}
  float get_savings();
  float get_check();
  float get_charge();
  float get_penalty();
};

#endif