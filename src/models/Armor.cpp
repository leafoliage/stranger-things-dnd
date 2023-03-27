#include "Armor.h"
#include "Player.h"

Armor::Armor() {}

Armor::Armor(string name, int hardness, int visibility):
    Item(name, ARMOR, hardness, visibility) {}

int Armor::useHardness(Player* player) {
    return getHardness() + player->getDexterity() + 10;
}

bool Armor::triggerEvent(Object* obj) {
    Player *player = dynamic_cast<Player*>(obj);
    if (player == nullptr) return false;
    player->addArmor(*this);
    player->getCurrentRoom()->popObject(this);
    return true;
}