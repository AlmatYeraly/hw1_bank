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
  float get_savings();
  float get_check();
  float get_charge();
  float get_penalty();
};

#endif