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
            int objectIndex, itemIndex;
            cout << "Choose your object (index): ";
            objectIndex = p->inputNumPrompt(0,number);
            p->listInventory();
            cout << "What item do you want to use? ";
            itemIndex = p->inputNumPrompt(0,p->getInventory().size());
            p->attack(fighters[objectIndex].second, p->getInventory()[itemIndex]);
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

