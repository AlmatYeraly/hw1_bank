#include "bank.h"

//Must implement a flush/clear of cin buffer for when user enters information so that there is no overflow //
//Must implement the usage of exceptions for control //


// TBI
// Requests user to input account number and customer number to find an account //
// If account that matches the two numbers is found, outputs the pointer to the account //
// If not found, must implement an exception
Account* Bank::get_account(){
  char response;
  while(true){
    
    int InputAccountNum;
    int InputCustomerNum;
    std::cout << "Enter account number: ";
    std::cin >> InputAccountNum;
    std::cout << "Enter customer number: ";
    std::cin >> InputCustomerNum;
    bool found = false;
    int index;
    for (int i = 0; i < accounts.size(); i++){
      if (*accounts[i] == InputAccountNum && *accounts[i]->get_customer() == InputCustomerNum){
        found = true;
        index = i;
        break;
      }
    }
    if (!found){
      std::cout << "Account not found.\n";
      while (response != 'y' || response != 'n'){
        std::cout << "Do you wish to resubmit? (y/n)\n";
        std::cin >> response;
      }
      if (response == 'y'){
        continue;
      }
    }
    else if (found){
      std::cout << "Account was found\n";
      return accounts[index];
    }
  }
}

// TBI
// User is prompted to input information, calls get_account to ensure no duplication
void Bank::add_account(){
  char response;
  std::cout<<"BEGINING ACCOUNT CREATION\n";
  while (true){
    std::cout<<"Will this account have an already existing customer? (y/n)\n";
    std::cin>>response;
    
    if (response == 'n'){
      std::string input_name;
      std::cout << "Input name: ";
      std::getline (std::cin, input_name);
      
      int input_age = -1;
      while (input_age < 0){
        std::cout << "Input age: ";
        std::cin >> input_age;
      }

      long int input_phone =1000000000000000;
      while (input_phone <= 999999999999999){
        std::cout <<"input telephone number: ";
        std::cin >> input_phone;
      }
    }
    else if (response == 'y'){
      
    }
  }
}

// TBI
void Bank::make_deposit(){

}
// TBI
void Bank::make_withdrawal(){

}