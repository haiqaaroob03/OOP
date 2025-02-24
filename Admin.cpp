#include "Admin.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
Admin::Admin(string username,string password) : User(username, password) {}

void Admin::display() const {
    cout << "Admin Username: " << username << endl;
}


void Admin::changePassword(string newPassword) {
    password = newPassword;
}

void Admin::saveToFile(string filename) const {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << username << "," << password << endl;
        file.close();
    }
}



void Admin::addUser(User* users[], int& count, User* user) {
    if (count < 100) {
        users[count] = user;
        count++;
    }
    else
    {
        cout << "More users Cannot be added!!" << endl;
    }
}

void Admin::removeUser(User* users[], int& count,string username) {
    for (int i = 0; i < count; i++) {
        if (users[i]->getUsername() == username) {
            for (int j = i; j < count - 1; j++) {
                users[j] = users[j + 1];
            }
            count--;
            break;
        }
    }
}

void Admin::addArtwork(const Artwork& artwork) {
    artwork.saveToFile("Artwork");
}

void Admin::removeArtwork(Artwork artworks[], int& count,string title) {
    for (int i = 0; i < count; i++) {
        if (artworks[i].getTitle() == title) {
            for (int j = i; j < count - 1; j++) {
                artworks[j] = artworks[j + 1];
            }
            count--;
            break;
        }
    }
}

void Admin::viewAllUsers(User* users[], int count) const {
    for (int i = 0; i < count; i++) {
        users[i]->display();
    }
}

void Admin::viewAllArtworks(Artwork artworks[], int count) const {
    for (int i = 0; i < count; i++) {
        artworks[i].display();
    }
}

void Admin::viewAllOrders(Order orders[], int count) const {
    for (int i = 0; i < count; i++) {
        orders[i].display();
    }
}