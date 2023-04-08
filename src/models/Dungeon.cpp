#include "Dungeon.h"

Dungeon::Dungeon() {}

void Dungeon::createPlayer() {
    string name;
    cout << "What's your name: ";
    cin >> name;
    cout << "0. Basketball Player  1. Guitarist  2. Cheerleader  3. Reporter  4. Scoops Ahoy" << endl;
    cout << "Choose your job: ";
    int job = inputNumPrompt(0,5);
    player = Player(name, job);
}

void Dungeon::createMap() {
    Weapon bat("bat", WeaponType::MELEE, 12, 5);
    Room r0("Home", false, 0, vector<Object*>{&bat});
    
    Armor gear("Gear", 16, 10);
    Enemy demodog("Demodog", new Weapon("Claw and Teeth", WeaponType::MELEE, 16, 0), 4, 4, 2, -4);
    Enemy demogorgon("Demogorgon", new Weapon("Claw", WeaponType::MELEE, 16, 0), 4, 2, 2, -4);
    NPC jim("Jim Hopper", vector<string>{"Yo kid","wacha doin"}, vector<Item*>{new Weapon("gun",WeaponType::RANGE,16,15)});
    Room r1("School", false, 1, vector<Object*>{&demodog, &demogorgon, &jim, &gear});

    Enemy vecna("Vecna", new Weapon("Superpower", WeaponType::RANGE,20,0),2,0,4,4);
    Room r2("Lab", true, 2, vector<Object*>{&vecna});

    r0.setNorthRoom(&r1);
    r1.setNorthRoom(&r2);

    rooms = vector<Room>{r0,r1,r2};
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
    Battle battle;
    player.getCurrentRoom()->callEnemy(&battle);
    battle.add(&player);
    battle.initiate();
    while (!battle.ended()) battle.run();
}

void Dungeon::runRoom() {
    while (player.getCurrentRoom()->hasEnemy()) {
        cout << "Enemy detected! Fight(0) or run(1)? " << endl;
        int run = inputNumPrompt(0,2);
        if (run) {
            handleMoveTo(player.getPreviousRoom());
            return;
        }
        runBattle();
    }
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
    // vector<Object*> actions, objects=room->getObjects();
    vector<Object*> actions=room->getObjects();

    // bool addEnemy = false;
    // for (auto it=objects.begin();it!=objects.end();++it) {
    //     if ((*it)->getObjectType()==ObjectType::CHARACTER) {
    //         if (dynamic_cast<GameCharacter*>(*it)->getCharacterType()==CharacterType::ENEMY) {
    //             if (!addEnemy) actions.push_back(*it);
    //             addEnemy = true;
    //         }
    //         else actions.push_back(*it);
    //     }
    //     else actions.push_back(*it);
    // }

    int i=0;
    cout << "------Actions------" << endl;
    for (auto it=room->getObjects().begin();it!=room->getObjects().end();++it) {
        if ((*it)->getObjectType()==ObjectType::CHARACTER) {
            cout << i++ << ". Interact with " << (*it)->getName() << endl;
        }
        else cout << i++ << ". Pick up " << (*it)->getName() << endl;
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
