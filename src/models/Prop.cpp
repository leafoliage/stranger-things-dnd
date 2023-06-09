#include "Prop.h"
#include "Player.h"

Prop::Prop() {}

Prop::Prop(string name, int quality, int price): 
    Item(name, ItemType::PROP, quality, price) {}

int Prop::useQuality(GameCharacter* user) {
    return getQuality();
}

void Prop::workOn(GameCharacter* target, GameCharacter* user) {
    // target->setEffect
}

bool Prop::triggerEvent(Object* obj) {
    Player *player = dynamic_cast<Player*>(obj);
    if (player == nullptr) return false;
    player->take(this);
    bool popped = player->getCurrentRoom()->popObject(this);
    if (popped) logf("You picked up %s", getName().c_str());
    return true;
}
