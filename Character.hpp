#ifndef __CHARACTER__
#define __CHARACTER__
#include "Enemy.hpp"
using namespace std;

enum job {Warrior, Magician, Rouge, Archer, Pirate};

class Character {
private:
    char* characterName;
    enum job characterJob; 
    int experience; // The amount of experience the player have right now
    int experienceCapacity; // How much experience needed for next level
    int level; // Character level
    int healthPoints; // Character health
    int attackStrength;
public:
    //Character();
    Character( char* Name, job Job);
    // Character( char* Name, job Job, int hp);
    // Character( char* Name, job Job, int hp, int Strength);
    int attack(Enemy enemy);

    ~Character();
} ;
#endif