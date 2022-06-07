
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

        int e_healthPoints = 10;
        int e_attackStrength = 10;
        int e_experienceWorth = 10;

        cout << "Enemy created!" << endl
             << "Enemy name: " << enemyName << endl;
        cout << "Enemy healh: " << e_healthPoints << endl
             << "Enamy attak: " << e_attackStrength << endl
             << "Enemy experience: " << e_experienceWorth << endl;
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
        e_healthPoints = hp;
        int e_attackStrength = 10;
        int e_experienceWorth = 10;

        cout << "Enemy created!" << endl
             << "Enemy name: " << enemyName << endl;
        cout << "Enemy healh: " << e_healthPoints << endl
             << "Enamy attak: " << e_attackStrength << endl
             << "Enemy experience: " << e_experienceWorth << endl;
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
        e_healthPoints = hp;
        e_attackStrength = Strength;
        int e_experienceWorth = 10;

        cout << "Enemy created!" << endl
             << "Enemy name: " << enemyName << endl;
        cout << "Enemy healh: " << e_healthPoints << endl
             << "Enamy attak: " << e_attackStrength << endl
             << "Enemy experience: " << e_experienceWorth << endl;
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
        e_healthPoints = hp;
        e_attackStrength = Strength;
        e_experienceWorth = expWorth;

        cout << "Enemy created!" << endl
             << "Enemy name: " << enemyName << endl;
        cout << "Enemy healh: " << e_healthPoints << endl
             << "Enamy attak: " << e_attackStrength << endl
             << "Enemy experience: " << e_experienceWorth << endl;
    }catch(int e)
    {
        cout << "error with creating enamy - NULL argument" << endl;
    }
}
int Enemy::getattack(){
    return e_attackStrength;
}

int Enemy::gethealth(){
    return e_healthPoints;
}

int Enemy::getexperiencworth(){
    return e_experienceWorth;
}

Enemy::~Enemy()
{
    delete enemyName;
}