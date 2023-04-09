#include "Effect.h"

Effect::Effect() {
    setZero();
}

void Effect::add(int effect, int time, int power) {
    if (effect<0 || effect>=EFFECT_AMOUNT) return;
    if (time<this->time[effect] && power<this->power[effect]) return;
    this->time[effect] = time;
    this->power[effect] = power;
}

int Effect::getTime(int effect) {
    if (effect<0 || effect>=EFFECT_AMOUNT) return 0;
    return time[effect];
}

int Effect::getPower(int effect) {
    if (effect<0 || effect>=EFFECT_AMOUNT) return 0;
    return power[effect];
}

void Effect::elapse() {
    for (int i=0;i<EFFECT_AMOUNT;i++) {
        time[i]--;
        if (time[i]==0) power[i] = 0;
    }
}

void Effect::setZero() {
    for (int i=0;i<EFFECT_AMOUNT;i++) {
        time[i] = power[i] = 0;
    }
}
