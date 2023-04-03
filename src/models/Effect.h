#ifndef EFFECT_H_INCLUDED
#define EFFECT_H_INCLUDED

#include <string>
using namespace std;

class Effect {
    private:
        string name;
        int effectType;
        int level;
        int time;

    public:
        Effect();
        Effect(string name, int effectType, int level, int time);
};

#endif // EFFECT_H_INCLUDED