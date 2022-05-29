#include <iostream>
#include <Cstring>
#include "Character.hpp"

namespace Users {

class User {
private:    
    char userName[10];
    char password[10];
    Character characters[5]; //Notice it’s an array of the next Class
public:
    User(char* userName, char* password);
    User(char* userName, char* password, Character the_character); 
    User(char* userName, char* password, Character the_character[]);

    ~User();
} ;

}