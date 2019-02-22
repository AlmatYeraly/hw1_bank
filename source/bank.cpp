#include "bank.h"
#include <time.h>
#include <stdlib.h>
#include <typeinfo>

// Requests user to input account number and customer number to find an account //
// If account that matches the two numbers is found, outputs the pointer to the account //
// If no account was found that matches the two numbers, outputs a NULL pointer //
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
      if (accounts[i]->get_account_number() == InputAccountNum && accounts[i]->get_customer()->get_customer_id() == InputCustomerNum){
        found = true;
        index = i;
        break;
      }
    }
    if (!found){
      std::cout << "Account not found.\n";
      return NULL;
    }
    else if (found){
      std::cout << "\nAccount was found\n";
      return accounts[index];
    }
  }
}




// Add a new account to the Bank's account array
// If user is creating account with a previously existing customer, finds the customer by inputting customer's number
void Bank::add_account(){
  std::string a_type;
  char response;
  bool loop = true;
  std::cout<<"BEGINING ACCOUNT CREATION\n";
  while(loop){
    std::cout<<"What type of account? (Savings/Checking)\n";
    std::cin>>a_type;
    std::locale loc;
    for (int i = 0; i < a_type.length(); i++){
      a_type[i] = std::tolower(a_type[i],loc);
    }
    if (a_type == "savings" || a_type == "checking"){break;}
    else continue;
  }
  // Make unique account_id by generating random number within range and checking all other account's numbers
  srand(time(NULL));
  bool unique = false;
  int new_a_id;
  while (!unique){
    new_a_id = rand() % 9999 + 1000;
    unique = true;
    for (int i = 0; i < accounts.size(); i++){
      if (new_a_id == accounts[i]->get_account_number()){
        unique = false;
      }
      else continue;
    }
  }

  while (loop){
    std::cout<<"Will this account have an already existing customer? (y/n)\n";
    std::cin>>response;
    std::locale loc;
    response = std::tolower(response, loc);
    if (response == 'n'){
      std::string input_name;
      std::cout << "Input name: ";
      std::cin.ignore();
      std::getline (std::cin, input_name);

      std::string input_address;
      std::cout << "Input address: ";
      std::getline (std::cin, input_address);

      int input_age = -1;
      bool valid_int = false;
      while ((input_age < 0 || input_age > 125) || !valid_int){
        std::cout << "Input age: ";        
        std::cin >> input_age;
        if (std::cin.fail()){
          std::cin.clear();
          valid_int = false;
        }
        else {
          valid_int = true;
        }
      }

      long int input_phone = 0;
      valid_int = false;
      while ((input_phone > 999999999999999 || input_phone < 100) || !valid_int){
        std::cout << "Input telephone number: ";
        std::cin.ignore();
        std::cin >> input_phone;
        if (std::cin.fail()){
          std::cin.clear();
          valid_int = false;
        }
        else {
          valid_int = true;
        }
      }

      // Make unique customer_id by generating random number within range and checking all other account's customer
      unique = false;
      int new_c_id;
      while (!unique){
        new_c_id = rand() % 9999 + 1000;
        unique = true;
        for (int i = 0; i < accounts.size(); i++){
          if (new_c_id == accounts[i]->get_customer()->get_customer_id()){
            unique = false;
          }
          else continue;
        }
      }
      // With the information we need given, creates savings and checkings with a specified customer based on age given //
      if (input_age >= 16 && input_age < 23){
        if (a_type == "savings"){
          accounts.push_back(new Savings(new  Student(input_name, input_address,input_age, input_phone, new_c_id),new_a_id, 1));
          std::cout<<"\nStudent Savings Account\n";
        }
        else if (a_type == "checking"){
          accounts.push_back(new Checking(new Student(input_name, input_address,input_age, input_phone, new_c_id),new_a_id, 0));
          std::cout<<"\nStudent Checking Account\n";
        }
        loop = false;
      }
      else if (input_age >= 23 && input_age < 65){
        if (a_type == "savings"){
          accounts.push_back(new Savings(new  Adult(input_name, input_address,input_age, input_phone, new_c_id),new_a_id, 1));
          std::cout<<"\nAdult Savings Account\n";
        }
        else if (a_type == "checking"){
          accounts.push_back(new Checking(new Adult(input_name, input_address,input_age, input_phone, new_c_id),new_a_id, 0));
          std::cout<<"\nAdult Checking Account\n";
        }
        loop = false;
      }
      else if (input_age >= 65){
        if (a_type == "savings"){
          accounts.push_back(new Savings(new  Senior(input_name, input_address,input_age, input_phone, new_c_id),new_a_id, 1));
          std::cout<<"\nSenior Savings Account\n";
        }
        else if (a_type == "checking"){
          accounts.push_back(new Checking(new Senior(input_name, input_address,input_age, input_phone, new_c_id),new_a_id, 0));
          std::cout<<"\nSenior Checking Account\n";
        }
        loop = false;
      }
      std::cout<<"Account id: " << 
      accounts[accounts.size()-1]->get_account_number() <<std::endl;
      std::cout<<"Customer id: " << 
      accounts[accounts.size()-1]->get_customer()->get_customer_id() <<std::endl;
    }

    // If the user is creating an account with an already existing customer, prompts for the customer's number and searches within the other accounts for a match and uses the pointer to access the customer
    // When the account is made, it displays the account and customer id
    else if (response == 'y'){
      bool found= false;
      int find_id;
      std::cout<<"Input customer id of existing customer\n";
      std::cin>>find_id;
      for (int i = 0; i < accounts.size(); i++){
        if (accounts[i]->get_customer()->get_customer_id() == find_id){
          std::cout<<"Customer found\n";
          if (a_type == "savings"){
            found = true;
            accounts.push_back(new  Savings(accounts[i]->get_customer(),new_a_id, 1));
            std::cout<<"Account id: " << 
            accounts[accounts.size()-1]->get_account_number() <<std::endl;
            std::cout<<"Customer id: " << 
            accounts[accounts.size()-1]->get_customer()->get_customer_id() <<std::endl;
            loop = false;
            break;
          }
          else if (a_type == "checking"){
            found = true;
            accounts.push_back(new Checking(accounts[i]->get_customer(),new_a_id, 0));
            std::cout<<"Account id: " << 
            accounts[accounts.size()-1]->get_account_number() <<std::endl;
            std::cout<<"Customer id: " << 
            accounts[accounts.size()-1]->get_customer()->get_customer_id() <<std::endl;
            loop = false;
            break;
          }
        }
      }
      if (!found){
        std::cout<<"Customer not found\n";
      }
    }
  }
}



