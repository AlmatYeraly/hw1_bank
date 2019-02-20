#include "adult.h"

float Adult::get_savings(){
  return SAVINGS_INTEREST;
}

float Adult::get_check(){
  return CHECK_INTEREST;
}

float Adult::get_charge(){
  return CHECK_CHARGE;
}

float Adult::get_penalty(){
  return OVERDRAFT_PENALTY;
}