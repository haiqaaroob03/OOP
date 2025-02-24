#include <iostream>
#include <string>
#include "Customer.h"
#include "Admin.h"
#include"UtilityFunctions.h"
#include<fstream>
using namespace std;

int main() {
    int login,choice;
    cout << "\t\t-------------------------------------------------------------\n";
    cout << "\t\t|              Welcome to Virtual Art Gallery               |\n";
    cout << "\t\t-------------------------------------------------------------\n";
    cout << "1. Don't have an Account? Create a new one!\n2. Already have account? Login\n";
    cin >> choice;
    if (choice == 1)
    {
        cout << "Want to join?\nSelect from the below\n";
        cout << "1. Register as Admin\n2. Register as Customer\n3. Register as an Artist\n";
        cin >> login;
        if (login == 1)
        {
            string username, password;
            cout << "Enter the Username : ";
            cin >> username;
            if (isUserExists("Admin.txt", username))
            {
                cout << "Error!! Admin with this username already Exists!!";
            }
            else
            {
                int action;
                cout << "Enter the password : ";
                cin >> password;
                Admin admin(username, password);
                admin.saveToFile("Admin.txt");
                cout << "You are successfully registered to our system!" << endl<<endl<<endl<<endl;
                cout << "You want to :" << endl;
                cout << "1. Add a User\n2. Remove a User\n3.Add an Artwork\n4. Remove an Artwork\n5. View All Users\n6. View All Artworks\n7.View all Orders\n";
                
                cin >> action;
                
                if (action == 3)
                {
                    
                    string username, title, desc;
                    double price;
                    cout << "You want to add an artwork : " << endl;
                    cout << "************Enter the following details of artwork***********\n";
                    cout << "Artwork Title : ";
                    cin >> title;
                    cout << "Artist Name : ";
                    cin >> username;
                    while (!isUserExists("Artist.txt", username))
                    {
                        cout << "Artist don't Exists!\nRe-enter the Name for the artist : ";
                        cin >> username;
                    }
                    cout << "Describe the artwork : ";
                    getline(cin, desc);
                    cout << "Enter price : ";
                    cin >> price;
                    Artwork artwork(username,getPassword("Artist.txt",username),title,desc,price);
                    artwork.saveToFile("Artwork.txt");
                    cout << "Artwork Added successfully!";
                }
            }
            
        }
        else if (login == 2)
        {
            string username, password;
            cout << "Enter the Username : ";
            cin >> username;
            cin.ignore();
            if (isUserExists("Customer.txt", username))
            {
                cout << "Error!! Admin with this username already Exists!!";
            }
            else
            {
                cout << "Enter the password : ";
                cin >> password;
                Customer customer(username, password);
                customer.saveToFile("Customer.txt");
                cout << "You are successfully registered to our system!" << endl;
            }
           
        }
        else if (login == 3)
        {
            string username, password;
            cout << "Enter the Username : ";
            cin >> username;
            cin.ignore();
            if (isUserExists("Artist.txt", username))
            {
                cout << "Error!! Admin with this username already Exists!!";
            }
            else
            {
                cout << "Enter the password : ";
                cin >> password;
                Artist artist(username, password);
                artist.saveToFile("Artist.txt");
                cout << "You are successfully registered to our system!" << endl;
            }
        }
        else
        {
            cout << "Invalid Choice!!" << endl;
        }
    }
    else
    {
        cout << "Want to Login?\nSelect from the below\n";
        cout << "1. Login as Admin\n2. Login as Customer\n3. Login as an Artist\n";
        cin >> login;
        if (login == 1)
        {
            string username, password;
            cout << "Enter the Username : ";
            cin >> username;
            cout << "Enter the password : ";
            cin >> password;
            if (!isUserExists("Admin.txt", username))
            {
                cout << "This user don't Exist!!";
            }
            else if (isValidPassword("Admin.txt",password))
            {
                cout << "You are successfully Logged In" << endl;
                Admin admin(username, password);
                cout << "You want to :" << endl;
                cout << "1. Add a User\n2. Remove a User\n3.Add an Artwork\n4. Remove an Artwork\n5. View All Users\n6. View All Artworks\n7.View all Orders\n";
                int action;
                cin >> action;
                cin.ignore();
                if (action == 3)
                {

                    string username, title, desc;
                    double price;
                    cout << "You want to add an artwork : " << endl;
                    cout << "************Enter the following details of artwork***********\n";
                    cout << "Artwork Title : ";
                    getline(cin, title);
              
                    cin.ignore();
                    cout << "Artist Name : ";
                    cin >> username;
                    cin.ignore();
                    while (!isUserExists("Artist.txt", username))
                    {
                        cout << "Artist don't Exists!\nRe-enter the Name for the artist : ";
                        cin >> username;
                        cin.ignore();
                    }
                    cout << "Describe the artwork : ";
                    getline(cin, desc);
                    cin.ignore();
                    cout << "Enter price : ";
                    cin >> price;
                    Artwork artwork(username, getPassword("Artist.txt", username), title, desc, price);
                    artwork.saveToFile("Artwork.txt");
                    cout << "Artwork Added successfully!";
                }
            }
            else
            {
                cout << "Invalid Password!!" << endl;
            }

        }
        else if (login == 2)
        {
            string username, password;
            cout << "Enter the Username : ";
            cin >> username;
            cout << "Enter the password : ";
            cin >> password;
            if (!isUserExists("Customer.txt", username))
            {
                cout << "This user don't Exist!!";
            }
            else if (isValidPassword("Customer.txt", password))
            {
                Artwork artwork;
                Artist artist;
                Customer customer(username,password);
                cout << "You are successfully Logged In" << endl;
                cout << "*************Explore Our System and Enjoy*************\n";
                cout << "1. View All the Artworks\n2. View the Artists\n3. Place an Order\n4. Cancel an order\n-1 to Exit! ";
                int choice;
                cout << "Enter your choice :";
                cin >> choice;
                while (choice != -1)
                {
                    if (choice == 1)
                    {
                        artwork.view();
                        cout << "1. View All the Artworks\n2. View the Artists\n3. Place an Order\n4. Cancel an order\n-1 to Exit! ";
                        cout << "Enter your choice :";
                        cin >> choice;
                    }
                    else if (choice == 2)
                    {
                        artist.view();
                        cout << "1. View All the Artworks\n2. View the Artists\n3. Place an Order\n4. Cancel an order\n-1 to Exit! ";
                        cout << "Enter your choice :";
                        cin >> choice;
                    }
                    else if (choice == 3)
                    {
                        customer.placeAnOrder();
                        cout << "1. View All the Artworks\n2. View the Artists\n3. Place an Order\n4. Cancel an order\n-1 to Exit! ";
                        cout << "Enter your choice :";
                        cin >> choice;
                    }
                }
             
            }
            else
            {

                cout << "Invalid Password!!" << endl;

            }
            
        }
        else if (login == 2)
        {
            string username, password;
            cout << "Enter the Username : ";
            cin >> username;
            cout << "Enter the password : ";
            cin >> password;
            if (!isUserExists("Artist.txt", username))
            {
                cout << "This user don't Exist!!";
            }
            else if (isValidPassword("Artist.txt", password))
            {
                cout << "You are successfully Logged In" << endl;
            }
            else
            {
                cout << "Invalid Password!!" << endl;
            }

        }
    }
    

    return 0;
}