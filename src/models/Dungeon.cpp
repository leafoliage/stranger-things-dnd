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

void Dungeon::handleEvent(Object* obj) {
    obj->triggerEvent(&player);
}

void Dungeon::startGame() {
    createPlayer();
    createMap();
    player.setCurrentRoom(&rooms[0]);
}

void Dungeon::chooseAction(vector<Object*> objects) {
    bool addEnemy = false;
    vector<Object*> actions;
    for (auto it=objects.begin();it!=objects.end();++it) {
        if ((*it)->getObjectType()==ObjectType::CHARACTER) {
            if (dynamic_cast<GameCharacter*>(*it)->getCharacterType()==CharacterType::ENEMY) {
                if (!addEnemy) actions.push_back(*it);
                addEnemy = true;
            }
            else actions.push_back(*it);
        }
        else actions.push_back(*it);
    }

    int i=0;
    cout << "------Actions------" << endl;
    for (auto it=actions.begin();it!=actions.end();++it) {
        if ((*it)->getObjectType()==ObjectType::CHARACTER) {
            cout << i++ << ". Interact with " << (*it)->getName() << endl;
        }
        else cout << i++ << ". Pick up " << (*it)->getName() << endl;
    }
    cout << "Choose action: " << endl;
    int action = player.inputNumPrompt(0,actions.size());
    handleEvent(actions[action]);
}

void Dungeon::runDungeon() {
    startGame();
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
