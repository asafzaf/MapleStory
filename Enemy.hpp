namespace Enemy {

class Enemy {
private:
    char* enemyName;
    int healthPoints;
    int attackStrength;
    int experienceWorth;
public:
    Enemy(char* EnemyName);
    Enemy(char* EnemyName, int &healthPoints);
    Enemy(char* EnemyName, int &healthPoints, int &attackStrength);
} ;

}