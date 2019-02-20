#ifndef _STUDENT_H_
#define _STUDENT_H_
#include "customer.h"

class Student : public Customer {
private:
  const float SAVINGS_INTEREST = 0.04;
  const float CHECK_INTEREST = 0.04;
  const float CHECK_CHARGE = 0.15;
  const float OVERDRAFT_PENALTY = 0.03;
public:
  float get_savings();
  float get_check();
  float get_charge();
  float get_penalty();
};

#endif