#include "transaction.h"


void Transaction::process_tran(int c_num, bool type, float tran_amount, std::string list_of_fees){
  customer_number = c_num;
  transaction_type = type;
  amount = tran_amount;
  fees = list_of_fees;
}

std::string Transaction::get_type(){
  if(transaction_type == 0)
  {
    return "Deposit";
  }
  else
  {
    return "Withdrawal";
  }
}

int Transaction::get_amount(){
  return amount;
}

std::string Transaction::get_fees(){
  return fees;
}