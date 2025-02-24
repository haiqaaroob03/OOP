#ifndef ORDER_H
#define ORDER_H
#include "Artwork.h"
#include"Customer.h"
class Order : public Customer
{
private:
    static int oId; 
    int orderId; 
    Artwork* artworks; 
    double totalPrice; 
    string paymentMethod; 
    int numOfProducts; 

public:
    Order(){}
    Order(string username, string password, string paymentMethod, int num);
    void display();
    void saveToFile(string filename) const;
    void setArtwork(string title, int index);
    ~Order();
};

#endif


