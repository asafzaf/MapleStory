/*
========ASSIGNED BY======== 
  Rony Zrihen 318917549
  Asaf Zafrir 205929029
 */

#include "User.hpp"
#include "Enemy.hpp"
#include <iostream>

using namespace std;
void print_bar(int exp, int cap);


// for option the there are characters //
char C1[] = "Jinx";char C2[] = "Elie";char C3[] = "Joul";char C4[] = "Ash";char C5[] = "Jack sparrow";
Character characters[5] = {Character(C1, Warrior), Character(C2, Magician), Character(C3, Rouge), Character(C4, Archer), Character(C5, Pirate)};
Character test_character = Character(C4, Warrior);

// generating enemies //
char E1_name[4] = "avi";char E2_name[4] = "eli";char E3_name[6] = "jakob";char E4_name[6] = "david";char E5_name[5] = "josh";char E6_name[7] = "barbur";char E7_name[7] = "sandal";
Enemy enemies[7] = {Enemy(E1_name), Enemy(E2_name, 15, 15, 15), Enemy(E3_name, 22, 5, 10), Enemy(E4_name, 20, 10, 20), Enemy(E5_name, 50, 15, 30), Enemy(E6_name, 65, 30, 50), Enemy(E7_name, 50, 35, 30)};
int numberofenemies = 7;

// login details //
char main_user_name[] = "YuviVerse";
char main_user_pass[] = "TwitchTTV";


// options for starting :
 User main_user(main_user_name, main_user_pass);
// User main_user(main_user_name, main_user_pass, test_character);
//User main_user(main_user_name, main_user_pass, characters);

int main()
{

    int choiceChar;
    Character new_character;
    Character the_chosen_one;

     main_user.login();

    if (!main_user.characterCount()) // create new character if the user generated without one
    {
        cout << "There are currently no characters in your account." << endl;
        main_user.insert_character();
    }

    cout << endl
         << "           ~~|Select Character|~~ " << endl;
    main_user.print_characters();
    cout << "|==========> ";


    cin >> choiceChar;
    while (choiceChar > main_user.characterCount() || choiceChar <= 0)
    { // character choice validation
        cout << "Invalid choice! you have " << main_user.characterCount() << " Characters" << endl
             << "Please try again: ";
        cin >> choiceChar;
    }
    main_user.current_character = choiceChar - 1; //setting current character to the chosen one
    main_user.ChooseCharacter(the_chosen_one, choiceChar - 1); //getting character from user's bank

    // character choice Menu
    int MenuChoose = 0;
    while (MenuChoose != 9)
    {
        MenuChoose = 0;
        cout << endl
             << endl
             << "\tPlease choose option:" << endl
             << "1 - Attack\t\t2 - Add new character " << endl
             << "3 - Switch character\t4 - Character experience ststus" << endl
             << "0 - Exit program" << endl;
        cin >> MenuChoose;

        switch (MenuChoose)
        {
        case 1: // Attack
        {
            int chooseCforAttk;


            cout << "Attack mode!!!!!!" << endl
                 << endl
                 << "Enemys list:" << endl;

            
            // Enemy menu
            cout << "no.\t||      Name    || HealthPoints ||   Strength   ||Eexperience Worth" << endl;
            cout << "----------------------------------------------------------------------------" << endl;

            for (int i = 0; i < numberofenemies; i++)
            {
                cout << i + 1 << " \t||\t";
                enemies[i].PrintEnemy();
                cout << endl;
            }

            cout << "Please choose an enemy to attak: " << endl;
            cin >> chooseCforAttk;

            the_chosen_one.attack(enemies[chooseCforAttk - 1]);
            break;
        }
        case 2: // add new character
        {
            main_user.insert_character();
            break;
        }

        case 3: // Switch Character
        {
            cout << endl
                 << "           ~~|Select Character|~~ " << endl;
            main_user.print_characters();
            cout << "|==========>  " << endl;

            cin >> choiceChar;
            while (choiceChar > main_user.characterCount() || choiceChar <= 0)
            {
                cout << "Invalid choice! you have " << main_user.characterCount() << " Characters" << endl
                     << "Please try again: ";
                cin >> choiceChar;
            }
            main_user.update_character(the_chosen_one, main_user.current_character); //saving changes of previous character
            main_user.ChooseCharacter(the_chosen_one, choiceChar - 1); //getting the new character from user's bank
            main_user.current_character = choiceChar - 1;   

            break;
        }
        case 4: // Character status
        {
            char const *name;
            the_chosen_one.getName(name);

            cout << endl
                 << name << "'s status:" << endl
                 << "----------------" << endl
                 << "Character level: " << the_chosen_one.GETlevel() << endl;

            cout << "Exp: " << the_chosen_one.GETexperience() << "/" << the_chosen_one.GETexperienceCapacity() << endl;
            print_bar(the_chosen_one.GETexperience(), the_chosen_one.GETexperienceCapacity());

            cout << endl
                 << (the_chosen_one.GETexperienceCapacity() - the_chosen_one.GETexperience()) << " points until the next level!  " << endl;
            break;
        }

        case 0:
        {
            cout << "bye! :)" << endl;
            return 0;
        }

        default:
        {
            cout << "Wrong chiose! please try again" << endl
                 << endl;
            break;
        }
        }
    }

    // starting of attak
    return 0;
}

// just a cool bar for experience status
void print_bar(int exp, int cap)
{
    int percent = (exp * 100) / cap;
    int bar_length = percent;
    cout << "|";
    for (int i = 0; i < bar_length; i++)
    {
        cout << "=";
    }
    cout << ">";
    for (int i = 0; i < (100 - percent); i++)
    {
        cout << " ";
    }
    cout << "|" << endl;
}