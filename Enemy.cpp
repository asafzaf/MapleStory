
#include "Enemy.hpp"

using namespace std;

Enemy::Enemy(char* Name){
    try
    {
        enemyName = new char[strlen(Name) + 1];
        if (enemyName == NULL)
        {
            throw 1;
        }

        strcpy(enemyName, Name);

        int E_healthPoints = 10;
        int E_attackStrength = 10;
        int E_experienceWorth = 10;

        cout << "Enemy created!" << endl << "User name: " << enemyName << endl;
        cout << "Enemy healh: " << E_healthPoints << endl << "Enamy attak: " << E_attackStrength << endl << "Enemy experience: " << E_experienceWorth << endl;
    }
    catch (int e)
    {
        cout << "error with creating enamy - NULL argument" << endl;
    }

}


Enemy::~Enemy(){
    delete enemyName;
}