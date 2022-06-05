
#include "Enemy.hpp"

using namespace std;

Enemy::Enemy(char *Name)
{
    try
    {
        enemyName = new char[strlen(Name) + 1];
        if (enemyName == NULL)
        {
            throw 1;
        }

        strcpy(enemyName, Name);

        int healthPoints = 10;
        int attackStrength = 10;
        int experienceWorth = 10;

        cout << "Enemy created!" << endl
             << "User name: " << enemyName << endl;
        cout << "Enemy healh: " << healthPoints << endl
             << "Enamy attak: " << attackStrength << endl
             << "Enemy experience: " << experienceWorth << endl;
    }
    catch (int e)
    {
        cout << "error with creating enamy - NULL argument" << endl;
    }
}

Enemy::Enemy(char *Name, int hp)
{

    try
    {
        enemyName = new char[strlen(Name) + 1];
        if (enemyName == NULL)
        {
            throw 1;
        }
        strcpy(enemyName, Name);
        healthPoints = hp;
        int attackStrength = 10;
        int experienceWorth = 10;

    }catch(int e)
    {
        cout << "error with creating enamy - NULL argument" << endl;
    }
}

Enemy::Enemy(char* Name, int hp, int Strength){
    try
    {
        enemyName = new char[strlen(Name) + 1];
        if (enemyName == NULL)
        {
            throw 1;
        }
        strcpy(enemyName, Name);
        healthPoints = hp;
        attackStrength = Strength;
        int experienceWorth = 10;

    }catch(int e)
    {
        cout << "error with creating enamy - NULL argument" << endl;
    }
}

Enemy::Enemy(char* Name, int hp, int Strength, int expWorth){

    try
    {
        enemyName = new char[strlen(Name) + 1];
        if (enemyName == NULL)
        {
            throw 1;
        }
        strcpy(enemyName, Name);
        healthPoints = hp;
        attackStrength = Strength;
        experienceWorth = expWorth;

    }catch(int e)
    {
        cout << "error with creating enamy - NULL argument" << endl;
    }

}
Enemy::~Enemy()
{
    delete enemyName;
}