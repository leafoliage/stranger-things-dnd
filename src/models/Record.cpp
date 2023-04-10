#include "Record.h"

Record::Record(){}

void Record::savePlayer(Player* player, ofstream& file) {
    // Save player information to file
    file << player->getName() << endl;
    file << player->getJob() << endl;
    file << player->getStrength() << endl;
    file << player->getDexterity() << endl;
    file << player->getConstitution() << endl;
    file << player->getWisdom() << endl;
    file << player->getCurrentRoom()->getIndex() << endl;
    file << player->getMoney() << endl;

    // Save player's inventory items to file
    vector<Item*> inventory = player->getInventory();
    int numItems = inventory.size();
    file << numItems << endl;
    for (int i = 0; i < numItems; i++) {
        file << inventory[i]->getName() << endl;
        file << inventory[i]->getType() << endl;
        file << inventory[i]->getQuality() << endl;
        file << inventory[i]->getPrice() << endl;
    }

    // Save player's equipped armor to file
    Armor* armor = player->getArmor();
    if (armor != nullptr) {
        file << armor->getName() << endl;
        file << armor->getQuality() << endl;
        file << armor->getPrice() << endl;
    }
}

void Record::saveRooms(vector<Room>& rooms, ofstream& file) {
    // Save room information to file
    int numRooms = rooms.size();
    file << numRooms << endl;
    for (int i = 0; i < numRooms; i++) {
        file << rooms[i].getName() << endl;
        file << rooms[i].getIsExit() << endl;
        file << rooms[i].hasSecretRoom() << endl;
        file << rooms[i].getIndex() << endl;
        file << rooms[i].revealSecret << endl;
        file << rooms[i].visited << endl;

        // Save room objects to file
        vector<Object*> objects = rooms[i].getObjects();
        int numObjects = objects.size();
        file << numObjects << endl;
        for (int j = 0; j < numObjects; j++) {
            file << objects[j]->getName() << endl;
            file << objects[j]->getType() << endl;
        }

        // Save neighbor room indices to file
        // file << rooms[i].getNorthRoomIndex() << endl;
        // file << rooms[i].getSouthRoomIndex() << endl;
        // file << rooms[i].getWestRoomIndex() << endl;
        // file << rooms[i].getEastRoomIndex() << endl;
        // file << rooms[i].getInnerRoomIndex() << endl;
        // file << rooms[i].getOuterRoomIndex() << endl;
        // file << rooms[i].getSecretRoomIndex() << endl;
    }
}

void Record::loadPlayer(Player* player, ifstream& inFile) {
    string name;
    int job, strength, dexterity, constitution, wisdom, currentRoomIndex, money, inventorySize;
    string itemName, armorName, allyName;

    // Load player's attributes from the input file
    getline(inFile, name);
    inFile >> job;
    inFile >> strength;
    inFile >> dexterity;
    inFile >> constitution;
    inFile >> wisdom;
    inFile >> currentRoomIndex;
    inFile >> money;
    inFile >> inventorySize;
    inFile.ignore(numeric_limits<streamsize>::max(), '\n');

    player->setName(name);
    player->job = job;
    player->setStrength(strength);
    player->setDexterity(dexterity);
    player->setConstitution(constitution);
    player->setWisdom(wisdom);
    // player->setCurrentRoomIndex(currentRoomIndex);
    player->setMoney(money);

    // Load player's inventory from the input file
    for (int i = 0; i < inventorySize; i++)
    {
        int type, quality, price;
        getline(inFile, itemName);
        cin >> type;
        cin >> quality;
        cin >> price;
        // Item* item = new Item(itemName);
        // player->getInventory().push_back(item);
    }

    // Load player's equipped armor from the input file
    getline(inFile, armorName);
    if (armorName != "None")
    {  
        int quality, price;
        cin >> quality >> price;
        Armor* armor = new Armor(armorName,quality,price);
        player->wear(armor);
    }

    // Load player's ally from the input file
    getline(inFile, allyName);
    if (allyName != "None")
    {
        // Ally* ally = new Ally(allyName,);
        // player->setAlly(ally);
    }
}

