#include "Armor.h"
#include "Player.h"

Armor::Armor() {}

Armor::Armor(string name, int quality, int visibility):
    Item(name, ARMOR, quality, visibility) {}

int Armor::useQuality(Player* player) {
    return getQuality() + player->getDexterity() + 10;
}

bool Armor::triggerEvent(Object* obj) {
    Player *player = dynamic_cast<Player*>(obj);
    if (player == nullptr) return false;
    player->wear(this);
    bool popped = player->getCurrentRoom()->popObject(this);
    if (popped) cout << "You picked up " << this->getName() << endl;
    return true;
}