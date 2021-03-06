#include "User.hpp"
#include "Enemy.hpp"
#include <iostream>

using namespace std;

// for option the there are characters //
char C1[] = "Jinx"; char C2[] = "Elie"; char C3[] = "Joul"; char C4[] = "Ash"; char C5[] = "Jack";
Character characters[5] = {Character(C1,Warrior), Character(C2,Magician), Character(C3,Rouge), Character(C4,Archer), Character(C5,Pirate) } ;

// generating enemies //
char E1_name[4] = "avi"; char E2_name[4] = "eli"; char E3_name[6] = "jakob"; char E4_name[6] = "david"; char E5_name[5] = "josh"; char E6_name[7] = "barbur"; char E7_name[7] = "sandal";
Enemy enemies[7] = {Enemy(E1_name),
                    Enemy(E2_name, 15, 15, 15),
                    Enemy(E3_name, 22, 5, 10),
                    Enemy(E4_name, 20, 10, 20),
                    Enemy(E5_name, 50, 15, 30),
                    Enemy(E6_name, 65, 30, 50),
                    Enemy(E7_name, 50, 35, 30)};
int numberofenemies = 7;

// login details //
char main_user_name[] = "YuviVerse";
char main_user_pass[] = "TwitchTTV";

// options for starting :

User main_user(main_user_name, main_user_pass);
//User main_user(main_user_name, main_user_pass,characters[0]);
//User main_user(main_user_name, main_user_pass,characters);


int main()
{
    Character new_character;
    cout << "           <<LOG-IN>>" << endl;
    cout << "            ````````" << endl;

   // main_user.login();
    if (!main_user.characterCount()) // create new character if the user generated without one
    { 

        char *character_name = new char;
        int character_job;
        cout << "There are currently no characters in your account." << endl;
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

        new_character = Character(character_name, (job)character_job); // space allocation for new character
        main_user.insert_character(new_character,5);
    }
    else
    {
       cout << endl << "           ~~|Select Character|~~ " << endl; 
    }
    
    main_user.print_characters();
    cout << "--------> " << endl;
    
    Character the_chosen_one;

    int choiceChar;

    cin >> choiceChar;

    while( choiceChar > main_user.characterCount() || choiceChar < 0 ){ // character choice validation
        cout << "Invalid choice! you have " << main_user.characterCount() << " Characters" << endl <<
        "Please try again: ";
        cin >> choiceChar;
    }
    main_user.ChooseCharacter(the_chosen_one, choiceChar-1);

// character choice Menu
    int MenuChoose = 0;
    while( MenuChoose != 9) 
    {
        MenuChoose = 0;
        cout << endl << endl << "Please choose option:" << endl <<
            "1 - Attack" << endl <<
            "2 - Character experience ststus" << endl <<
            "3 - Switch character" << endl <<
            "0 - Exit program" << endl ;
        cin >> MenuChoose;

        switch(MenuChoose)
        {
            case 1: // Attak
            {
                int chooseCforAttk;
                
                //Character the_chosen_one;
                //main_user.ChooseCharacter(the_chosen_one,1);
                
                cout << "Attack mode!!!!!!" << endl << endl << "Enemys list:" << endl;

                //menu

                cout << "no.\t||      Name    || HealthPoints ||   Strength   ||Eexperience Worth" << endl;
                cout << "----------------------------------------------------------------------------" << endl;

                for(int i = 0 ; i < numberofenemies ; i++){
                    cout << i+1 << " \t||\t";
                    enemies[i].PrintEnemy();
                    cout << endl;
                }

                cout << "Please choose an enemy to attak: " << endl;
                cin >> chooseCforAttk;

                the_chosen_one.attack(enemies[chooseCforAttk-1]);
                break;
            }

            case 2: // Character status
            {
                cout << endl << "Character status:" << endl << "----------------" << endl <<
                "Character level: " << the_chosen_one.GETlevel() << endl <<
                the_chosen_one.GETexperience() << " of " << the_chosen_one.GETexperienceCapacity() << " experience points" << endl <<
                "To next level --> " << (the_chosen_one.GETexperienceCapacity()-the_chosen_one.GETexperience()) << " points";
                break;
            }

            case 3: // Switch Character
            {
                cout << endl << "           ~~|Select Character|~~ " << endl;
                main_user.print_characters();
                cout << "--------> " << endl;
                
                cin >> choiceChar;
                while( choiceChar > main_user.characterCount() || choiceChar < 0 ){
                    cout << "Invalid choice! you have " << main_user.characterCount() << " Characters" << endl <<
                    "Please try again: ";
                    cin >> choiceChar;
                }
                main_user.ChooseCharacter(the_chosen_one, choiceChar-1);

                break;
            }

            case 0:
            {
                cout << "bye! :)" << endl;
                return 0;
            }

            default:
            {
                cout << "Wrong chiose! please try again" << endl << endl ;
                break;
            }
        }
    }
    
    //starting of attak
    return 0;
}

