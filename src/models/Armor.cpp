#include "Armor.h"
#include "Player.h"

Armor::Armor() {}

Armor::Armor(string name, int quality, int price):
    Item(name, ARMOR, quality, price) {}

int Armor::useQuality(GameCharacter* user) {
    return getQuality();
}

void Armor::workOn(GameCharacter* target, GameCharacter* user) {}

bool Armor::triggerEvent(Object* obj) {
    Player *player = dynamic_cast<Player*>(obj);
    if (player == nullptr) return false;
    player->wear(this);
    bool popped = player->getCurrentRoom()->popObject(this);
    if (popped) logf("You picked up %s", getName().c_str());
    return true;
}