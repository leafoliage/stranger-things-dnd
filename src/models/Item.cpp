#include "Item.h"
#include "Player.h"

Item::Item() {}

Item::Item(string name, int itemType, int quality, int visibility):
    Object(name, ITEM), itemType(itemType), quality(quality), visibility(visibility) {}

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
