#include "Dungeon.h"

Dungeon::Dungeon() {}

void Dungeon::createPlayer() {
    string name;
    cout << "What's your name: ";
    getline(cin, name);
    cout << "0. Basketball Player  1. Guitarist  2. Cheerleader  3. Reporter  4. Scoops Ahoy" << endl;
    cout << "Choose your job: ";
    int job = inputNumPrompt(0,5);
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

    /*
    rooms.push_back(
        Room("Home", false, 0, vector<Object*>{
            new Ally("Nancy Wheeler", new Weapon("gun",RANGE,16,15), 
                vector<string>{"Hi!"}, 0, 4, 0, 3), 
            new Weapon("bat", WeaponType::MELEE, 20, 5)
        }, vector<string>{
            "Welcome to Hawkins", "Please find out where Eleven is"
        })
    );
    
    rooms.push_back(
        Room("School", false, 1, vector<Object*>{
            new Enemy("Demodog", new Weapon("Claw and Teeth", WeaponType::MELEE, 4, 0), 2, 2, 2, -4),
            // new Enemy("Demogorgon", new Weapon("Claw", WeaponType::MELEE, 8, 0), 2, 1, 2, -4),
            new NPC("Jim Hopper", vector<string>{"Yo kid","wacha doin"}, vector<Item*>{new Weapon("gun",WeaponType::RANGE,16,15)}),
            new Armor("Gear", 16, 10),
        }, vector<string>{
            "Hawkins High is as busy as usual,", "You see your friend Jim coming from far",
            "Jim: Yo man", "Jim: Wacha doin"
        })
    );
    
    rooms.push_back(
        Room("Lab", true, 2, vector<Object*>{
            new Enemy("Vecna", new Weapon("Superpower", WeaponType::RANGE,20,0),2,0,4,4)
        }, vector<string>{
            "You can feel it, the pressure from him",
            "He looks at you with a grim face"
        })
    );

    rooms[0].setNorthRoom(&rooms[1]);
    rooms[1].setSouthRoom(&rooms[0]);
    rooms[1].setNorthRoom(&rooms[2]);
    rooms[2].setSouthRoom(&rooms[1]);
    */
}

void Dungeon::handleMoveTo(Room* nextRoom) {
    player.setPreviousRoom(player.getCurrentRoom());
    player.setCurrentRoom(nextRoom);
    if (nextRoom->getName().length() > 0) {
        cout << "Current location: " << nextRoom->getName() << endl;
    }
}

void Dungeon::handleEvent(Object* obj) {
    obj->triggerEvent(&player);
}

void Dungeon::startGame() {
    srand(time(NULL));
    createPlayer();
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
}

void Dungeon::runRoom() {
    player.getCurrentRoom()->readPlots();
    while (checkGameLogic() && player.getCurrentRoom()->hasEnemy()) {
        cout << "Enemy detected! Fight(0) or run(1)? ";
        int run = inputNumPrompt(0,2);
        if (run) {
            cout << "Moving to previous place" << endl;
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
    }
    cout << "-----------------------" << endl;
    cout << "Where to go? ";
    int dest = inputNumPrompt(0,index);
    handleMoveTo(destination[dest]);
}

void Dungeon::chooseAction() {
    vector<Object*> objects = player.getCurrentRoom()->getObjects();

    int actionNumber=0, objectsSize = objects.size();
    cout << "------Actions------" << endl;
    for (;actionNumber<objects.size();actionNumber++) {
        if (objects[actionNumber]->getObjectType()==ObjectType::CHARACTER) {
        cout << actionNumber << ". Talk to " << objects[actionNumber]->getName() << endl;
        }
        else cout << actionNumber << ". Pick up " << objects[actionNumber]->getName() << endl;
    }
    cout << actionNumber++ << ". Move" << endl;
    cout << actionNumber++ << ". Show Status" << endl;
    cout << actionNumber++ << ". Open Backpack" << endl;
    cout << "-------------------" << endl;
    cout << "Choose action: ";

    int action = player.inputNumPrompt(0,actionNumber);
    if (action==objectsSize) chooseRoom();
    else if (action==objectsSize+1) player.triggerEvent(NULL);
    else if (action==objectsSize+2) player.listInventory();
    else handleEvent(objects[action]);
}

bool Dungeon::checkGameLogic() {
    Room* room = player.getCurrentRoom();
    return !(player.checkIsDead() || (room->getIsExit() && !room->hasEnemy()));
}

void Dungeon::runDungeon() {
    startGame();
    while (checkGameLogic()) {
        runRoom();
    }
    cout << "Gameover!" << endl;
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
