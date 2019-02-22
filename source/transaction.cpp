#include "transaction.h"

// Sets all the transactions values
void Transaction::process_tran(int c_num, bool type, float tran_amount, std::string list_of_fees){
  customer_number = c_num;
  transaction_type = type;
  amount = tran_amount;
  fees = list_of_fees;
}

// 0 is for deposit, and other values (which should only be 1 since it is a bool) are withdrawal
std::string Transaction::get_type(){
  if(transaction_type == 0)
  {
    return "deposit";
  }
  else
  {
    return "withdrawal";
  }
}

int Transaction::get_amount(){
  return amount;
}

std::string Transaction::get_fees(){
  return fees;
}