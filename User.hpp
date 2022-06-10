/*
========ASSIGNED BY======== 
  Rony Zrihen 318917549
  Asaf Zafrir 205929029
 */

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

    int current_character;
   
//--==functions==--//   
    void login();
    int characterCount();
    void insert_character();
    void print_characters();
    void update_character(Character characrter,unsigned int index);
    void ChooseCharacter(Character &choosen_character, int num);


//--==constructors==--//
    User(char Name[], char pass[]);
    User(char Name[], char pass[], Character the_character);
    User(char Name[], char pass[], Character the_character[]);
    
    ~User();
} ;
#endif
//}