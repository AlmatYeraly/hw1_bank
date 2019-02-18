#ifndef _STUDENT_H_
#define _STUDENT_H_

#include "customer.h"

class Student: public Customer
{
private:
    const float savings_interest = 0.1;
    const float check_interest = 0.1;
    const float check_charge = 0.1;
    const float overdraft_penalty = 0.05;
public:
    Student();
    float get_sav_interest();
    float get_check_interest();
    float get_check_charge();
    float get_over_penalty();
};

#endif