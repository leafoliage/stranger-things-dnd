#include "Ally.h"

Ally::Ally() {}

Ally::Ally(string name, vector<string> script, int hp, const int abilities[4], Skill skill):
    GameCharacter(name, ALLY, hp, hp, abilities[0], abilities[1], abilities[2], abilities[3], skill),
    script(script) {}

Ally::Ally(string name, Weapon* weapon, vector<string> script, 
int strength, int dexterity, int constitution, int wisdom): 
    GameCharacter(name, ALLY, MAX_HEALTH, MAX_HEALTH, strength, dexterity, constitution, wisdom), 
    script(script), weapon(weapon) {}

bool Ally::triggerEvent(Object* obj) {
    Player* p = dynamic_cast<Player*>(obj);
    if (!p) return false;

    for (auto it = script.begin()+1; it != script.end(); ++it) {
        log(*it);
    }
    cout << "Wanna team up with me? ($10) (Y/n) ";
    bool teamUp = p->inputBoolPrompt();
    if (teamUp && p->pay(10)) {
        if (p->getAlly() != NULL) p->getCurrentRoom()->add(p->getAlly());
        p->setAlly(this);
        p->getCurrentRoom()->remove(this);
        log(script[0]);
    } else {
        log("Alright. Bye");
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

void Ally::setWeapon(Weapon* weap) {
    weapon = weap;
}
