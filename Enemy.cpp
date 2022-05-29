enum job {Warrior, Magician, Rouge, Archer, Pirate};

class Enemy_t {
private:
    char* enemyName;
    int healthPoints;
    int attackStrength;
    int experienceWorth;
public:
    Enemy(EnemyName);
    Enemy(EnemyName, healthPoints);
    Enemy(EnemyName, healthPoints, attackStrength);
} enemy ;