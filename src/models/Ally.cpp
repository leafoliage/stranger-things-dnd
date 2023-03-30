#include "Ally.h"

Ally::Ally() {}

Ally::Ally(string name, vector<string> script, int strength, int dexterity, int constitution, int wisdom): 
    GameCharacter(name, ALLY, MAX_HEALTH, MAX_HEALTH, strength, dexterity, constitution, wisdom), script(script) {}

bool Ally::triggerEvent(Object* obj) {
    // TODO
    return true;
}

void Ally::setScript(vector<string> script) {
    this->script = script;
}

vector<string> Ally::getScript() const {
    return script;
}