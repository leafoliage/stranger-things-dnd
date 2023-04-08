#include "Ally.h"

Ally::Ally() {}

Ally::Ally(string name, Weapon* weapon, vector<string> script, 
int strength, int dexterity, int constitution, int wisdom): 
    GameCharacter(name, ALLY, MAX_HEALTH, MAX_HEALTH, strength, dexterity, constitution, wisdom), 
    script(script), weapon(weapon) {}

bool Ally::triggerEvent(Object* obj) {
    Player* p = dynamic_cast<Player*>(obj);
    if (!p) return false;

    for (auto it = script.begin(); it != script.end(); ++it) {
        cout << *it << endl;
    }
    cout << "Wanna team up with me? (Y/n) ";
    bool teamUp = p->inputBoolPrompt();
    if (teamUp) {
        if (p->getAlly() != NULL) p->getCurrentRoom()->add(p->getAlly());
        p->setAlly(this);
        p->getCurrentRoom()->remove(this);
        cout << "Tatakai! My friend" << endl;
    } else {
        cout << "Alright. Bye" << endl;
    }
    return true;
}

Item* Ally::getWeapon() {
    return weapon;
}

void Ally::setScript(vector<string> script) {
    this->script = script;
}

vector<string> Ally::getScript() const {
    return script;
}