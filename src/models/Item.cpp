#include "Item.h"
#include "Player.h"

Item::Item() {}

Item::Item(string name, int itemType, int quality, int visibility):
    Object(name, ITEM), itemType(itemType), quality(quality), visibility(visibility) {}

bool Item::triggerEvent(Object* obj) {
    Player *player = dynamic_cast<Player*>(obj);
    if (player == nullptr) return false;
    player->addItem(this);
    bool popped = player->getCurrentRoom()->popObject(this);
    if (popped) cout << "You picked up " << this->getName() << endl;
    return true;
}

int Item::useQuality(Player* player) {
    return quality;
}

void Item::setItemType(int itemType) {
    this->itemType = itemType;
}

void Item::setQuality(int quality) {
    this->quality = quality;
}

void Item::setVisibility(int visibility) {
    this->visibility = visibility;
}

int Item::getItemType() const {
    return itemType;
}

int Item::getQuality() const {
    return quality;
}

int Item::getVisibility() const {
    return visibility;
}
