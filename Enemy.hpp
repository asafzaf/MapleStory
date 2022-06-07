#ifndef __ENEMY__
#define __ENEMY__
#include <iostream>
#include <Cstring>

class Enemy {
private:
    char* enemyName;
    int e_healthPoints;
    int e_attackStrength;
    int e_experienceWorth;
public:
    Enemy();
    Enemy(char* Name);
    Enemy(char* Name, int hp);
    Enemy(char* Name, int hp, int Strength);
    Enemy(char* Name, int hp, int Strength, int expWorth);
    int getattack(Enemy &enemy);
    int gethealth(Enemy &enemy);
    int getexperiencworth(Enemy &enemy);
    ~Enemy();
} ;

#endif