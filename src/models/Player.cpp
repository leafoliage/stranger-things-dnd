#include "Player.h"

Player::Player() {}

Player::Player(string name, int strength, int dexterity, int constitution, int wisdom):
    GameCharacter(name,PLAYER,25+constitution,25+constitution,strength,dexterity,constitution,wisdom) {}

void Player::changeRoom(Room* newRoom) {
    previousRoom = currentRoom;
    currentRoom = newRoom;
}

bool Player::triggerEvent(Object* obj) {
    // Show the status of the player
    cout << "Player status:" << endl;
    cout << "----------------" << endl;
    cout << "Current HP: " << getCurrHp() << endl;
    cout << "Strength: " << getStrength() << endl;
    cout << "Dexterity: " << getDexterity() << endl;
    cout << "Constitution: " << getConstitution() << endl;
    cout << "Wisdom: " << getWisdom() << endl;
    cout << "Money: " << money << endl;
    return true;
}

void Player::attack(GameCharacter* rival, Item* equipment) {
    char c;
    cout << "Roll to Attack! Press Enter to roll a D20: ";
    scanf("%c", &c);
    int hit = hitCheck(equipment);
    if (hit <= rival->armorClass() && hit < 20) {
        cout << "That attack was a miss" << endl;
        return;
    }
    cout << rival->getName() << " got hit by your " << equipment->getName() << "!" << endl;
    cout << "Now roll the damage. Press Enter to roll a D20: ";
    scanf("%c", &c);
    equipment->workOn(rival, this);
}

int Player::armorClass() {
    if (!armor) return ARMOR_CLASS_BASE + getDexterity();
    return armor->useQuality(this);
}

void Player::take(Item* item) {
    if (inventory.size() >= MAX_INVENTORY) {
        cout << "Your backpack is full!" << endl << "Discard something!";
        return;
    }
    inventory.push_back(item);
}

void Player::wear(Armor* arm) {
    if (armor != NULL) currentRoom->getObjects().push_back(armor);
    armor = arm;
}

void Player::discard(int index) {
    if (index >=0 && index < inventory.size()) {
        currentRoom->getObjects().push_back(inventory[index]);
        inventory.erase(inventory.begin() + index);
    }
}

void Player::setCurrentRoom(Room* room) {
    currentRoom = room;
}

void Player::setPreviousRoom(Room* room) {
    previousRoom = room;
}

void Player::setInventory(vector<Item*> inventory) {
    this->inventory = inventory;
}

Room* Player::getCurrentRoom() const {
    return currentRoom;
}

Room* Player::getPreviousRoom() const {
    return previousRoom;
}

vector<Item*> Player::getInventory() const {
    return inventory;
}

Armor* Player::getArmor() const {
    return armor;
}
