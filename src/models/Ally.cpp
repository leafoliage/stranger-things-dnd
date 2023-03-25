#include <iostream>
#include <string>
#include <vector>
#include "Ally.h"
#include "GameCharacter.h"
#include "Player.h"
#include "enums.h"

Ally::Ally() {}

Ally::Ally(string name, vector<string> script, int strength, int dexterity, int constitution, int wisdom): 
    GameCharacter(name, CHARACTER, ALLY, MAX_HEALTH, MAX_HEALTH, strength, dexterity, constitution, wisdom), script(script) {}

void Ally::setScript(vector<string> script) {
    this->script = script;
}

vector<string> Ally::getScript() const {
    return script;
}