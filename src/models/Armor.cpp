#include "Armor.h"
#include "Player.h"

Armor::Armor() {}

Armor::Armor(string name, int hardness, int visibility):
    Item(name, ARMOR, hardness, visibility) {}

bool Armor::triggerEvent(Object* obj) {
    Player *player = dynamic_cast<Player*>(obj);
    if (player == nullptr) return false;
    player->addArmor(*this);
    player->getCurrentRoom()->popObject(this);
    return true;
}