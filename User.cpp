#include "User.hpp"
#include "Character.hpp"
#include <iostream>
#include <istream>

using namespace std;
// using namespace Users;

// Create New User //

User::User(char *Name, char *pass)
{
    char *initName = "N/A";
    strcpy(userName, Name);
    strcpy(password, pass);

    for (int i = 0; i < 5; i++)
    {
        characters[i] = Character(initName, Default);
    }
    cout << "User created!" << endl
         << "User name: " << userName << endl;
    cout << "Password: " << password << endl;
    delete[] initName;
}

User::User(char Name[], char pass[], Character the_character)
{
    char *initName = "N/A";
    strcpy(userName, Name);
    strcpy(password, pass);

    characters[0] = the_character;
    for (int i = 1; i < 5; i++)
    {
        characters[i] = Character(initName, Default);
    }

    cout << "User created!" << endl
         << "User name: " << userName << endl;
}

User::User(char Name[], char pass[], Character the_character[])
{

    strcpy(userName, Name);
    strcpy(password, pass);
    for (int i = 0; i < 5; i++)
    {
        characters[i] = the_character[i];
    }
    cout << "User created!" << endl
         << "User name: " << userName << endl;
}

void User::login()
{

    char loginName[10];
    char loginPass[10];

    cout << "User Name: ";
    cin >> loginName;
    cout << "Password: ";
    cin >> loginPass;

    while (strcmp(userName, loginName) && strcmp(password, loginPass))
    {
        cout << "Incorrect user name or password, please try again" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "User Name: ";
        cin >> loginName;
        cout << "Password: ";
        cin >> loginPass;
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
         << endl;
}

int User::characterCount()
{
    char initName[] = "N/A";
    int count = 0;
    char const *curr_Name;
    job curr_job;
    for (int i = 0; i < 5; i++)
    {
        characters[i].getName(curr_Name);
        characters[i].getJob(curr_job);
        if (strcmp(curr_Name, initName) && curr_job != Default){
            count++;
        }
    }
    return count;
}

User::~User()
{
    for (int i = 0; i < 5; i++)
    {
        characters[i].~Character();
    }
}