#ifndef _SENIOR_H_
#define _SENIOR_H_

#include "customer.h"

class Senior: public Customer
{
private:
    const float savings_interest = 0.15;
    const float check_interest = 0.15;
    const float check_charge = 0.15;
    const float overdraft_penalty = 0.03;
public:
    Senior();
    float get_sav_interest();
    float get_check_interest();
    float get_check_charge();
    float get_over_penalty();
};

#endif