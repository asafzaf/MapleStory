#include "User.hpp"
using namespace Users;

// Create New User //
User(char* userName, char* password) {
    try{ 
        user* new_user = new user ;
        if ( new_user == NULL ){
            throw 1;
        }

        new_user->userName = new char[10];
        new_user->password = new char[10];
        if ( new_user->userName == NULL || new_user->password == NULL ){
            throw 2;
        }

        strcpy(new_user->userName, userName);
        strcpy(new_user->password, password);
    
    }   catch ( int e ) ;

User(char* userName, char* password, character) {
    try{
        User* new_user = new User ;
        if ( new_user == NULL ){
            throw 1;
        }

        new_user->userName = new char[10];
        new_user->password = new char[10];
        if ( new_user->userName == NULL || new_user->password == NULL ){
            throw 2;
        }

        strcpy(new_user->userName, userName);
        strcpy(new_user->password, password);
    
    }   catch ( int e ) ;

}


}