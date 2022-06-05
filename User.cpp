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

    for(int i = 0 ; i < 5 ; i++ ){
        characters[i] = Character();
    }
    cout << "User created!" << endl
         << "User name: " << userName << endl;
    cout << "Password: " << password << endl;

    
}

User::User(char Name[], char pass[], Character the_character)
{
   
    strcpy(userName, Name);
    strcpy(password, pass);

    characters[0] = the_character;
    for (int i = 1 ; i < 5 ; i++ ){
        characters[i] = Character();
    }

    cout << "User created!" << endl
         << "User name: " << userName << endl;


    
}

User::User(char Name[], char pass[], Character the_character[]){

    strcpy(userName, Name);
    strcpy(password, pass);
    for(int i = 0 ; i < 5 ; i++ ){
        characters[i] = the_character[i];
    }
    cout << "User created!" << endl
         << "User name: " << userName << endl;
}

User::~User()
{

}