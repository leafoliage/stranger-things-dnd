#include <Prop.h>
#include <Player.h>

Prop::Prop() {}

Prop::Prop(string name, int quality, int visibility): 
    Item(name, ItemType::PROP, quality, visibility) {}

int Prop::useQuality(Player* p) {
    return getQuality();
}

bool Prop::triggerEvent(Object* obj) {
    Player *player = dynamic_cast<Player*>(obj);
    if (player == nullptr) return false;
    player->take(this);
    bool popped = player->getCurrentRoom()->popObject(this);
    if (popped) cout << "You picked up " << this->getName() << endl;
    return true;
}
