#ifndef ARTWORK_H
#define ARTWORK_H
#include<string>
#include"Artist.h"
using namespace std;
class Artwork
{
	string title;
	string description;
	Artist artist;
	double price;
public:
	Artwork() {}
	Artwork(string username, string password, string title, string desc, double price);
	void display() const;
	void saveToFile(string filename) const;
	void view();
	double getPrice()const;
	bool isArtworkExists(string title);
	void setTitle(string title);
	string getTitle() const {
		return title;
	}
};

#endif