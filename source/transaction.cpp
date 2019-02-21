#include "transaction.h"


void Transaction::process_tran(int c_num, bool type, float tran_amount, std::string list_of_fees){
  customer_number = c_num;
  transaction_type = type;
  amount = tran_amount;
  fees = list_of_fees;
}