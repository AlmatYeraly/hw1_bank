#ifndef _ADULT_H_
#define _ADULT_H_

#include "customer.h"

class Adult: public Customer
{
private:
    const float savings_interest = 0.07;
    const float check_interest = 0.07;
    const float check_charge = 0.07;
    const float overdraft_penalty = 0.05;
public:
    Adult();
    float get_sav_interest();
    float get_check_interest();
    float get_check_charge();
    float get_over_penalty();
};

#endif