#include "NPC.h"

NPC::NPC() {}

NPC::NPC(string name, vector<string> script, vector<Item*> commodity):
    GameCharacter(name,CHARACTER,NEUTRAL,25,25,0,0,0,0), script(script), commodity(commodity) {}

bool NPC::triggerEvent(Object* obj) {
    Player* p = dynamic_cast<Player*>(obj);

    for (auto it = script.begin(); it != script.end(); ++it) {
        cout << *it << endl;
    }
    int i = 0, choice;
    for (auto it = commodity.begin(); it != commodity.end(); ++it) {
        cout << i++ << " " << (*it)->getName() << endl;
    } 
    cout << "What do you want to buy? " ;
    cin >> choice;
    if (choice >=0 && choice < commodity.size()) {
        switch (commodity[choice]->getItemType()) {
        case ItemType::PROP: {
            p->addItem(commodity[choice]);
            break;
        }
        case ItemType::ARMOR: {
            Armor* arm = dynamic_cast<Armor*>(commodity[choice]);
            p->addArmor(arm);
            break;
        }
        case ItemType::WEAPON: {
            Weapon* wep = dynamic_cast<Weapon*>(commodity[choice]);
            p->addWeapon(wep);
            break;
        }
        default:
            break;
        }
        cout << "You got a " << commodity[choice]->getName() << " from " << this->getName() << "!" << endl;
        commodity.erase(commodity.begin() + choice);
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
