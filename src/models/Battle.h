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
        int fighterNumber;
        vector< pair<int,GameCharacter*> > fighters;

        GameCharacter* findOpponent(int index, int size);
    public:
        Battle();

        void add(GameCharacter* fighter);
        void initiate();
        void showInitiative();
        void run();
        void removeFighter(GameCharacter* fighter);
        void terminate();

        bool ended() const;
};

#endif // BATTLE_H_INCLUDED