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
    rooms.push_back(
        Room("Home", false, 0, vector<Object*>{
            new Weapon("bat", WeaponType::MELEE, 20, 5)
        })
    );
    
    rooms.push_back(
        Room("School", false, 1, vector<Object*>{
            new Enemy("Demodog", new Weapon("Claw and Teeth", WeaponType::MELEE, 4, 0), 2, 2, 2, -4),
            // new Enemy("Demogorgon", new Weapon("Claw", WeaponType::MELEE, 8, 0), 2, 1, 2, -4),
            new NPC("Jim Hopper", vector<string>{"Yo kid","wacha doin"}, vector<Item*>{new Weapon("gun",WeaponType::RANGE,16,15)}),
            new Armor("Gear", 16, 10),
        })
    );
    
    rooms.push_back(
        Room("Lab", true, 2, vector<Object*>{
            new Enemy("Vecna", new Weapon("Superpower", WeaponType::RANGE,20,0),2,0,4,4)
        })
    );

    rooms[0].setNorthRoom(&rooms[1]);
    rooms[1].setSouthRoom(&rooms[0]);
    rooms[1].setNorthRoom(&rooms[2]);
    rooms[2].setSouthRoom(&rooms[1]);
}

void Dungeon::handleMoveTo(Room* nextRoom) {
    player.setPreviousRoom(player.getCurrentRoom());
    player.setCurrentRoom(nextRoom);
}

void Dungeon::handleEvent(Object* obj) {
    obj->triggerEvent(&player);
}

void Dungeon::startGame() {
    createPlayer();
    createMap();
    player.setCurrentRoom(&rooms[0]);
    player.setPreviousRoom(&rooms[0]);
}

void Dungeon::runBattle() {
    Battle battle(player.getCurrentRoom());
    player.getCurrentRoom()->callEnemy(&battle);
    battle.add(&player);
    battle.initiate();
    while (!battle.ended()) battle.run();
}

void Dungeon::runRoom() {
    while (checkGameLogic() && player.getCurrentRoom()->hasEnemy()) {
        cout << "Enemy detected! Fight(0) or run(1)? ";
        int run = inputNumPrompt(0,2);
        if (run) {
            handleMoveTo(player.getPreviousRoom());
            return;
        }
        runBattle();
    }
    if (!checkGameLogic()) return;
    chooseAction();
}

void Dungeon::chooseRoom() {
    Room* room = player.getCurrentRoom();
    vector<Room*> destination;

    int i=0;
    cout << "------Direction------" << endl;
    if (room->getNorthRoom()!=NULL) {
        destination.push_back(room->getNorthRoom());
        cout << i++ << ". Go North" << endl;
    }
    if (room->getSouthRoom()!=NULL) {
        destination.push_back(room->getSouthRoom());
        cout << i++ << ". Go South" << endl;
    }
    if (room->getEastRoom()!=NULL) {
        destination.push_back(room->getEastRoom());
        cout << i++ << ". Go East" << endl;
    }
    if (room->getWestRoom()!=NULL) {
        destination.push_back(room->getWestRoom());
        cout << i++ << ". Go West" << endl;
    }
    if (room->getInnerRoom()!=NULL) {
        destination.push_back(room->getInnerRoom());
        cout << i++ << ". Go Inner" << endl;
    }
    if (room->getOuterRoom()!=NULL) {
        destination.push_back(room->getOuterRoom());
        cout << i++ << ". Go Outer" << endl;
    }
    cout << "-----------------------" << endl;
    cout << "Where to go? ";
    int dest = inputNumPrompt(0,i);
    handleMoveTo(destination[dest]);
}

void Dungeon::chooseAction() {
    Room* room = player.getCurrentRoom();
    vector<Object*> actions=room->getObjects();

    int i=0;
    cout << "------Actions------" << endl;
    for (;i<room->getObjects().size();i++) {
        if ((room->getObjects()[i])->getObjectType() ==ObjectType::CHARACTER) {
        cout << i << ". Interact with " << (room->getObjects()[i])->getName() << endl;
        }
        else cout << i << ". Pick up " << (room->getObjects()[i])->getName() << endl;
    }
    cout << i << ". Move on to other place" << endl;
    cout << "-------------------" << endl;
    cout << "Choose action: ";

    int action = player.inputNumPrompt(0,actions.size()+1);
    if (action>=actions.size()) chooseRoom();
    else handleEvent(actions[action]);
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
