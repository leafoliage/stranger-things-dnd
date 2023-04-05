#include "Ally.h"

Ally::Ally() {}

Ally::Ally(string name, Weapon* weapon, vector<string> script, 
int strength, int dexterity, int constitution, int wisdom): 
    GameCharacter(name, ALLY, MAX_HEALTH, MAX_HEALTH, strength, dexterity, constitution, wisdom), 
    script(script), weapon(weapon) {}

bool Ally::triggerEvent(Object* obj) {
    // TODO
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