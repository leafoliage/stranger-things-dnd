#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <map>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "NPC.h"
#include "Room.h"
#include "Record.h"
#include "Ally.h"
#include "Battle.h"

using namespace std;

class Dungeon{
private:
    Player player;
    // vector<Room> rooms;
    map<int,Room> rooms;
public:
    Dungeon();
    /* Create a new player, and give him/her basic status */
    void createPlayer();

    /* Create a map, which include several different rooms */
    void createMap();

    void handleMoveTo(Room* nextRoom);

    /* Deal with player's moveing action */
    void handleMovement();

    /* Deal with player's iteraction with objects in that room */
    void handleEvent(Object*);

    /* Deal with all game initial setting       */
    /* Including create player, create map etc  */
    void startGame();

    void runBattle();

    void runRoom();

    void chooseRoom();

    /* Deal with the player's action     */
    /* including showing the action list */
    /* that player can do at that room   */
    /* and dealing with player's input   */
    void chooseAction();

    /* Check whether the game should end or not */
    /* Including player victory, or he/she dead */
    bool checkGameLogic();

    /* Deal with the whole game process */
    void runDungeon();

    void testDungeon(int roomNumber, int allyNumber, int weaponNumber);

    int inputNumPrompt(int lowbound, int upbound);
};


#endif // DUNGEON_H_INCLUDED
