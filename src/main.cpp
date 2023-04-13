#include <iostream>
#include <string>
#include <vector>
#include "models/Dungeon.h"
#include "models/Item.h"
#include "models/NPC.h"
#include "models/Player.h"
#include "models/Room.h"


using namespace std;

int main(){
    Dungeon dungeon = Dungeon();
    // dungeon.runDungeon();
    dungeon.testDungeon(1760,1,23);
    return 0;
}
