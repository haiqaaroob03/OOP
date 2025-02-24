#ifndef CUSTOMER_H
#define CUSTOMER_H
#include"User.h"
#include "UtilityFunctions.h"
class Order;

class Customer:public User
{	
public:
    Customer();
	Customer(string username, string password);
    void display() const override final;
    void changePassword(string newPassword) override final;
    void saveToFile(string filename) const override ;
    void placeAnOrder();
};



#endif