// User inputs which account and amount to deposit
// account's deposit is called with amount as argument
void Bank::make_deposit(){
  Account* account = get_account();
  if (account == NULL){
    std::cout<< "Exiting make deposit action\n";
    return;
  }
  while (true){
    float amount;
    std::cout <<"what amount is the deposit?\n";
    std::cin  >> amount;
    if (amount < 0.0){
      std::cout << "Invalid amount (cannot be negative)\n";
      continue;
    }
    else if (amount > 0.0){
      std::cout << "Initial balance: " << account->get_balance() <<std::endl;
      account->deposit(amount);
      std::cout << "Final balance: " << account->get_balance() <<std::endl;
      break;
    }
    else if (amount == 0.0){
      std::cout <<"An amount of 0 is not an amount worth making a transaction\n";
      break;
    }
    else {
      std::cout <<"Invalid amount (must be a value)\n";
      continue;
    }
  }
}


// User inputs which account and amount to withdraw
// account's withdraw is called with amount as argument
void Bank::make_withdrawal(){
  Account* account = get_account();
  if (account == NULL){
    std::cout<< "Exiting make withdrawal action\n";
    return;
  }
  while (true){
    float amount;
    std::cout <<"what amount is the withdrawal?\n";
    std::cin  >> amount;
    if (amount < 0.0){
      std::cout << "Invalid amount (cannot be negative)\n";
      continue;
    }
    else if (amount > 0.0){
      std::cout << "Initial balance: " << account->get_balance() <<std::endl;
      account->withdraw(amount);
      std::cout << "Final balance: " << account->get_balance() <<std::endl;
      break;
    }
    else if (amount == 0.0){
      std::cout <<"An amount of 0 is not an amount worth making a transaction\n";
      continue;
    }
    else {
      std::cout <<"Invalid amount (must be a value)\n";
      continue;
    }
  }
}