void Record::loadRooms(vector<Room>& rooms, ifstream& inFile) {
    int numRooms;
    inFile >> numRooms;
    inFile.ignore(numeric_limits<streamsize>::max(), '\n');

    // Load each room's attributes from the input file
    for (int i = 0; i < numRooms; i++)
    {
        string name;
        bool isExit;
        int index;
        bool revealSecret;
        int numObjects;
        string objName;

        getline(inFile, name);
        inFile >> isExit;
        inFile >> index;
        inFile >> revealSecret;
        inFile >> numObjects;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');

        Room room(name, isExit, index, vector<Object*>{}, vector<string>{});

        // Load each room's objects from the input file
        for (int j = 0; j < numObjects; j++)
        {
            getline(inFile, objName);
            // Object* obj = new Object(objName);
            // room.addObject(obj);
        }

        rooms.push_back(room);
    }
}

void Record::loadItemFromSetting(Room *room, int id) {
    auto it = itemMap.find(id);
    if (it==itemMap.end()) return;
    ItemRecord ir = it->second;
    switch(ir.type) {
        case tMELEE: 
            return room->add(new Weapon(ir.name,MELEE,ir.quality,ir.price));
        case tRANGE: 
            return room->add(new Weapon(ir.name,RANGE,ir.quality,ir.price));
        case tARMOR: 
            return room->add(new Armor(ir.name,ir.quality,ir.price));
        case tPROP: 
            return room->add(new Prop(ir.name,ir.quality,ir.price));
    }
}

void Record::loadCharacterFromSetting(Room *room, int id) {
    auto it = characterMap.find(id);
    if (it==characterMap.end()) return;
    CharaterRecord cr = it->second;
    // Weapon *weap = dynamic_cast<Weapon*>(loadItemFromSetting(cr.weaponId));
    switch(cr.characterType) {
        case ALLY:
            return room->add(new Ally(cr.name,NULL,loadScriptFromSetting(id),cr.strength,cr.dexterity,cr.constitution,cr.wisdom));
        case ENEMY: 
            return room->add(new Enemy(cr.name,NULL,cr.strength,cr.dexterity,cr.constitution,cr.wisdom));
        case NEUTRAL:
            NPC *npc = new NPC(cr.name,loadScriptFromSetting(id));
            loadCommodityFromSetting(npc,id);
            room->add(npc);
            return;
    }
}

void Record::loadRoomFromSetting(map<int,Room> &rooms, int id) {
    auto it = roomMap.find(id);
    if (it==roomMap.end()) return ;
    RoomRecord rr = it->second;
    rooms.insert({id, Room(rr.name, rr.isExit, it->first,loadPlotFromSetting(id))});
    return;
}

vector<string> Record::loadPlotFromSetting(int id) {
    auto it = plotMap.find(id);
    if (it==plotMap.end()) return vector<string>{};
    return it->second;
}

vector<string> Record::loadScriptFromSetting(int id) {
    auto it = scriptMap.find(id);
    if (it==scriptMap.end()) return vector<string>{};
    return it->second;
}

void Record::loadCommodityFromSetting(NPC *npc, int id) {
    auto it = characterMap.find(id);
    if (it==characterMap.end()) return;
    CharaterRecord cr = it->second;
    for (auto i=cr.commodity.begin();i!=cr.commodity.end();++i) {
        ItemRecord ir = itemMap.at(*i);
        switch(ir.type) {
            case tMELEE: npc->add(new Weapon(ir.name,MELEE,ir.quality,ir.price));
            break;
            case tRANGE: npc->add(new Weapon(ir.name,RANGE,ir.quality,ir.price));
            break;
            case tARMOR: npc->add(new Armor(ir.name,ir.quality,ir.price));
            break;
            case tPROP: npc->add(new Prop(ir.name,ir.quality,ir.price));
            break;
        }
    }
    return;
}

void Record::saveToFile(Player* player, vector<Room>& rooms) {
    ofstream outFile("savefile.txt"); // Open a file for writing

    if (outFile.is_open()) // Check if the file is open
    {
        savePlayer(player, outFile); // Save player information to file
        saveRooms(rooms, outFile); // Save room information to file

        outFile.close(); // Close the file
        cout << "Game saved successfully!" << endl;
    }
    else
    {
        cout << "Unable to open file for saving." << endl;
    }
}

void Record::loadFromFile(Player* player, vector<Room>& rooms) {
    ifstream inFile("savefile.txt"); // Open the saved file for reading

    if (inFile.is_open()) // Check if the file is open
    {
        loadPlayer(player, inFile); // Load player information from file
        loadRooms(rooms, inFile); // Load room information from file

        inFile.close(); // Close the file
        cout << "Game loaded successfully!" << endl;
    }
    else
    {
        cout << "Unable to open file for loading." << endl;
    }
}
