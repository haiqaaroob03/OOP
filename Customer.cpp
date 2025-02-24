#include "Customer.h"
#include"UtilityFunctions.h"
#include"Order.h"
#include<iostream>
#include<fstream>
using namespace std;

Customer::Customer(){}

Customer::Customer(string username, string password):User(username,password)
{
}

void Customer::display() const {
    cout << "Customer Name: " << username << endl;
}

void Customer::changePassword(string newPassword) {
    password = newPassword;
}

void Customer::saveToFile(string filename) const {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << username << "," << password << endl;
        file.close();
    }
}
void Customer::placeAnOrder()
{
    int num;
    string name, password,payment;
    cout << "Want to Place an Order ? " << endl;
    cout << "Enter your username : ";
    cin.ignore();
    getline(cin,name);
    cin.ignore();
    while (!isUserExists("Customer.txt", name))
    {
        cout << "Invalid username!!!" << endl;
        cout << "Re-enter the username : ";
        getline(cin, name);
        cin.ignore();
    }
    cout << "Enter your password : ";
    cin >> password;
    while (!isValidPassword("Customer.txt", password))
    {
        cout << "Invalid password!!!" << endl;
        cout << "Re-enter the password : ";
        cin >> password;
    }
    cout << "Enter the details\n";
    cout << "Number of artworks you want to Buy : ";
    cin >> num;
    cout << "Enter the payment method : ";
    getline(cin, payment);
    cin.ignore();
    Order order(name, password, payment, num);
    cout << "Enter the titles of the Artworks\n" << endl;
    string title;
    cin.ignore();
    for (int i = 0; i < num; i++)
    {
        cout << " Title of Artwork " << i + 1 << " : " << endl;
        getline(cin, title);
        cin.ignore();
        order.setArtwork(title, i);
    }
    
    order.display();
    int cnfrm;
    cout << "Press 1 to confirm your order\n";
    cin >> cnfrm;
    if (cnfrm == 1)
    {
        order.saveToFile("Order.txt");
    }
}


