#include "customer.h"

void Customer::set_name(string new_name)
{
    name = new_name;
}

void Customer::set_address(string new_address)
{
    address = new_address;
}

void Customer::set_age(int new_age)
{
    age = new_age;
}

void Customer::set_telephone(int new_telephone)
{
    telephone_number = new_telephone;
}

string Customer::get_name()
{
    return name;
}

string Customer::get_address()
{
    return address;
}

int Customer::get_age()
{
    return age;
}

int Customer::get_telephone()
{
    return telephone_number;
}

int Customer::get_customer_number()
{
    return customer_number;
}