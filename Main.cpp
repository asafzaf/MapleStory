
#include "User.hpp"
#include "Enemy.hpp"
#include <iostream>

using namespace std;
char C1[] = "Jinx"; char C2[] = "Elie"; char C3[] = "Joul"; char C4[] = "Ash"; char C5[] = "Jack";
Character characters[5] = {Character(C1,Warrior), Character(C2,Magician), Character(C3,Rouge), Character(C4,Archer), Character(C5,Pirate) } ;
char main_user_name[] = "YuviVerse";
char main_user_pass[] = "TwitchTTV";
//User main_user(main_user_name, main_user_pass);
User main_user(main_user_name, main_user_pass,characters[0]);
//User main_user(main_user_name, main_user_pass,characters);
int main()
{

    Character new_character;
    cout << "           <<LOG-IN>>" << endl;
    cout << "            ````````" << endl;

   // main_user.login();
    if (!main_user.characterCount()) // create new character
    { 
        char *character_name = new char;
        int character_job;
        cout << "There are currently no characters in your account." << endl;
        cout << "__________________________________________________" << endl;
        cout << "            ~~|Create New Character|~~" << endl;
        cout << "              ~~~~~~~~~~~~~~~~~~~~~~" << endl;

        cout << "Character Name: ";
        cin >> character_name;


        cout << endl << "                 ~~|Select Job|~~ " << endl;
        
        cout << "         0 - Warrior" << "          " << "1 - Magician" << endl;
        cout << "         2 - Rouge" << "            " << "3 - Archer" << endl;
        cout << "         4 - Pirate" << endl;
        cout << "------------------> ";
        cin >> character_job;

        while(character_job < 0 || character_job > 4){
            cout << "Invalid Job!, please try again" << endl;
            cout << "Select Job:";
            cin >> character_job;
        }

        new_character = Character(character_name, (job)character_job);
        main_user.insert_character(new_character,5);
    }
    else
    {
       cout << endl << "           ~~|Select Character|~~ " << endl; 
    }

    main_user.print_characters();
    cout << "--------> " << endl;
    
    cin >> main_user.chosen_charecter;
    return 0;
}