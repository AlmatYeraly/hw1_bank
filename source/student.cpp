#include "student.h"

float Student::get_savings(){
  return SAVINGS_INTEREST;
}

float Student::get_check(){
  return CHECK_INTEREST;
}

float Student::get_charge(){
  return CHECK_CHARGE;
}

float Student::get_penalty(){
  return OVERDRAFT_PENALTY;
}