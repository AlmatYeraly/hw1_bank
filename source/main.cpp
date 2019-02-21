#include "bank.h"
//WARNING!!! TESTING HAS NOT BEEN PERFORMED AND ERROR'S ARE LIKELY TO OCCUR!//

int main() {
/*  std::string command;
  std::cout << "[Welcome to BANK!]\n";
  Bank bank;
  while (command != "exit"){
    std::cout<<"[]Input a command: ";
    std::getline(std::cin,command);
    if (command == "new account"){
      std::cout<<"[]new account called! /s\n";
    }
    else if(command == "display account"){
      std::cout<<"[]display account called! /s\n";
    }
    else if(command == "make withdrawal"){
      std::cout<<"[]withdrawal called! /s\n";
    }
    else if(command == "make deposit"){
      std::cout<<"[]deposit called! /s\n";
    }
    else if(command != "exit"){
      std::cout<<"[]unrecognized command!\n";
    }
  }*/

  Bank bank;
  bank.add_account();
  bank.add_account();
}