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
/*     Enemy(char* EnemyName, int healthPoints);
    Enemy(char* EnemyName, int healthPoints, int attackStrength);
    Enemy(char* EnemyName, int healthPoints, int attackStrength, int experienceWorth); */

    ~Enemy();
} ;

#endif