#include "Character.hpp"
#include <string>

using namespace std;

Character::Character()
{
    characterName = NULL;
    characterJob = Default;
    experience = 0;
    level = 0;
    healthPoints = 0;
    attackStrength = 0;
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
    if(characterName != NULL)
        delete characterName;
}

int Character::attack(Character character, Enemy attackd_enemy){
    
    int e_healthPoints = attackd_enemy.gethealth();
    int e_attackStrength = attackd_enemy.getattack();
    int e_experienceWorth = attackd_enemy.getexperiencworth();

    while( healthPoints > 0 && e_healthPoints > 0)
    {
        e_healthPoints -= attackStrength;
        if (e_healthPoints <= 0)
        {
            cout << characterName << " has won!!!" << endl <<
                    "you got " << e_experienceWorth << "experience points" << endl <<
                    "you have now " << experience + e_experienceWorth << "points of " << experienceCapacity << endl;
            return e_experienceWorth;
        }
        else
        {
            healthPoints -= e_attackStrength;
            if (healthPoints <= 0)
            {
                cout << characterName << " has lost..." << endl <<
                    "you lost -5 experience points" << endl <<
                    "you have now " << experience - 5 << "points of " << experienceCapacity << endl;
                return -5;
            }
        }
    }
    return 0;
}
