#include "Battle.h"
#include "Player.h"

Battle::Battle(): end(false) {
    log("A battle begins...");
}

Battle::Battle(Room* room): end(false), room(room) {
    log("A battle begins...");
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
    pause(1000);
    log("Battle starts!");
}

void Battle::showFighters(bool initiative) {
    cout << endl;
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
        GameCharacter *attacker = it->second, *target;
        if (attacker->hasEffect(CLOCKED) && attacker->getEffect(CLOCKED)==1) {
            fighters.erase(it);
            attacker = it->second;
        }

        if (attacker->hasEffect(CURED)) attacker->setCurrHp(attacker->getCurrHp() + attacker->getEffect(CURED));

        if (attacker->getCharacterType() == CharacterType::PLAYER) {
            bool roundEnd = false;
            Player *player = dynamic_cast<Player*>(attacker);
            log("Your turn!", 1000);

            while (!roundEnd) {
                int action = chooseAction(player);

                if (action==RETREAT) return terminate(false);

                target = chooseTarget(player);

                if (action==ATTACK) {
                    bool dead = attacker->attack(target, attacker->getWeapon());
                    if (dead) removeFighter(target);
                    roundEnd = true;
                }
                else if (action==USESKILL) {
                    player->useSkillOn(target);
                }
            }
        } else {
            target = this->findOpponent(attacker, it->first);
            if (target == NULL) break;
            if (attacker->wantUseSkill()) {
                if (attacker->getCharacterType() == ENEMY) attacker->useSkillOn(target);
                else if (attacker->hasSkill(ATTRACT_FIRE)) attacker->useSkillOn(attacker);
                else attacker->useSkillOn(findPlayer());
            }
            bool dead = attacker->attack(target, attacker->getWeapon());
            if (dead) removeFighter(target);
        }

        attacker->effectElapse();

        if (end) {
            log("The battle is over", 1000);
            break;
        }

        log("");
    }
}

int Battle::chooseAction(Player* player) {
    cout << endl;
    cout << "------Actions------" << endl;
    int i=0;
    for (;i<2;i++) {
        cout << i << ". " << battleActions[i] << endl;
    }
    if (player->skillAvailable()) cout << i++ << ". Use skill: " << player->getSkillName() << endl;
    cout << "-------------------" << endl;
    cout << "Choose your action: ";
    return player->inputNumPrompt(0,i);
}

GameCharacter* Battle::chooseTarget(Player* player) {
    showFighters(false);
    cout << "Choose your target (index): ";
    int objectIndex = player->inputNumPrompt(0,fighterNumber);
    return fighters[objectIndex].second;
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
    if (found) {\
        logf("%s died!", fighter->getName().c_str());
        fighters.erase(target);
        room->remove(fighter);
        if (fighter->getType() == tALLY) room->add(fighter->getWeapon());
    }
    if (!goodCount || !badCount) end = true;
}

void Battle::terminate(bool lose) {
    if (lose) log("You died!");
    else log("Guys! Retreat!");
    end = true;
    return;
}

GameCharacter* Battle::findOpponent(GameCharacter* fighter, int initiative) {
    GameCharacter *target = NULL;
    int minScore=INT32_MAX;
    for (auto it=fighters.begin();it!=fighters.end();++it) {
        if (fighter->hostile(it->second)) {
            if (it->second->hasEffect(ATTRACT_FIRE)) return it->second;
            int score = it->first-initiative;
            if (score<0) score = -score;
            if (score < minScore) {
                target = it->second;
                minScore = score;
            }
        }
    }
    return target;
}

GameCharacter* Battle::findPlayer() {
    for (pair<int,GameCharacter*> it : fighters) {
        if (it.second->getCharacterType() == PLAYER) {
            return it.second;
        }
    }
    return NULL;
}

bool Battle::ended() const {
    return end;
}
