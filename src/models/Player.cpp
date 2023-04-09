#include "Player.h"

Player::Player(): armor(NULL), ally(NULL) {}

Player::Player(string name, int job):
    GameCharacter(name,PLAYER,
    MAX_HEALTH+jobAilities[job][CONSTITUTION], MAX_HEALTH+jobAilities[job][CONSTITUTION],
    jobAilities[job][STRENGTH],jobAilities[job][DEXTERITY],
    jobAilities[job][CONSTITUTION],jobAilities[job][WISDOM]), 
    armor(NULL), ally(NULL), money(INIT_MONEY) {}

Player::Player(string name, int strength, int dexterity, int constitution, int wisdom):
    GameCharacter(name,PLAYER,MAX_HEALTH+constitution,MAX_HEALTH+constitution,
    strength,dexterity,constitution,wisdom), armor(NULL), ally(NULL), money(INIT_MONEY) {}

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

bool Player::attack(GameCharacter* rival, Item* equipment) {
    cout << "Roll to Attack! ";
    int hit = hitCheck(equipment);
    if (hit <= rival->armorClass() && hit < 20) {
        cout << "That attack was a miss" << endl;
        return false;
    }
    cout << "You hit " << rival->getName() << "!" << endl;

    cout << "Now roll the damage. ";
    if (!equipment) {
        int dam = rollDice(8, true);
        rival->takeDamage(dam,this);
    }
    else equipment->workOn(rival, this);
    return rival->checkIsDead();
}

int Player::armorClass() {
    int result = armor ? armor->useQuality(this) : ARMOR_CLASS_BASE + getDexterity();
    if (this->hasEffect(ATTRACT_FIRE)) {
        result += (result*this->getEffect(ATTRACT_FIRE))/4;
    }
    return result;
}

Item* Player::getWeapon() {
    int itemIndex;
    this->listInventory();
    cout << "Choose your weapon: ";
    itemIndex = this->inputNumPrompt(-1,this->getInventory().size());
    if (itemIndex<0) return NULL;
    return this->getInventory()[itemIndex];
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

bool Player::pay(int money) {
    if (this->money < money) return false;
    this->money -= money;
    cout << "You have " << this->money << " galleons left" << endl;
    return true;
}

bool Player::acquire(Item* item) {
    if (!pay(item->getPrice())) {
        cout << "Not enough galleons to buy that fancy toy!" << endl;
        return false;
    }
    switch (item->getItemType()) {
        case ItemType::ARMOR: 
            this->wear(dynamic_cast<Armor*>(item));
            break;
        case ItemType::PROP:
        case ItemType::WEAPON: 
            this->take(item);
            break;
        default:
            break;
    }
    cout << "You got a " << item->getName() << "!" << endl;
    return true;
}

int Player::inputNumPrompt(int lowbound, int upbound) {
    int input;
    cin >> input;
    while (input<lowbound || input>=upbound) {
        cout << "Choice out of range! Choose again: ";
        cin >> input;
    }
    getchar();
    return input;
}

bool Player::inputBoolPrompt() {
    char c;
    do {
        cin >> c; 
    } while (c!='Y'&&c!='y'&&c!='N'&&c!='n');
    if (c=='Y'||c=='y') return true;
    return false;
}

void Player::listInventory() {
    int i=0;
    cout << "------Inventory------" << endl;
    if (inventory.empty()) cout << "-1. bear hand" << endl;
    for (auto it=inventory.begin();it!=inventory.end();++it) {
        cout << i << "- " << (*it)->getName() << endl;
    }
    cout << "---------------------" << endl;
}

void Player::setCurrentRoom(Room* room) {
    currentRoom = room;
    if (room->getName().length() > 0) {
        cout << "You arrived at " << room->getName() << endl;
    }
}

void Player::setPreviousRoom(Room* room) {
    previousRoom = room;
}

void Player::setInventory(vector<Item*> inventory) {
    this->inventory = inventory;
}

void Player::setMoney(int money) {
    this->money = money;
}

void Player::setAlly(Ally* ally) {
    this->ally = ally;
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

int Player::getMoney() const {
    return money;
}

int Player::getJob() const {
    return job;
}

Ally* Player::getAlly() const {
    return ally;
}
