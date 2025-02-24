#include "Order.h"
#include"Artwork.h"
#include<fstream>
#include<iostream>
using namespace std;

int Order::oId = 10 + rand() % 1000;

Order::Order(string username, string password, string payment, int num):Customer(username,password)
{
	this->orderId = oId;
	this->totalPrice = 0;
	this->numOfProducts = num;
	this->paymentMethod = payment;
	artworks = new Artwork[numOfProducts];
	oId++;
}

void Order::display()
{
	double sum = 0.0;
	cout << "-------------------Order Receipt------------------" << endl;
	cout << "       Order Id : " << orderId << endl;
	cout << "   Customer Name : " << getUsername()<<endl;
	
	cout << "   Items                          Price " << endl;
	for (int i = 0; i < numOfProducts; i++)
	{
		cout << artworks[i].getTitle() << "                        " << artworks[i].getPrice() << endl;
		sum += artworks[i].getPrice();
	}
	totalPrice = sum;
	cout << "--------------------------------------------------\n";
	cout << "  Total Price                 " << totalPrice << endl;

	cout << "  Payment method :            " <<  paymentMethod << endl;

}
void Order::saveToFile(string filename) const
{
	ofstream file(filename, ios::app);
	if (file.is_open()) {
		file << orderId << "," << getUsername() << "," << numOfProducts << "," << totalPrice << "," << paymentMethod << endl;
		for (int i = 0; i < numOfProducts; i++)
		{
			file << artworks[i].getTitle() << "," << artworks[i].getPrice() << endl;
		}
		file.close();
	}
}

void Order::setArtwork(string t, int index)
{
	if (! artworks[index].isArtworkExists(t))
	{
		artworks[index].setTitle(t);
	}
	else
	{
		cout << "Artwork don't Exists!\n";
	}
}
Order::~Order()
{
	if (artworks)
	{
		delete[] artworks;
		artworks = nullptr;
	}
}
