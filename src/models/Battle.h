#ifndef BATTLE_H_INCLUDED
#define BATTLE_H_INCLUDED

#include <cstdlib>
#include <vector>
#include <algorithm>
#include "GameCharacter.h"
using namespace std;

class Battle {
    private:
        bool end;
        vector< pair<int,GameCharacter*> > fighters;

        GameCharacter* findOpponent(int index, int size);
    public:
        Battle();

        void add(GameCharacter* fighter);
        void initiate();
        void run();
        void terminate();
};

#endif // BATTLE_H_INCLUDED