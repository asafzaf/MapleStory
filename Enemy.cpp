/*
========ASSIGNED BY======== 
  Rony Zrihen 318917549
  Asaf Zafrir 205929029
 */

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

        e_healthPoints = 10;
        e_attackStrength = 10;
        e_experienceWorth = 10;

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
        e_attackStrength = 10;
        e_experienceWorth = 10;

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
        e_experienceWorth = 10;

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

void Enemy::PrintEnemy(){
    cout << enemyName << "\t||\t" << e_healthPoints << "\t||\t" << e_attackStrength << "\t||\t" << e_experienceWorth << endl;
}

Enemy::~Enemy()
{
    delete enemyName;
}