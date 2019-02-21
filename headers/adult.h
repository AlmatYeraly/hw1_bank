#ifndef _ADULT_H_
#define _ADULT_H_
#include "customer.h"

class Adult : public Customer {
private:
  const float SAVINGS_INTEREST = 0.05;
  const float CHECK_INTEREST = 0.05;
  const float CHECK_CHARGE = 0.05;
  const float OVERDRAFT_PENALTY = 0.05;
public:
  Adult(std::string set_name, std::string set_address, int set_age, long int set_telephone, int set_id) : Customer(set_name, set_address, set_age, set_telephone, set_id) {}
  float get_savings();
  float get_check();
  float get_charge();
  float get_penalty();
};

#endif