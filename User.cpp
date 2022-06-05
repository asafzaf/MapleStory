#include "User.hpp"
#include "Character.hpp"
#include <iostream>
#include <istream>

using namespace std;
// using namespace Users;

// Create New User //

User::User(char *Name, char *pass)
{
    strcpy(userName, Name);
    strcpy(password, pass);

    cout << "User created!" << endl
         << "User name: " << userName << endl;
    cout << "Password: " << password << endl;
}

User::User(char Name[], char pass[], Character the_character)
{
   
    strcpy(userName, Name);
    strcpy(password, pass);

    
}

User::~User()
{

}