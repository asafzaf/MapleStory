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

        int experience = 0;
        int experienceCapacity = 10;
        int level = 1;

        switch (Job)
        {
        case 0:
        {
            int healthPoints = 50;
            int attackStrength = 15;
            break;
        }
        case 1:
        {
            int healthPoints = 20;
            int attackStrength = 30;
            break;
        }
        case 2:
        {
            int healthPoints = 30;
            int attackStrength = 20;
            break;
        }
        case 3:
        {
            int healthPoints = 35;
            int attackStrength = 10;
            break;
        }
        case 4:
        {
            int healthPoints = 25;
            int attackStrength = 25;
            break;
        }
        default:
        {
            int healthPoints = 0;
            int attackStrength = 0;
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

        int experience = 0;
        int experienceCapacity = 10;
        int level = 1;
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
}