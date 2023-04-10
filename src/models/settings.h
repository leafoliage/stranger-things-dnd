#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

#include <string>
#include <vector>
#include <map>
#include "enums.h"
using namespace std;

struct RoomRecord {
    string name;
    bool isExit;
    vector<int> itemIds;
    vector<int> characterIds;
};

const map<int,RoomRecord> roomMap = {
    {10,{"The Byer's", false, vector<int>{}, vector<int>{}}},
    {20,{"", false, vector<int>{}, vector<int>{}}},
    {30,{"The Wheeler's", false, vector<int>{}, vector<int>{}}},
    {70,{"Starcourt", false, vector<int>{}, vector<int>{}}},
    {100,{"Your Home", false, vector<int>{2}, vector<int>{2}}},
    {110,{"The Sinclair's", false, vector<int>{}, vector<int>{}}},
    {120,{"", false, vector<int>{}, vector<int>{}}},
    {130,{"", false, vector<int>{}, vector<int>{}}},
    {140,{"", false, vector<int>{}, vector<int>{}}},
    {150,{"Hawkins Community Pool", false, vector<int>{}, vector<int>{}}}
};

const map<int,vector<string>> plotMap = {
    {10,vector<string>{"You: Knock knock! Will! You there?", "Will is not at home", "Neither is his brother Jonathan"}},
    {30,vector<string>{"You knocked on the door of the Wheeler's", "Mike's mom opened the door", "Mrs. Wheeler: Those kids have gone to school. Catch up!"}},
    {100,vector<string>{"You woke up, feeling awkwardly cold", "Somethings not right...", "But what is it?", "Anyways, you have to go to school today"}},
    {110,vector<string>{"You walked by Will's house", "Should you check him out?"}},
    // {"", false, vector<int>{}, vector<int>{}}, // 10
    // {"", false, vector<int>{}, vector<int>{}},
    // {"Hawkins Police Station", false, vector<int>{}, vector<int>{}},
    // {"The Hawkins Post", false, vector<int>{}, vector<int>{}},
    // {"", false, vector<int>{}, vector<int>{}},
    // {"Hawkins Memorial Hospital", false, vector<int>{}, vector<int>{}}, // 15
    // {"", false, vector<int>{}, vector<int>{}},
    // {"Melvald's General", false, vector<int>{}, vector<int>{}},
    // {"Hawkins High", false, vector<int>{}, vector<int>{}},
    // {"", false, vector<int>{}, vector<int>{}},
    // {"", false, vector<int>{}, vector<int>{}}, // 20
    // {"", false, vector<int>{}, vector<int>{}},
    // {"The Creel's", false, vector<int>{}, vector<int>{}},
};

struct RoomRelation {
    int id;
    int northId;
    int southId;
    int eastId;
    int westId;
    int inId;
    int outId;
    int secretId;
};

const vector<RoomRelation> roomRelations{
    {10,110,-1,20,-1,-1,-1,-1},
    {20,120,-1,30,10,-1,-1,-1},
    {30,130,-1,40,20,-1,-1,-1},
    {70,-1,-1,-1,-1,-1,-1,-1},
    {100,-1,-1,110,-1,-1,-1,-1},
    {110,-1,10,120,100,-1,-1,-1},
    {120,-1,20,130,110,-1,-1,-1},
    {130,-1,30,140,120,-1,-1,-1},
    {140,-1,-1,150,130,-1,-1,-1},
    {150,-1,-1,-1,140,-1,-1,-1}
};

struct ItemRecord {
    string name;
    int type;
    int quality;
    int price;
};

const map<int,ItemRecord> itemMap = {
    {0,{"Triple Basketball", tRANGE, 14, 10}},
    {1,{"Crackled Red 1983 BC Rich NJ Warlock", tMELEE, 16, 20}},
    {2,{"Bat", tMELEE, 8, 3}},
    {3,{"Bat2", tMELEE, 8, 3}},
    {4,{"Bat3", tMELEE, 8, 3}},
};

struct CharaterRecord {
    string name;
    int characterType;
    int hp;
    int strength;
    int dexterity;
    int constitution;
    int wisdom;
    int skill[3];
    int weaponId;
    vector<int> commodity;
};

const map<int,CharaterRecord> characterMap = {
    {0, {"Lucas Sinclair", ALLY, MAX_HEALTH, jobAilities[BASKETBALL_PLAYER][0]+1, jobAilities[BASKETBALL_PLAYER][1]+1, jobAilities[BASKETBALL_PLAYER][2]-1, jobAilities[BASKETBALL_PLAYER][3]-1, {jobSkills[BASKETBALL_PLAYER][0], jobSkills[BASKETBALL_PLAYER][1], jobSkills[BASKETBALL_PLAYER][2]}, 0}},
    {1, {"Eddie Munson", ALLY, MAX_HEALTH, jobAilities[GUITARIST][0]+1, jobAilities[GUITARIST][1]-1, jobAilities[GUITARIST][2]+1, jobAilities[GUITARIST][3]-1, {jobSkills[GUITARIST][0], jobSkills[GUITARIST][1], jobSkills[GUITARIST][2]}, 1}},
    {2, {"Mom", NEUTRAL, MAX_HEALTH,-1,-1,-1,-1,{-1,-1,-1},-1,vector<int>{3,4}}}
};

const map<int,vector<string>> scriptMap = {
    {0, vector<string>{"Hi"}}
};

#endif // SETTINGS_H_INCLUDED