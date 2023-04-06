#include "Battle.h"
#include "Player.h"

Battle::Battle() {
    cout << "A battle begins..." << endl;
}

void Battle::add(GameCharacter* fighter) {
    if (fighter->getCharacterType() == CharacterType::PLAYER) {
        cout << "Initiate!" << endl << "Roll your initiative. " << endl;
    }
    int initiative = fighter->abilityCheck(Ability::DEXTERITY);
    fighters.push_back({initiative, fighter});
    fighterNumber++;
}

void Battle::initiate() {
    sort(fighters.begin(), fighters.end());
    showInitiative();
}

void Battle::showInitiative() {
    cout << "------Initiative------" << endl;
    int i=0;
    for (auto it=fighters.begin();it!=fighters.end();++it) {
        cout << i++ << ". " << it->second->getName() << " - " << it->first;
        cout << "(" << it->second->getCurrHp() << ")" << endl;
    }
    cout << "----------------------" << endl;
}

void Battle::run() {
    for (auto it=fighters.begin();it!=fighters.end();++it) {
        GameCharacter *attacker = it->second, *opponent;
        if (attacker->getCharacterType() == CharacterType::PLAYER) {
            cout << "Your turn!" << endl;
            showInitiative();
            cout << "Choose your target (index), or input -1 to retreat: ";
            
            int objectIndex = dynamic_cast<Player*>(attacker)->inputNumPrompt(-1,fighterNumber);
            if (objectIndex<0) {
                cout << "Guys! Retreat!" << endl;
                terminate();
                break;
            }
            opponent = fighters[objectIndex].second;
        } else {
            opponent = this->findOpponent(it-fighters.begin(),fighterNumber);
            if (opponent == NULL) break;
        }
        bool dead = attacker->attack(opponent, attacker->getWeapon());
        if (dead) removeFighter(opponent);
        if (end) break;
    }
}

void Battle::removeFighter(GameCharacter* fighter) {
    cout << "Removing " << fighter->getName() << endl;;
    int goodCount = 0, badCount = 0;
    if (!fighter->checkIsDead()) return;
    if (fighter->getCharacterType() == CharacterType::PLAYER) {
        cout << "You died! Game over" << endl;
        end = true;
        return;
    }
    auto it=fighters.begin(), target = fighters.begin();
    for (;it!=fighters.end();++it) {
        if (it->second == fighter) {
            target = it;
            fighterNumber--;
        } else {
            if (it->second->getCharacterType() >= CharacterType::ENEMY) badCount++;
            else goodCount++;
        }
    }
    fighters.erase(it);
    if (!goodCount || !badCount) end = true;
}

void Battle::terminate() {
    end = true;
}

GameCharacter* Battle::findOpponent(int startIndex, int size) {
    GameCharacter *fighter = fighters[startIndex].second, *opponent;
    for (int i=startIndex+1;i!=startIndex;i = (i+1)%size) {
        opponent = fighters[i].second;
        if (fighter->hostile(opponent)) return opponent;
    }
    return NULL;
}

bool Battle::ended() const {
    return end;
}
