typedef class Character_t {
private:
    char* characterName;
    enum job characterJob; 
    int experience; // The amount of experience the player have right now
    int experienceCapacity; // How much experience needed for next level
    int level; // Character level
    int healthPoints; // Character health
    int attackStrength;
public:
    Character(characterName, characterJob);
    Character(characterName, characterJob, healthPoints);
    Character(characterName, characterJob, healthPoints,attackStrength);
    attack(Enemy);
} character ;