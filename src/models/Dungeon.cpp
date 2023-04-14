#include "Dungeon.h"

Dungeon::Dungeon() {}

void Dungeon::createPlayer() {
    string name;
    cout << endl;
    cout << "------Citizen Profile------" << endl;
    cout << "Your name: ";
    getline(cin, name);
    cout << "0. Basketball Player  1. Guitarist  2. Cheerleader  3. Reporter  4. Scoops Ahoy" << endl;
    cout << "Your job: ";
    int job = inputNumPrompt(0,5);
    cout << "---------------------------" << endl;
    player = Player(name, job);
}

void Dungeon::createMap() {
    Record recorder;
    for (auto it=roomMap.begin();it!=roomMap.end();++it) {
        recorder.loadRoomFromSetting(rooms, it->first);
        RoomRecord rr = it->second;
        for (auto i = rr.characterIds.begin();i!=rr.characterIds.end();++i) {
            recorder.loadCharacterFromSetting(&rooms.at(it->first), *i);
        }
        for (auto i = rr.itemIds.begin();i!=rr.itemIds.end();++i) {
            recorder.loadItemFromSetting(&rooms.at(it->first), *i);
        }
    }

    for (auto it=rooms.begin();it!=rooms.end();++it) {
        int id = it->first;
        Room& room = it->second;
        if (id%10!=0) continue;
        if (rooms.find(id+100)!=rooms.end()) room.setNorthRoom(&rooms[id+100]);
        if (rooms.find(id-100)!=rooms.end()) room.setSouthRoom(&rooms[id-100]);
        if (rooms.find(id+10)!=rooms.end()) room.setEastRoom(&rooms[id+10]);
        if (rooms.find(id-10)!=rooms.end()) room.setWestRoom(&rooms[id-10]);
        if (rooms.find(id+1)!=rooms.end()) {
            room.setInnerRoom(&rooms[id+1]); 
            rooms[id+1].setOuterRoom(&room);
        }
    }

    for (auto it=roomRelations.begin();it!=roomRelations.end();++it) {
        int id = (*it).id;
        Room &room = rooms.at(id);
        room.setNeighborRoom(
            (*it).northId > 0 ? &rooms[(*it).northId] : room.getNorthRoom(),
            (*it).southId > 0 ? &rooms[(*it).southId] : room.getSouthRoom(),
            (*it).eastId > 0 ? &rooms[(*it).eastId] : room.getEastRoom(),
            (*it).westId > 0 ? &rooms[(*it).westId] : room.getWestRoom(),
            (*it).inId > 0 ? &rooms[(*it).inId] : room.getInnerRoom(),
            (*it).outId > 0 ? &rooms[(*it).outId] : room.getOuterRoom(),
            (*it).secretId > 0 ? &rooms[(*it).secretId] : room.getSecretRoom()
        );
    }
}

void Dungeon::handleMoveTo(Room* nextRoom) {
    player.setPreviousRoom(player.getCurrentRoom());
    player.setCurrentRoom(nextRoom);
    if (nextRoom->getName().length() > 0) {
        logf("\nCurrent Location: %s", nextRoom->getName().c_str());
    }
}

void Dungeon::handleEvent(Object* obj) {
    obj->triggerEvent(&player);
}

void Dungeon::startGame() {
    createPlayer();
    logf("\nHi, %s", player.getName().c_str());
    log("Welcome...");
    log("to Hawkins");
    createMap();
    player.setCurrentRoom(&rooms[STARTING_ROOM]);
    player.setPreviousRoom(&rooms[STARTING_ROOM]);
}

void Dungeon::runBattle() {
    Battle battle(player.getCurrentRoom());
    player.getCurrentRoom()->callEnemy(&battle);
    battle.add(&player);
    if (player.getAlly()!=NULL) battle.add(player.getAlly());
    battle.initiate();
    while (!battle.ended()) battle.run();
    player.skillCoolDown();
    if (player.getAlly()) player.getAlly()->skillCoolDown();
}

void Dungeon::runRoom() {
    player.getCurrentRoom()->readPlots();
    while (checkGameLogic() && player.getCurrentRoom()->hasEnemy()) {
        cout << endl;
        cout << "Enemy detected! Fight(0) or run(1)? ";
        int run = inputNumPrompt(0,2);
        if (run) {
            log("Moving to previous place");
            handleMoveTo(player.getPreviousRoom());
            return;
        }
        runBattle();
        if (player.getAlly() && player.getAlly()->checkIsDead()) player.setAlly(NULL);
    }
    if (!checkGameLogic()) return;
    chooseAction();
}

