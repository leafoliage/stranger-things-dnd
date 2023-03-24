#include "Item.h"
#include "enums.h"

Item::Item() {}

Item::Item(string name, ItemType itemType, int hardness, int visibility):
    Object(name, ITEM), itemType(itemType), hardness(hardness), visibility(visibility) {}

bool Item::triggerEvent(Object*) {
    return true;
}

int Item::useHardness() {
    return hardness;
}

void Item::setItemType(ItemType itemType) {
    this->itemType = itemType;
}

void Item::setHardness(int hardness) {
    this->hardness = hardness;
}

void Item::setVisibility(int visibility) {
    this->visibility = visibility;
}

ItemType Item::getItemType() const {
    return itemType;
}

int Item::getHardness() const {
    return hardness;
}

int Item::getVisibility() const {
    return visibility;
}
