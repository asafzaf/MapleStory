#include "Character.hpp"
#include <Cstring>

using namespace std;

Character::Character()
{
    characterName = NULL;
}

Character::Character(char *Name, job Job)
{

    try
    {

        characterName = new char[strlen(Name) + 1];
        if (characterName == NULL)
        {
            throw 1;
        }
        strcpy(characterName, Name);

        if (Job > 4 || Job < -1)
        {
            throw 2;
        }

        characterJob = Job;

        experience = 0;
        experienceCapacity = 10;
        level = 1;

        switch (Job)
        {
        case 0:
        {
            healthPoints = 50;
            attackStrength = 15;
            break;
        }
        case 1:
        {
            healthPoints = 20;
            attackStrength = 30;
            break;
        }
        case 2:
        {
            healthPoints = 30;
            attackStrength = 20;
            break;
        }
        case 3:
        {
            healthPoints = 35;
            attackStrength = 10;
            break;
        }
        case 4:
        {
            healthPoints = 25;
            attackStrength = 25;
            break;
        }
        default:
        {
            healthPoints = 0;
            attackStrength = 0;
            break;
        }
        }
        cout << "character created!!!  "<< Name << "\t" << healthPoints << "\t" << attackStrength << "\t" << level << endl; 
    }
    catch (int e)
    {
        cout << "ERROR" << endl;
    }
}

Character::Character(char *Name, job Job, int hp, int Strength)
{

    try
    {
        characterName = new char[strlen(Name) + 1];
        if (characterName == NULL)
        {
            throw 1;
        }
        strcpy(characterName, Name);

        if (Job > 4 || Job < 0)
        {
            throw 2;
        }

        characterJob = Job;

        experience = 0;
        experienceCapacity = 10;
        level = 1;
        healthPoints = hp;
        attackStrength = Strength;
    }
    catch (int e)
    {
        cout << "ERROR" << endl;
    }
}

void Character::getName(char const *&ptr)
{
    ptr = characterName;
}

void Character::getJob(job &Job)
{
    Job = characterJob;
}

Character::~Character()
{
    delete characterName;
}

int Character::GETexperience(){
    return experience;
}

int Character::GETexperienceCapacity(){
    return experienceCapacity;
}

int Character::GETlevel(){
    return level;
}



void Character::attack(Enemy &attackd_enemy){
    
    int e_healthPoints = attackd_enemy.gethealth();
    int e_attackStrength = attackd_enemy.getattack();
    int e_experienceWorth = attackd_enemy.getexperiencworth();

    int c_healthPoints = healthPoints;
    int c_attackStrength = attackStrength;
    cout << endl << "let's fight!" << endl << "-----------" << endl << "boom!" << endl << "poww" << endl << "..." << endl << endl;

    while( c_healthPoints > 0 && e_healthPoints > 0)
    {
        e_healthPoints -= c_attackStrength;
        if (e_healthPoints <= 0)
        {
            experience += e_experienceWorth;
            if ( experience >= experienceCapacity ) // the level up rule
            {
            ++level;
            ++healthPoints;
            ++attackStrength;
            experience -= experienceCapacity;
            experienceCapacity *= 2;
                cout << characterName << " has won!!! and LEVELD UP!!! :)" << endl <<
                        "you are on level " << level << " right now" << endl <<
                        "you got " << e_experienceWorth << " experience points" << endl <<
                        "you have now " << experience << " points of " << experienceCapacity << endl;
            }
            else
            {
                cout << characterName << " has won!!!" << endl <<
                        "you got " << e_experienceWorth << " experience points" << endl <<
                        "you have now " << experience << " points of " << experienceCapacity << endl;
            }
        }
        else
        {
            c_healthPoints -= e_attackStrength;
            if ( c_healthPoints <= 0 )
            {
                experience -= 5;
                if( experience < 0){
                    experience = 0;
                }
                cout << characterName << " has lost..." << endl <<
                    "you lost -5 experience points" << endl <<
                    "you have now " << experience << " points of " << experienceCapacity << endl;
            }
        }
    }
}