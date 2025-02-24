#include "Artist.h"
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
Artist::Artist(string username, string password):User(username,password)
{
}



void Artist::display() const {
    cout << "Artist Name: " << getUsername() << endl;
  
}

void Artist::saveToFile(string filename) const {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << username << "," << password << endl;
        file.close();
    }
}

void Artist::changePassword(string newPassword) {
    password = newPassword;
}

void Artist::view()
{
    ifstream file("Artist.txt");
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {

            stringstream ss(line);
            string temp;

            // Read the Name
            getline(ss, temp, ',');
            username = temp;

            display();
        }
        file.close();
    }
    else {
        cout << "Unable to open file." << endl;
    }
}