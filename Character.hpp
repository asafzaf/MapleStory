using namespace std;


enum job {Warrior, Magician, Rouge, Archer, Pirate};

class Character {
private:
    char* characterName;
    enum job characterJob; 
    int experience; // The amount of experience the player have right now
    int experienceCapacity; // How much experience needed for next level
    int level; // Character level
    int healthPoints; // Character health
    int attackStrength;
public:
    Character( char* &characterName, int &characterJob);
    Character( char* &characterName, int &characterJob, int &healthPoints);
    Character( char* &characterName, int &characterJob, int &healthPoints, int &attackStrength);
    void attack(Enemy);
} ;