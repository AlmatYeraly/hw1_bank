#include "bank.h"


void bank(){
  std::string command;
  std::cout << "[Welcome to BANK!]\n";
  Bank bank;
  std::locale loc;
  while (command != "exit"){
    std::cout<<"[]Input a command: ";
    std::getline(std::cin,command);
    for (int i = 0; i < command.length(); i++){
      command[i] = std::tolower(command[i],loc);
    }
    if (command == "new account"){
      bank.add_account();
    }
    else if(command == "display account"){
      bank.get_account()->to_string();
    }
    else if(command == "make withdrawal"){
      bank.make_withdrawal();
    }
    else if(command == "make deposit"){
      bank.make_deposit();
    }
    else if(command != "exit"){
      std::cout<<"[]unrecognized command!\n";
    }
  }
}

int main() {
  bank();
}