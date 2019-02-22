#include "bank.h"


void bank(){
  int command = -1;
  std::cout << "[Welcome to BANK!]\n";
  std::cout << "Input a corresponding number for the next step.\n";
  Bank bank;
  while (command != 0){
    std::cout << "[1] Create new account. \n";
    std::cout << "[2] Display existing account. \n";
    std::cout << "[3] Deposit. \n";
    std::cout << "[4] Withdraw. \n";
    std::cout << "[0] Exit. \n";
    // Make sure that the user command is an integer value (not some other data type) //
    bool valid_int = false;
    while (!valid_int){
      std::cout<<"[]Input a command: ";
      std::cin >> command;
      std::cin.ignore();
      if (std::cin.fail()){
        std::cin.clear();
        valid_int = false;
      }
      else {
        valid_int = true;
      }
    }

    if(command == 1)
    {
      std::cout << "\n";
      bank.add_account();
      std::cout << "\n";
    }
    else if(command == 2)
    {
      std::cout << "\n";
      Account* account = bank.get_account();
      // If account user is getting is NULL (not found) then it continues back to menu prompt //
      if (account == NULL){ std::cout << "\n";}
      else{
        std::cout <<  account->to_string();
    }
    }
    else if(command == 3)
    {
      std::cout << "\n";
      bank.make_deposit();
      std::cout << "\n";
    }
    else if(command == 4)
    {
      std::cout << "\n";
      bank.make_withdrawal();
      std::cout << "\n";
    }
    else if(command != 0)
    {
      std::cout << "\n";
      std::cout << "Unrecognized command. Please try again. \n";
    }
  }
}

int main() {
  bank();
}