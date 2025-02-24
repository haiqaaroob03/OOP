#ifndef USER_H
#define USER_H
#include<string>
using namespace std;
class User
{
protected:
	string username;
	string password;
public:
    User(){}
	User(string uname, string pswrd):username(uname),password(pswrd){}
    virtual ~User() = default;

    virtual void display() const = 0;
    
    virtual void changePassword(string newPassword) = 0;
    virtual void saveToFile(string filename) const = 0;
    string getPassword()const
    {
        return password;
    }
    string getUsername() const {
        return username;
    }
    void setUsername(string n)
    {
        username = n;
    }
};

#endif