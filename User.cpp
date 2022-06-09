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
    char initName[] = "N/A";
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
    char  initName[] = "N/A";
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

void User::insert_character(Character character, unsigned int index){

    job job_check;


    if(index > 4){
        cout << "Invalid Index, searching for empty space" << endl;
        index = 0;
    }

    for( ;index < 5 ; index++){

    characters[index].getJob(job_check);
   
    if(job_check == Default){
        characters[index].~Character();
        characters[index] = character;
        return;
    }
    }
    cout << "Character List Is Full!" << endl;
}

void User::print_characters(){
   
   char J0[] = "Warrior"; char J1[] = "Magician"; char J2[] = "Rouge"; char J3[] = "Archer"; char J4[] = "Pirate";
   char *job_list[5] = {J0, J1, J2, J3, J4 };
   job curr_job;
   char const* curr_name;
    for (int i = 0 ; i < 5 ; i++){
        characters[i].getName(curr_name);
        characters[i].getJob(curr_job);

        if (curr_job == Default){

         cout << i+1 << ".  " << curr_name << "    " << "-" << endl ;
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