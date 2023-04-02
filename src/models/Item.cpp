#include "Item.h"
#include "GameCharacter.h"

Item::Item() {}

Item::Item(string name, int itemType, int quality, int price):
    Object(name, ITEM), itemType(itemType), quality(quality), price(price) {}

int Item::useQuality(GameCharacter* user) {
    return quality;
}

void Item::setItemType(int itemType) {
    this->itemType = itemType;
}

void Item::setQuality(int quality) {
    this->quality = quality;
}

void Item::setPrice(int price) {
    this->price = price;
}

int Item::getItemType() const {
    return itemType;
}

int Item::getQuality() const {
    return quality;
}

int Item::getPrice() const {
    return price;
}
