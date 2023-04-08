#ifndef BATTLE_H_INCLUDED
#define BATTLE_H_INCLUDED

#include <cstdlib>
#include <vector>
#include <algorithm>
#include "GameCharacter.h"
using namespace std;

class Room;

class Battle {
    private:
        bool end;
        int fighterNumber;
        Room* room;
        vector< pair<int,GameCharacter*> > fighters;

        GameCharacter* findOpponent(GameCharacter* fighter, int initiative);
    public:
        Battle();
        Battle(Room*);

        void add(GameCharacter* fighter);
        void initiate();
        void showFighters(bool initiative);
        void run();
        void removeFighter(GameCharacter* fighter);
        void terminate();

        bool ended() const;
};

#endif // BATTLE_H_INCLUDED