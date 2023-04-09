#include "Battle.h"
#include "Player.h"

Battle::Battle(): end(false), attraction(NULL) {
    cout << "A battle begins..." << endl;
}

Battle::Battle(Room* room): end(false), room(room), attraction(NULL) {
    cout << "A battle begins..." << endl;
}

void Battle::add(GameCharacter* fighter) {
    if (fighter->getCharacterType() == CharacterType::PLAYER) {
        cout << "Initiate!" << endl << "Roll your initiative. ";
    }
    int initiative = fighter->abilityCheck(Ability::DEXTERITY);
    fighters.push_back({initiative, fighter});
    fighterNumber++;
    fighter->skillCoolDown();
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
        if (attacker->hasEffect(CLOCKED) && attacker->getEffect(CLOCKED)==1) {
            fighters.erase(it);
            attacker = it->second;
        }

        if (attraction == attacker) attraction = NULL;
        if (attacker->hasEffect(CURED)) attacker->setCurrHp(attacker->getCurrHp() + attacker->getEffect(CURED));
        
        if (attacker->getCharacterType() == CharacterType::PLAYER) {
            Player *player = dynamic_cast<Player*>(attacker);
            cout << "Your turn!" << endl;

            if (player->wantUseSkill()) {
                showFighters(false);
                cout << "Choose your target (index): ";
                int objectIndex = player->inputNumPrompt(-1,fighterNumber);
                GameCharacter* target = fighters[objectIndex].second;
                player->useSkillOn(target);
                if (target->hasEffect(ATTRACT_FIRE)) attraction = target;
            }

            showFighters(false);
            cout << "Choose your target (index), or input -1 to retreat: ";
            
            int objectIndex = player->inputNumPrompt(-1,fighterNumber);
            if (objectIndex<0) return terminate(false);
            opponent = fighters[objectIndex].second;
        } else {
            opponent = this->findOpponent(attacker, it->first);
            if (opponent == NULL) break;
            if (attacker->wantUseSkill()) attacker->useSkillOn(opponent);
        }

        bool dead = attacker->attack(opponent, attacker->getWeapon());
        if (dead) removeFighter(opponent);

        attacker->effectElapse();

        if (end) {
            cout << "The battle is over" << endl;
            break;
        }
    }
}

void Battle::removeFighter(GameCharacter* fighter) {
    int goodCount = 0, badCount = 0;
    if (!fighter->checkIsDead()) return;
    if (fighter->getCharacterType() == CharacterType::PLAYER) return terminate(true);

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
        room->remove(fighter);
    }
    if (!goodCount || !badCount) end = true;
}

void Battle::terminate(bool lose) {
    if (lose) cout << "You died!" << endl;
    else cout << "Guys! Retreat!" << endl;
    end = true;
    return;
}

GameCharacter* Battle::findOpponent(GameCharacter* fighter, int initiative) {
    if (attraction != NULL) return attraction;
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
