#include <iostream>
using namespace std;
#include <string.h>
#include "Character.cpp"

typedef class User_t {
private:    
    char userName[10];
    char password[10];
    Character characters [5]; //Notice it’s an array of the next Class
public:
    User(userName, password);
    User(userName, password, character);
    User(userName, password, character[]);

    
    user* signUp( char &userName, char &password );
    user* logIn( char &userName, char &password, character);
    user* (userName, password, character[]);
} user ;

user* signUp( char &userName, char &password ) {
    user* new_user = new user ;
    if ( new_user == NULL ){
        return NULL;
    }

    new_user->userName = new char[10];
    new_user->password = new char[10];

    strcpy(new_user->userName, userName);
    strcpy(new_user->password, password);

    return user;
}

User* logIn( char &userName, char &password, character);
