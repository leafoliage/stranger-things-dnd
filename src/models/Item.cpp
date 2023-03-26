#include "Item.h"
#include "Player.h"

Item::Item() {}

Item::Item(string name, int itemType, int hardness, int visibility):
    Object(name, ITEM), itemType(itemType), hardness(hardness), visibility(visibility) {}

bool Item::triggerEvent(Object* obj) {
    Player *player = dynamic_cast<Player*>(obj);
    if (player == nullptr) return false;
    player->addItem(*this);
    player->getCurrentRoom()->popObject(this);
    return true;
}

int Item::useHardness() {
    return hardness;
}

void Item::setItemType(int itemType) {
    this->itemType = itemType;
}

void Item::setHardness(int hardness) {
    this->hardness = hardness;
}

void Item::setVisibility(int visibility) {
    this->visibility = visibility;
}

int Item::getItemType() const {
    return itemType;
}

int Item::getHardness() const {
    return hardness;
}

int Item::getVisibility() const {
    return visibility;
}
