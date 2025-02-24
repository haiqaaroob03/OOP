#ifndef ARTIST_H
#define ARTIST_H
#include"User.h"
class Artist:public User
{
	
public:
	Artist(){}
	Artist(string username, string password);
	void changePassword(string newPassword) override;
	void display() const override;
	void saveToFile(string filename) const override;
	
	void view();
};
#endif;