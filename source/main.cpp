#include <iostream>

#include "customer.h"
#include "student.h"
#include "senior.h"
#include "adult.h"

int main()
{
    string name;
    string address;
    int age;
    int tele;
    
    cout << "create new customer" << endl;

    cout << "name: ";
    cin >> name;

    cout << "address: ";
    cin >> address;
   
    cout << "age: ";
    cin >> age;

    cout << "telephone number: ";
    cin >> tele;
    
    Customer * customer = new Customer(name, address, age, tele);

    cout << "new customer info: " << endl;
    cout << "name: " << customer->get_name() << endl;
    cout << "address: " << customer->get_address() <<endl;
    cout << "age: " << customer->get_age() << endl;
    cout << "telephone: " << customer->get_telephone() <<endl;

    return 0;
}