#ifndef SKILL_H_INCLUDED
#define SKILL_H_INCLUDED

#include <string>
#include "enums.h"
using namespace std;

class GameCharacter;

class Skill {
    private:
        int effectType;
        int elapseTime;
        int power;
        bool needCoolDown;
    public:
        Skill();
        Skill(const int settings[3]);
        Skill(int effectType,int elapseTime,int power);

        void workOn(GameCharacter*);
        bool available();
        void coolDown();
        void upgrade();
};

#endif // SKILL_H_INCLUDED