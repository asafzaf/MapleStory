#ifndef __CHARACTER__
#define __CHARACTER__
#include "Enemy.hpp"
using namespace std;

//added defult value to default as an indicator of empty character
 enum job {Default = -1, Warrior, Magician, Rouge, Archer, Pirate} ;

class Character {
private:
    char* characterName;
    enum job characterJob; 
    int experience;         // The amount of experience the player have right now
    int experienceCapacity; // How much experience needed for next level
    int level;              // Character level
    int healthPoints;       // Character health
    int attackStrength;
public:
//--==functions==--//
    void attack(Enemy &attackd_enemy);
    void getName(char const* &ptr);
    void getJob(job& Job);
    int GETexperience();
    int GETexperienceCapacity();
    int GETlevel();
    void copyCharacter(Character character);
    void setCharacter(char* Name, job Job);
    void update(int Exp, int Exp_Cap, int Level);


//--==constructors==--//
    Character();
    Character( char* Name, job Job);
    Character( char* Name, job Job, int hp);
    Character( char* Name, job Job, int hp, int Strength);
    ~Character();
} ;

#endif