#include "NPC.h"

NPC::NPC() {}

NPC::NPC(string name, vector<string> script, vector<Item> commodity):
    GameCharacter(name,CHARACTER,NEUTRAL,25,25,0,0,0,0), script(script), commodity(commodity) {}

bool NPC::triggerEvent(Object* obj) {
    // TODO
    return true;
}

void NPC::listCommodity() {
    for (Item i : commodity) {
        cout << i.getName() << endl;
    }
}

void NPC::setScript(vector<string> script) {
    this->script = script;
}

void NPC::setCommodity(vector<Item> commodity) {
    this->commodity = commodity;
}

vector<string> NPC::getScript() const {
    return script;
}

vector<Item> NPC::getCommodity() const {
    return commodity;
}