void Dungeon::chooseRoom() {
    Room* room = player.getCurrentRoom();
    vector<Room*> destination;

    int i=0, index=0;
    cout << endl;
    cout << "------Direction------" << endl;
    for (i=0;i<6;i++) {
        if (room->getRoom(i)==NULL) continue;
        destination.push_back(room->getRoom(i));
        cout << index++ << ". Go " << Direct[i] << " "; 
        if (room->getRoom(i)->getName().length()>0) {
            cout << "(" << room->getRoom(i)->getName() <<")";
        }
        cout << endl;
    }
    if (room->hasSecretRoom()) {
        cout << index++ << ". Wait, what's that?" << endl;
        destination.push_back(room->getSecretRoom());
    }
    cout << "-----------------------" << endl;
    cout << "Where to go? ";
    int dest = inputNumPrompt(0,index);
    handleMoveTo(destination[dest]);
}

void Dungeon::chooseAction() {
    vector<Object*> objects = player.getCurrentRoom()->getObjects();

    int actionNumber=0, objectsSize = objects.size();
    cout << endl;
    cout << "------Actions------" << endl;
    for (;actionNumber<objects.size();actionNumber++) {
        if (objects[actionNumber]->getObjectType()==ObjectType::CHARACTER) {
        cout << actionNumber << ". Talk to " << objects[actionNumber]->getName() << endl;
        }
        else cout << actionNumber << ". Pick up " << objects[actionNumber]->getName() << endl;
    }

    Room* innerRoom = player.getCurrentRoom()->getInnerRoom();
    if (innerRoom != NULL) cout << actionNumber++ << ". Go in" << endl;
    cout << actionNumber++ << ". Move" << endl;
    cout << actionNumber++ << ". Show Status" << endl;
    cout << actionNumber++ << ". Open Backpack" << endl;
    cout << "-------------------" << endl;
    cout << "Choose action: ";

    int action = player.inputNumPrompt(0,actionNumber);
    int otherChoiceStart = objectsSize + (innerRoom == NULL ? 0 : 1);
    if (innerRoom != NULL && action==objectsSize) handleMoveTo(innerRoom);
    else if (action==otherChoiceStart) chooseRoom();
    else if (action==otherChoiceStart+1) player.triggerEvent(NULL);
    else if (action==otherChoiceStart+2) player.listInventory(false);
    else handleEvent(objects[action]);
}

bool Dungeon::checkGameLogic() {
    Room* room = player.getCurrentRoom();
    return !(player.checkIsDead() || (room->getIsExit() && !room->hasEnemy()));
}

void Dungeon::runDungeon() {
    log(" _______ _________ ______   _        ______  \n(  ____ \\__   __/(  __  \\ ( (    /|(  __  \\ \n| (    \\/   ) (   | (  \\  )|  \\  ( || (  \\  )\n| (_____    | |   | |   ) ||   \\ | || |   ) |\n(_____  )   | |   | |   | || (\\ \\) || |   | |\n      ) |   | |   | |   ) || | \\   || |   ) |\n/\\____) |   | |   | (__/  )| )  \\  || (__/  )\n\\_______)   )_(   (______/ |/    )_)(______/ \n");
    log("A fangame for the Stranger Things Series");
    log("\nAlso a DSOOP midterm project");
    pause(1000);
    clearScreen();
    startGame();
    clearScreen();
    pause(1000);
    while (checkGameLogic()) {
        runRoom();
    }
    log("Gameover!");
    whiteText();
}

void Dungeon::testDungeon(int roomNumber, int allyNumber, int weaponNumber) {
    Record recorder;
    createPlayer();

    auto rit = roomMap.find(roomNumber);
    if (rit==roomMap.end()) return;
    const RoomRecord &rr = rit->second;
    recorder.loadRoomFromSetting(rooms, rit->first);
    for (auto i = rr.characterIds.begin();i!=rr.characterIds.end();++i) {
        recorder.loadCharacterFromSetting(&rooms.at(rit->first), *i);
    }
    for (auto i = rr.itemIds.begin();i!=rr.itemIds.end();++i) {
        recorder.loadItemFromSetting(&rooms.at(rit->first), *i);
    }

    auto ait = characterMap.find(allyNumber);
    if (ait==characterMap.end()) return;
    const CharaterRecord &cr = ait->second;
    player.setAlly(new Ally(cr.name,{},cr.hp,cr.abilities,Skill(cr.skill)));
    recorder.loadWeaponForAlly(player.getAlly(),cr.weaponId);

    auto wit = itemMap.find(weaponNumber);
    if (wit==itemMap.end()) return;
    const ItemRecord &ir = wit->second;
    player.take(new Weapon(ir.name,ir.type-ITEM*TYPE_BOUND,ir.quality,ir.price));
    
    player.setCurrentRoom(&rooms[roomNumber]);
    player.setPreviousRoom(&rooms[roomNumber]);
    while (checkGameLogic()) {
        runRoom();
    }
    whiteText();
}

int Dungeon::inputNumPrompt(int lowbound, int upbound) {
    int input;
    cin >> input;
    while (input<lowbound || input>=upbound) {
        cout << "Choice out of range! Choose again: ";
        cin >> input;
    }
    getchar();
    return input;
}
