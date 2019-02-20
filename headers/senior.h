#ifndef _SENIOR_H_
#define _SENIOR_H_
#include "customer.h"

class Senior : public Customer {
private:
  const float SAVINGS_INTEREST = 0.07;
  const float CHECK_INTEREST = 0.07;
  const float CHECK_CHARGE = 0.07;
  const float OVERDRAFT_PENALTY = 0.08;
public:
  float get_savings();
  float get_check();
  float get_charge();
  float get_penalty();
};

#endif