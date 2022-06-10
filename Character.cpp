#include "Character.hpp"
#include <Cstring>

using namespace std;

void Character::setCharacter(char* Name, job Job){
    characterName = new char[strlen(Name) + 1];
    if(characterName == NULL){
        printf("\nEROOR\n");
        return;
    }
    strcpy(characterName, Name);

    if(Job > 4 || Job < 0){
        printf("\nEROOR\n");
        return;
    }

    characterJob = Job;
    switch (Job)
        {
        case 0:
        {
            healthPoints = 50;
            attackStrength = 15;
            break;
        }
        case 1:
        {
            healthPoints = 20;
            attackStrength = 30;
            break;
        }
        case 2:
        {
            healthPoints = 30;
            attackStrength = 20;
            break;
        }
        case 3:
        {
            healthPoints = 35;
            attackStrength = 10;
            break;
        }
        case 4:
        {
            healthPoints = 25;
            attackStrength = 25;
            break;
        }
        default:
        {
            healthPoints = 0;
            attackStrength = 0;
            break;
        }
        }



}
void Character::update(int Exp, int Exp_Cap, int Level){
    
if(experience == Exp && experienceCapacity == Exp_Cap && level == Level){
    cout << "No update needed" << endl;
    return;
}
experience = Exp;
experienceCapacity = Exp_Cap;
level = Level;
cout << "character updated!  "<< characterName << "\tExp: " << experience << "/" << experienceCapacity << "\tLvl: " << level << endl; 
}

void Character::copyCharacter(Character character){
   
    characterName = new char[strlen(character.characterName) + 1]; //copying the name
    if(characterName == NULL){
        cout << "\nERROR\n";
        return;
    }
    strcpy(characterName, character.characterName);
   
    characterJob = character.characterJob; //copying the job

    //copying the stats
    experience = character.experience;
    experienceCapacity = character.experienceCapacity;
    level = character.level;
    healthPoints = character.healthPoints;
    attackStrength = character.attackStrength;


}
//////////GET FUNCTIONS//////////////
void Character::getName(char const *&ptr)
{
    ptr = characterName;
}


void Character::getJob(job &Job)
{
    Job = characterJob;
}


int Character::GETexperience(){
    return experience;
}

int Character::GETexperienceCapacity(){
    return experienceCapacity;
}

int Character::GETlevel(){
    return level;
}
//////////////////////////////////////

//LET'S FIGHT//
void Character::attack(Enemy &attackd_enemy){
    //getting enemy info
    int e_healthPoints = attackd_enemy.gethealth();
    int e_attackStrength = attackd_enemy.getattack();
    int e_experienceWorth = attackd_enemy.getexperiencworth();

    int c_healthPoints = healthPoints;
    int c_attackStrength = attackStrength;
    cout << endl << "LET'S FIGHT!" << endl << "-----------" <<endl << "boom! @#!" << endl << "BOOM! @#!%$" << endl << "poww" << endl << ".\n.\n." << endl << endl;

    while( c_healthPoints > 0 && e_healthPoints > 0)
    {
        e_healthPoints -= c_attackStrength;
        if (e_healthPoints <= 0)
        {
            experience += e_experienceWorth;
            if ( experience >= experienceCapacity ) // the level up rule
            {
            ++level;
            ++healthPoints;
            ++attackStrength;
            experience -= experienceCapacity;
            experienceCapacity *= 2;
                cout << characterName << " has won!!! and LEVELD UP!!! :)" << endl <<
                        "you are on level " << level << " right now" << endl <<
                        "you got " << e_experienceWorth << " experience points" << endl <<
                        "you have now " << experience << " points of " << experienceCapacity << endl;
            }
            else
            {
                cout << characterName << " has won!!!" << endl <<
                        "you got " << e_experienceWorth << " experience points" << endl <<
                        "you have now " << experience << " points of " << experienceCapacity << endl;
            }
        }
        else
        {
            c_healthPoints -= e_attackStrength;
            if ( c_healthPoints <= 0 )
            {
                experience -= 5;
                if( experience < 0){
                    experience = 0;
                }
                cout << characterName << " has lost..." << endl <<
                    "you lost -5 experience points" << endl <<
                    "you have now " << experience << " points of " << experienceCapacity << endl;
            }
        }
    }
}



//--==constructors==--//

Character::Character()
{

    characterName = NULL;
    characterJob = Default;
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

        experience = 0;
        experienceCapacity = 10;
        level = 1;

        switch (Job)
        {
        case 0:
        {
            healthPoints = 50;
            attackStrength = 15;
            break;
        }
        case 1:
        {
            healthPoints = 20;
            attackStrength = 30;
            break;
        }
        case 2:
        {
            healthPoints = 30;
            attackStrength = 20;
            break;
        }
        case 3:
        {
            healthPoints = 35;
            attackStrength = 10;
            break;
        }
        case 4:
        {
            healthPoints = 25;
            attackStrength = 25;
            break;
        }
        default:
        {
            healthPoints = 0;
            attackStrength = 0;
            break;
        }
        }
        if(Job != Default)
        {
        cout << "character created!!!  "<< Name << "\t" << healthPoints << "\t" << attackStrength << "\t" << level << endl; 
        }
    }
    catch (int e)
    {
        cout << "ERROR" << endl;
    }
}
Character::Character( char* Name, job Job, int hp){

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

        experience = 0;
        experienceCapacity = 10;
        level = 1;
        healthPoints = hp;
    }
    catch (int e)
    {
        cout << "ERROR" << endl;
    }

    switch (Job)
        {
        case 0:
        {
            attackStrength = 15;
            break;
        }
        case 1:
        {
            attackStrength = 30;
            break;
        }
        case 2:
        {
            attackStrength = 20;
            break;
        }
        case 3:
        {
            attackStrength = 10;
            break;
        }
        case 4:
        {
            attackStrength = 25;
            break;
        }
        default:
        {
            attackStrength = 0;
            break;
        }
        }
                cout << "character created!!!  "<< Name << "\t" << healthPoints << "\t" << attackStrength << "\t" << level << endl; 

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

        experience = 0;
        experienceCapacity = 10;
        level = 1;
        healthPoints = hp;
        attackStrength = Strength;
    }
    catch (int e)
    {
        cout << "ERROR" << endl;
    }
    cout << "character created!!!  "<< Name << "\t" << healthPoints << "\t" << attackStrength << "\t" << level << endl;
}
Character::~Character()
{
    delete characterName;
}