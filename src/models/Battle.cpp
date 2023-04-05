#include "Battle.h"
#include "Player.h"

Battle::Battle() {}

void Battle::add(GameCharacter* fighter) {
    int initiative = fighter->abilityCheck(Ability::DEXTERITY);
    fighters.push_back({initiative, fighter});
}

void Battle::initiate() {
    sort(fighters.begin(), fighters.end());
    cout << "------Initiative------" << endl;
    int i=0;
    for (auto it=fighters.begin();it!=fighters.end();++it) {
        cout << i << ". " << it->second->getName() << " - " << it->first << endl;
    }
    cout << "----------------------" << endl;
}

void Battle::run() {
    int number = fighters.size();
    for (int i=0; i<number; i = (i+1)%number) {
        GameCharacter *attacker = fighters[i].second, *opponent;
        if (attacker->getCharacterType() == CharacterType::PLAYER) {
            Player *p = dynamic_cast<Player*>(attacker);
            Item* weapon;
            int objectIndex;
            cout << "Who to attack (index)? ";
            objectIndex = p->inputNumPrompt(0,number);
            weapon = p->getWeapon();
            p->attack(fighters[objectIndex].second, weapon);
        } else {
            opponent = this->findOpponent(i,number);
            if (opponent == NULL) break;
            attacker->attack(opponent, attacker->getWeapon());
        }
    }
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

