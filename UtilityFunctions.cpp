#include "UtilityFunctions.h"
#include <fstream>
bool isUserExists(string filename, string username) {
    ifstream fin(filename);
    string line;
    bool found = false;

    if (fin.is_open()) {
        while (getline(fin, line)) {
            if (line.substr(0, line.find(',')) == username) {
                found = true;
                break;
            }
        }
        fin.close();
    }

    return found;
}
bool isValidPassword(string filename, string password)
{
    ifstream fin(filename);
    string line;
    bool found = false;

    if (fin.is_open()) {
        while (getline(fin, line)) {
            int pos = line.find(',');
            if (line.substr(pos + 1, line.find('\n')) == password) {
                found = true;
                break;
            }
        }
        fin.close();
    }
    return found;
}
string getPassword(string filename, string username)
{
    ifstream fin(filename);
    string line;
    string password;
    if (fin.is_open()) {
        while (getline(fin, line)) {
            if (line.substr(0, line.find(',')) == username) {
                password = line.substr(line.find(',') + 1, '\n');

            }
        }
        fin.close();
    }

    return password;
}