#ifndef __ENEMY__
#define __ENEMY__
#include <iostream>
#include <Cstring>

class Enemy {
private:
    char* enemyName;
    int healthPoints;
    int attackStrength;
    int experienceWorth;
public:
    Enemy(char* Name);
    Enemy(char* Name, int hp);
    Enemy(char* Name, int hp, int Strength);
    Enemy(char* Name, int hp, int Strength, int expWorth);

    ~Enemy();
} ;

#endif