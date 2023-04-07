#include "Battle.h"
#include "Player.h"

Battle::Battle(): end(false) {
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

bool cmp(pair<int,GameCharacter*> a, pair<int,GameCharacter*> b) {
    return a.first > b.first;
}

void Battle::initiate() {
    sort(fighters.begin(), fighters.end(), cmp);
    showFighters(true);
}

void Battle::showFighters(bool initiative) {
    if (initiative) cout << "------Initiative------" << endl;
    else cout << "------Fighter Hp------" << endl;
    int i=0;
    for (auto it=fighters.begin();it!=fighters.end();++it) {
        cout << i++ << ". " << it->second->getName();
        if (initiative) cout << " - " << it->first << endl;
        else cout << ": " << it->second->getCurrHp() << endl;
    }
    cout << "----------------------" << endl;
}

void Battle::run() {
    for (auto it=fighters.begin();it!=fighters.end();++it) {
        GameCharacter *attacker = it->second, *opponent;
        if (attacker->getCharacterType() == CharacterType::PLAYER) {
            cout << "Your turn!" << endl;
            showFighters(false);
            cout << "Choose your target (index), or input -1 to retreat: ";
            
            int objectIndex = dynamic_cast<Player*>(attacker)->inputNumPrompt(-1,fighterNumber);
            if (objectIndex<0) {
                cout << "Guys! Retreat!" << endl;
                terminate();
                break;
            }
            opponent = fighters[objectIndex].second;
        } else {
            opponent = this->findOpponent(attacker, it->first);
            if (opponent == NULL) break;
        }
        bool dead = attacker->attack(opponent, attacker->getWeapon());
        if (dead) removeFighter(opponent);
        if (end) break;
    }
}

void Battle::removeFighter(GameCharacter* fighter) {
    int goodCount = 0, badCount = 0;
    if (!fighter->checkIsDead()) return;
    if (fighter->getCharacterType() == CharacterType::PLAYER) {
        cout << "You died! Game over" << endl;
        end = true;
        return;
    }

    bool found = false;
    auto it=fighters.begin(), target = fighters.begin();
    for (;it!=fighters.end();++it) {
        if (it->second == fighter) {
            found = true;
            target = it;
            fighterNumber--;
        } else {
            if (it->second->getCharacterType() >= CharacterType::ENEMY) badCount++;
            else goodCount++;
        }
    }
    if (found) {
        cout << fighter->getName() << " died!" << endl;
        fighters.erase(target);
    }
    if (!goodCount || !badCount) end = true;
}

void Battle::terminate() {
    end = true;
}

GameCharacter* Battle::findOpponent(GameCharacter* fighter, int initiative) {
    GameCharacter *opponent = NULL;
    int minScore=INT32_MAX;
    for (auto it=fighters.begin();it!=fighters.end();++it) {
        if (fighter->hostile(it->second)) {
            int score = it->first-initiative;
            if (score<0) score = -score;
            if (score < minScore) {
                opponent = it->second;
                minScore = score;
            }
        }
    }
    return opponent;
}

bool Battle::ended() const {
    return end;
}
