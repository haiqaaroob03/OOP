#ifndef ADMIN_H
#define ADMIN_H
#include "User.h"
#include "Artwork.h"
#include "Customer.h"
#include "Artist.h"
#include "Order.h"
class Admin: public User
{
public:
	Admin(string username, string password);
    void display() const override;
    void changePassword(string newPassword) override;
    void saveToFile(string filename) const override;
    void addUser(User* users[], int& count, User* user);
    void removeUser(User* users[], int& count,string username);
    void addArtwork(const Artwork& artwork);
    void removeArtwork(Artwork artworks[], int& count,string title);
    void viewAllUsers(User* users[], int count) const;
    void viewAllArtworks(Artwork artworks[], int count) const;
    void viewAllOrders(Order orders[], int count) const;
};

#endif