#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <limits>
#include "Item.h"
#include "Enemy.h"
#include "NPC.h"
#include "Player.h"
#include "Ally.h"
#include "NPC.h"
#include "Prop.h"
#include "settings.h"

using namespace std;

/* This is the record system. Get the information of the  */
/* player and rooms then save them to (a) file(s). Notice */
/* that using pass by reference can prevent sending the   */
/* whole vector to the function.                          */

class Record
{
private:
    void savePlayer(Player*, ofstream&);
    void saveRooms(vector<Room>&, ofstream&);
    void loadPlayer(Player*, ifstream&);
    void loadRooms(vector<Room>&, ifstream&);

    vector<string> loadPlotFromSetting(int id);
    vector<string> loadScriptFromSetting(int id);
    void loadCommodityFromSetting(NPC *npc, int id);

public:
    Record();
    void saveToFile(Player*, vector<Room>&);
    void loadFromFile(Player*, vector<Room>&);
    void loadRoomFromSetting(map<int,Room> &rooms, int id);
    void loadItemFromSetting(Room *room, int id);
    // void loadItemFromSetting(Ga, int id);
    void loadCharacterFromSetting(Room *room, int id);

};

#endif // RECORD_H_INCLUDED
