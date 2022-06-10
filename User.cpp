#include "User.hpp"
#include "Character.hpp"
#include <iostream>
#include <istream>

using namespace std;
// using namespace Users;

// Create New User //

User::User(char *Name, char *pass)
{
    char initName[] = "N/A";
    strcpy(userName, Name);
    strcpy(password, pass);

    for (int i = 0; i < 5; i++)
    {
        characters[i] = Character(initName, Default) ;
    }

    cout << "User created!" << endl
         << "User name: " << userName << endl;
    cout << "Password: " << password << endl;


}

User::User(char Name[], char pass[], Character the_character)
{
     char const * newName;
    // job newjob;
    strcpy(userName, Name);
    strcpy(password, pass);

    // the_character.copyname(Name);
    // the_character.getJob(newjob);


    characters[0] = Character();
    characters[0].copyCharacter(the_character);

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
    cout << "\t\tLogin successful!\n" << endl;
    cout << "\t    --==WELCOME " << userName << "==--" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
         << endl;
}

int User::characterCount()
{

    int count = 0;
    char const *curr_Name;
    job curr_job;
    for (int i = 0; i < 5; i++)
    {
        characters[i].getName(curr_Name);
        characters[i].getJob(curr_job);
        if (curr_Name != NULL && curr_job != Default){
            count++;
        }
    }
    return count;
}

void User::insert_character(){
    char* character_name = new char;
    int character_job;

     cout << "__________________________________________________" << endl;
                cout << "            ~~|Create New Character|~~" << endl;
                cout << "              ~~~~~~~~~~~~~~~~~~~~~~" << endl;

                cout << "Character Name: "; // new mane for character
                cin >> character_name;

                cout << endl << "                 ~~|Select Job|~~ " << endl; // new job

                cout << "         0 - Warrior" << "          " << "1 - Magician" << endl;
                cout << "         2 - Rouge" << "            " << "3 - Archer" << endl;
                cout << "         4 - Pirate" << endl;
                cout << "------------------> ";
                cin >> character_job;

                while(character_job < 0 || character_job > 4){ // job choice validation
                    cout << "Invalid Job!, please try again" << endl;
                    cout << "Select Job:";
                    cin >> character_job;
                }

    job job_check;

    for(int i = 0 ; i < 5 ; i++){

    characters[i].getJob(job_check);
   
    if(job_check == Default){

        characters[i].setCharacter(character_name, (job)character_job);
        cout << "Character Created successfuly!" << endl;
        return;
    }
    }
    cout << "Character List Is Full!" << endl;
}

void User::print_characters(){
   
   char J0[] = "Warrior"; char J1[] = "Magician"; char J2[] = "Rouge"; char J3[] = "Archer"; char J4[] = "Pirate";
   char *job_list[5] = {J0, J1, J2, J3, J4 };
   job curr_job;
   char * curr_name;
    for (int i = 0 ; i < 5 ; i++){
        characters[i].copyname(curr_name);
        characters[i].getJob(curr_job);

        if (curr_job == Default){

         cout << i+1 << ".  " << "    " << "-" << endl ;
            continue;
        }

        cout << i+1 << ".  " << curr_name << "    " << job_list[curr_job] << endl;

    }
}

void User::ChooseCharacter(Character &choosen_character, int num){
    choosen_character = characters[num];
}


User::~User()
{
    for (int i = 0; i < 5; i++)
    {
        characters[i].~Character();
    }
}