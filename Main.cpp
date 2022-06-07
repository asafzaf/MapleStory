
#include "User.hpp"
#include "Enemy.hpp"
#include <iostream>

using namespace std;
 char main_user_name[] = "YuviVerse";
 char main_user_pass[] = "TwitchTTV";
User main_user(main_user_name, main_user_pass);
int main() {


cout << "<<LOG-IN>>" << endl;
cout << " ````````" << endl << endl;

//main_user.login(); 

 if (!main_user.characterCount()){

     
 }



char name1[5] = "rony";
char name2[10] = "asaf";
char password[10] = "12345";
    char E1_name[4] = "avi";
    char E2_name[4] = "eli";
    char E3_name[6] = "jakob";
    char E4_name[6] = "david";
    char E5_name[5] = "josh";
    char E6_name[7] = "barbur";
    char E7_name[7] = "sandal";
    Enemy E1(E1_name);
    Enemy E2(E2_name, 15, 15, 15);
    Enemy E3(E3_name, 22, 5, 10);
    Enemy E4(E4_name, 20, 10, 20);
    Enemy E5(E5_name, 50, 15, 30);
    Enemy E6(E6_name, 65, 30, 50);
    Enemy E7(E7_name, 50, 35, 30);
    User myUser(name2, password);
    

// create new user
 
// login and choose character

    return 0;
}