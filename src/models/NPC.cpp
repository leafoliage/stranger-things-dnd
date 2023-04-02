#include "NPC.h"

NPC::NPC() {}

NPC::NPC(string name, vector<string> script, vector<Item*> commodity):
    GameCharacter(name,NEUTRAL,25,25,0,0,0,0), script(script), commodity(commodity) {}

bool NPC::triggerEvent(Object* obj) {
    Player* p = dynamic_cast<Player*>(obj);
    if (!p) return false;

    for (auto it = script.begin(); it != script.end(); ++it) {
        cout << *it << endl;
    }

    int i = 0, choice;
    for (auto it = commodity.begin(); it != commodity.end(); ++it) {
        cout << i++ << ": " << (*it)->getName() << " - $" << (*it)->getPrice() << endl;
    } 
    cout << i << ": leave" << endl;

    bool deal = false;
    while (!deal) {
        cout << "Anything you want to buy? " ;
        cin >> choice;
        if (choice < 0 || choice >= commodity.size()) return false;
        deal = p->acquire(commodity[choice]);
        if (deal) commodity.erase(commodity.begin() + choice);
    }
    return true;
}

void NPC::listCommodity() {
    for (Item *i : commodity) {
        cout << i->getName() << endl;
    }
}

void NPC::setScript(vector<string> script) {
    this->script = script;
}

void NPC::setCommodity(vector<Item*> commodity) {
    this->commodity = commodity;
}

vector<string> NPC::getScript() const {
    return script;
}

vector<Item*> NPC::getCommodity() const {
    return commodity;
}
