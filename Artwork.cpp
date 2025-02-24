#include "Artwork.h"
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;


Artwork::Artwork(string username, string password, string title, string desc, double price) :artist(username, password)
{
    this->title = title;
    this->price = price;
    this->description = desc;
}

void Artwork::display() const {
    cout << "Title: " << title << endl;
    cout << "Description: " << description << endl;
    cout << "Artist: " << artist.getUsername()<<endl;
    cout << "Price: " << price << endl;
}

void Artwork::saveToFile(string filename) const {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << title << "," << description << "," << artist.getUsername()<< "," << price << endl;
        file.close();
    }
}

void Artwork::view()
{
    ifstream file("Artwork.txt");
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            
            stringstream ss(line);
            string temp;

            // Read the title
            getline(ss, temp, ',');
            title = temp;

            // Read the description
            getline(ss, temp, ',');
            description = temp;

            // Read the artist
            getline(ss, temp, ',');
            artist.setUsername(temp);

            // Read the price
            getline(ss, temp, ',');
            price = stod(temp);
            display();
        }
        file.close();
    }
    else {
        cout << "Unable to open file." << endl;
    }
}
bool Artwork::isArtworkExists(string title)
{
    ifstream fin("Artwork.txt");
    string line;
    bool found = false;

    if (fin.is_open()) {
        while (getline(fin, line)) {

            if (line.substr(0, line.find(',')) == title) {
                found = true;
                break;
            }
        }
        fin.close();
    }

    return found;
}

void Artwork::setTitle(string title)
{
    this->title = title;
}

double Artwork::getPrice()const
{
    double price;
    ifstream file("Artwork.txt");
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {

            stringstream ss(line);
            string temp;

            // Read the title
            getline(ss, temp, ',');
           

            // Read the description
            getline(ss, temp, ',');
            

            // Read the artist
            getline(ss, temp, ',');
            

            // Read the price
            getline(ss, temp, ',');
            price = stod(temp);
        }
        file.close();
    }
    return price;
}