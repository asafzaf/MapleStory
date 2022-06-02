#include "User.hpp"
#include "Character.hpp"

// using namespace Users;

// Create New User //
User::User(char *Name, char *pass)
{
    try
    {
        userName = new char[strlen(Name) + 1];
        if (userName == NULL)
        {
            throw 1;
        }
        password = new char[strlen(pass) + 1];
        if (password == NULL)
        {
            throw 1;
        }

        strcpy(userName, Name);
        strcpy(password, pass);

        cout << "User created!" << endl << "User name: " << userName << endl;
        cout << "Password: " << password << endl;
    }
    catch (int e)
    {
        cout << "error with user and password - NULL argument" << endl;
    }
}

User::User(char* Name, char* pass, Character the_character) {
      
userName = new char[strlen(Name)+1];
strcpy(userName, Name);

password = new char[strlen(pass)+1];
strcpy(password, pass);

characters[0] = the_character;


}

User::~User(){
    delete userName;
    delete password;
}