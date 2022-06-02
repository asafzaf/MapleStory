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

    }
    catch (int e)
    {
        cout << "ERROR" << endl;
    }
}


Character::~Character(){
    delete characterName;
}
