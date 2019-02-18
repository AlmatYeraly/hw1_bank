#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include <string>

using namespace std;

class Customer{
protected:
    string name;
    string address;
    int age;
    int telephone_number;
    int customer_number;
public:
    Customer(string new_name, string new_address, int new_age, int new_telephone)
    {
        name = new_name;
        address = new_address;
        age = new_age;
        telephone_number = new_telephone;
        customer_number = 1;
    }

    void set_name(string new_name);
    void set_address(string new_address);
    void set_age(int new_age);
    void set_telephone(int new_telephone);

    string get_name();
    string get_address();
    int get_age();
    int get_telephone();
    int get_customer_number();
};

#endif