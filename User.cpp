#include "User.hpp"
#include "Character.hpp"
#include <iostream>
#include <istream>

using namespace std;

void User::login()
{

    char loginName[10];
    char loginPass[10];
    cout << "           <<LOG-IN>>" << endl;
    cout << "            ~~~~~~~~" << endl;
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
    cout << "\t\tLogin successful!\n"
         << endl;
    cout << "\t    --==WELCOME " << userName << "==--" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
         << endl;
}

// Returns Number Of Characters In User's Bank//
int User::characterCount()
{

    int count = 0;
    char const *curr_Name;
    job curr_job;
    for (int i = 0; i < 5; i++)
    {
        characters[i].getName(curr_Name);
        characters[i].getJob(curr_job);
        if (curr_Name != NULL && curr_job != Default)
        {
            count++;
        }
    }
    return count;
}

// Insert New Character To User's Bank //
void User::insert_character()
{
    char *character_name = new char;
    int character_job;

    cout << "__________________________________________________" << endl;
    cout << "            ~~|Create New Character|~~" << endl;
    cout << "              ~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "Character Name: "; // new name for character
    cin >> character_name;

    cout << endl
         << "                 ~~|Select Job|~~ " << endl; // new job for character
    cout << "         0 - Warrior" << "          " << "1 - Magician" << endl;
    cout << "         2 - Rouge" << "            " << "3 - Archer" << endl;
    cout << "         4 - Pirate" << endl;
    cout << "------------------> ";
    cin >> character_job;

    // job choice validation
    while (character_job < 0 || character_job > 4)
    { 
        cout << "Invalid Job!, please try again" << endl;
        cout << "Select Job:";
        cin >> character_job;
    }

    job job_check;

    for (int i = 0; i < 5; i++)
    {

        characters[i].getJob(job_check);

        //checking if the slot is empty
        if (job_check == Default)
        {
            //resetting the slot to the new character
            characters[i].setCharacter(character_name, (job)character_job);
            cout << "Character Created successfuly!" << endl;
            return;
        }
    }
    cout << "Character List Is Full!" << endl;
}

// print all of the user's characters//
void User::print_characters()
{

    char J0[] = "Warrior";char J1[] = "Magician";char J2[] = "Rouge";char J3[] = "Archer";char J4[] = "Pirate";
    char *job_list[5] = {J0, J1, J2, J3, J4};
    job curr_job;
    char const *curr_name;
    
    
    for (int i = 0; i < 5; i++)
    {
        characters[i].getName(curr_name);
        characters[i].getJob(curr_job);

        if (curr_job == Default)
        {
            // print in case of empty slot
            cout << i + 1 << ".  "  << "      "  << "-" << endl;
            continue;
        }

        cout << i + 1 << ".  " << curr_name << "    " << job_list[curr_job] << endl;
    }
}

// Update Character status before switching characters//
void User::update_character(Character character, unsigned int index)
{

    int Exp;
    int Exp_Cap;
    int Level;

    if (index > 5)
    {
        cout << "Invalid Index!" << endl;
        return;
    }
    Exp = character.GETexperience();
    Exp_Cap = character.GETexperienceCapacity();
    Level = character.GETlevel();

    characters[index].update(Exp, Exp_Cap, Level);
}

void User::ChooseCharacter(Character &choosen_character, int num)
{ // changes the current character
    choosen_character = characters[num];
}



////////////////--==CONSTRUCTORS==--////////////////
User::User(char *Name, char *pass)
{
    char initName[] = "N/A";
    strcpy(userName, Name);
    strcpy(password, pass);

    for (int i = 0; i < 5; i++)
    {
        //setting all the characters to default
        characters[i] = Character(initName, Default);
    }

    cout << "User created!" << endl
         << "User name: " << userName << endl;
}

User::User(char Name[], char pass[], Character the_character)
{

    strcpy(userName, Name);
    strcpy(password, pass);


    characters[0] = Character();                //setting the first character to default
    characters[0].copyCharacter(the_character); //inserting the new character

    cout << "User created!" << endl
         << "User name: " << userName << endl;
}

User::User(char Name[], char pass[], Character the_character[])
{

    strcpy(userName, Name);
    strcpy(password, pass);
    for (int i = 0; i < 5; i++)
    {
        characters[i] = Character();
        characters[i].copyCharacter(the_character[i]);
    }
    cout << "User created!" << endl
         << "User name: " << userName << endl;
}
User::~User()
{
    for (int i = 0; i < 5; i++)
    {
        characters[i].~Character();
    }
}