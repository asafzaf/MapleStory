#include "Character.hpp"
#include <Cstring>

using namespace std;

Character::Character(char *Name, job Job)
{

    try
    {

        characterName = new char[strlen(Name)+1];
        if(characterName == NULL){
            throw 1;
        }
        strcpy(characterName , Name);
        
        if(Job > 4 || Job < 0){
            throw 2;
        }

        characterJob = Job;
        
        int experience = 0;
        int experienceCapacity = 10;
        int level = 1;

        switch(Job)
        {
            case 0:
            {
                int healthPoints = 50;
                int attackStrength = 15;
            }
            case 1:
            {
                int healthPoints = 20;
                int attackStrength = 30;
            }
            case 2:
            {
                int healthPoints = 30;
                int attackStrength = 20;
            }
            case 3:
            {
                int healthPoints = 35;
                int attackStrength = 10;
            }
            case 4:
            {
                int healthPoints = 25;
                int attackStrength = 25;
            }
        }


    }
    catch (int e)
    {
        cout << "ERROR" << endl;
    }
}


Character::~Character(){
    delete characterName;
}
