#ifndef EFFECT_H_INCLUDED
#define EFFECT_H_INCLUDED

#include <string>
#include "enums.h"
using namespace std;

class Effect {
    private:
        int time[EFFECT_AMOUNT];
        int power[EFFECT_AMOUNT];
    public:
        Effect();
        void add(int effect, int time, int power);
        int getTime(int effect);
        int getPower(int effect);
        void elapse();
        void setZero();
};

#endif // EFFECT_H_INCLUDED