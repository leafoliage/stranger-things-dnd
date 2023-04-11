#include "Skill.h"
#include "GameCharacter.h"

Skill::Skill(): effectType(-1), elapseTime(0), power(0), needCoolDown(false) {}

Skill::Skill(int effectType,int elapseTime,int power):
    effectType(effectType),elapseTime(elapseTime),power(power), needCoolDown(false) {}

void Skill::workOn(GameCharacter* character) {
    if (effectType<0 || needCoolDown) return;
    character->gotEffect(effectType,elapseTime,power);
    needCoolDown = true;
}

bool Skill::available() {
    return effectType > 0 && !needCoolDown;
}

void Skill::coolDown() {
    needCoolDown = false;
}

void Skill::upgrade() {
    power++;
}
