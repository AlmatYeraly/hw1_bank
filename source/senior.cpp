#include "senior.h"

float Senior::get_savings(){
  return SAVINGS_INTEREST;
}

float Senior::get_check(){
  return CHECK_INTEREST;
}

float Senior::get_charge(){
  return CHECK_CHARGE;
}

float Senior::get_penalty(){
  return OVERDRAFT_PENALTY;
}