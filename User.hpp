#ifndef __USER__
#define __USER__
#include <iostream>
#include <Cstring>
#include "Character.hpp"

//namespace Users {

class User {
private:    
    char userName[10];
    char password[10];
    Character characters[5]; //Notice it’s an array of the next Class
    
public:
    void login();
    int characterCount();

    User(char Name[], char pass[]);
    User(char Name[], char pass[], Character the_character);
    User(char Name[], char pass[], Character the_character[]);
    
    
    ~User();
} ;
#endif
//}