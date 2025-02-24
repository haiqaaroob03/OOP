#ifndef UTILITYFUNCTIONS_H
#define UTILITYFUNCTIONS_H
#include<string>
using namespace std;
bool isUserExists(string filename, string username);
bool isValidPassword(string filename, string password);
string getPassword(string filename, string username);

#endif;