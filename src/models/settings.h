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
    {11,{"", false, vector<int>{}, vector<int>{}}},
    {20,{"", false, vector<int>{}, vector<int>{}}},
    {30,{"The Wheeler's", false, vector<int>{}, vector<int>{}}},
    {31,{"", false, vector<int>{}, vector<int>{}}},
    {70,{"Starcourt", false, vector<int>{}, vector<int>{}}},
    {71,{"", false, vector<int>{}, vector<int>{}}},
    {72,{"Scoop Ahoy", false, vector<int>{}, vector<int>{}}},
    {100,{"Your Home", false, vector<int>{2}, vector<int>{2}}},
    {101,{"", false, vector<int>{}, vector<int>{}}},
    {110,{"The Sinclair's", false, vector<int>{}, vector<int>{}}},
    {111,{"", false, vector<int>{}, vector<int>{}}},
    {120,{"", false, vector<int>{}, vector<int>{}}},
    {130,{"", false, vector<int>{}, vector<int>{}}},
    {140,{"", false, vector<int>{}, vector<int>{}}},
    {150,{"Hawkins Community Pool", false, vector<int>{}, vector<int>{}}},
    {151,{"", false, vector<int>{}, vector<int>{}}},
    {160,{"", false, vector<int>{}, vector<int>{}}},
    {170,{"", false, vector<int>{}, vector<int>{}}},
    {220,{"Hawkins Police Station", false, vector<int>{}, vector<int>{}}},
    {221,{"", false, vector<int>{}, vector<int>{}}},
    {230,{"", false, vector<int>{}, vector<int>{}}},
    {240,{"The Hawkins Post", false, vector<int>{}, vector<int>{}}},
    {241,{"", false, vector<int>{}, vector<int>{}}},
    {260,{"", false, vector<int>{}, vector<int>{}}},
    {300,{"Hawkins Memorial Hospital", false, vector<int>{}, vector<int>{}}},
    {301,{"", false, vector<int>{}, vector<int>{}}},
    {302,{"", false, vector<int>{}, vector<int>{}}},
    {303,{"", false, vector<int>{}, vector<int>{}}},
    {310,{"", false, vector<int>{}, vector<int>{}}},
    {320,{"Melvald's General", false, vector<int>{}, vector<int>{}}},
    {321,{"", false, vector<int>{}, vector<int>{}}},
    {330,{"Hawkins High", false, vector<int>{}, vector<int>{}}},
    {331,{"", false, vector<int>{}, vector<int>{}}},
    {332,{"", false, vector<int>{}, vector<int>{}}},
    {340,{"", false, vector<int>{}, vector<int>{}}},
    {350,{"", false, vector<int>{}, vector<int>{}}},
    {360,{"", false, vector<int>{}, vector<int>{}}},
    {370,{"The Creel's", false, vector<int>{}, vector<int>{}}},
    {371,{"", false, vector<int>{}, vector<int>{}}},
    {420,{"Palace Arcade", false, vector<int>{}, vector<int>{}}},
    {421,{"", false, vector<int>{}, vector<int>{}}},
    {430,{"Radio Shack", false, vector<int>{}, vector<int>{}}},
    {431,{"", false, vector<int>{}, vector<int>{}}},
    {440,{"", false, vector<int>{}, vector<int>{}}},
    {450,{"Forest Hills Trailer Park", false, vector<int>{}, vector<int>{}}},
    {451,{"", false, vector<int>{}, vector<int>{}}},
    {452,{"", false, vector<int>{}, vector<int>{}}},
    {453,{"Munson Trailer", false, vector<int>{}, vector<int>{}}},
    {454,{"", false, vector<int>{}, vector<int>{}}},
    {460,{"", false, vector<int>{}, vector<int>{}}},
    {470,{"", false, vector<int>{}, vector<int>{}}},
    {520,{"", false, vector<int>{}, vector<int>{}}},
    {550,{"", false, vector<int>{}, vector<int>{}}},
    {560,{"", false, vector<int>{}, vector<int>{}}},
    {610,{"Roane Hill Cementery", false, vector<int>{}, vector<int>{}}},
    {620,{"", false, vector<int>{}, vector<int>{}}},
    {630,{"", false, vector<int>{}, vector<int>{}}},
    {640,{"", false, vector<int>{}, vector<int>{}}},
    {650,{"", false, vector<int>{}, vector<int>{}}},
    {660,{"", false, vector<int>{}, vector<int>{}}},
    {720,{"Hopper's Cabin", false, vector<int>{}, vector<int>{}}},
    {721,{"", false, vector<int>{}, vector<int>{}}},
    {760,{"Hawkins National Laboratory", false, vector<int>{}, vector<int>{}}},
    {1010,{"The Byer's", false, vector<int>{}, vector<int>{}}},
    {1020,{"", false, vector<int>{}, vector<int>{}}},
    {1030,{"The Wheeler's", false, vector<int>{}, vector<int>{}}},
    {1070,{"Starcourt", false, vector<int>{}, vector<int>{}}},
    {1100,{"Your Home", false, vector<int>{2}, vector<int>{2}}},
    {1110,{"The Sinclair's", false, vector<int>{}, vector<int>{}}},
    {1120,{"", false, vector<int>{}, vector<int>{}}},
    {1130,{"", false, vector<int>{}, vector<int>{}}},
    {1140,{"", false, vector<int>{}, vector<int>{}}},
    {1150,{"Hawkins Community Pool", false, vector<int>{}, vector<int>{}}},
    {1160,{"", false, vector<int>{}, vector<int>{}}},
    {1170,{"", false, vector<int>{}, vector<int>{}}},
    {1220,{"Hawkins Police Station", false, vector<int>{}, vector<int>{}}},
    {1230,{"", false, vector<int>{}, vector<int>{}}},
    {1240,{"The Hawkins Post", false, vector<int>{}, vector<int>{}}},
    {1260,{"", false, vector<int>{}, vector<int>{}}},
    {1300,{"Hawkins Memorial Hospital", false, vector<int>{}, vector<int>{}}},
    {1310,{"", false, vector<int>{}, vector<int>{}}},
    {1320,{"Melvald's General", false, vector<int>{}, vector<int>{}}},
    {1330,{"Hawkins High", false, vector<int>{}, vector<int>{}}},
    {1340,{"", false, vector<int>{}, vector<int>{}}},
    {1350,{"", false, vector<int>{}, vector<int>{}}},
    {1360,{"", false, vector<int>{}, vector<int>{}}},
    {1370,{"The Creel's", false, vector<int>{}, vector<int>{}}},
    {1420,{"Palace Arcade", false, vector<int>{}, vector<int>{}}},
    {1430,{"Radio Shack", false, vector<int>{}, vector<int>{}}},
    {1440,{"", false, vector<int>{}, vector<int>{}}},
    {1450,{"Forest Hills Trailer Park", false, vector<int>{}, vector<int>{}}},
    {1460,{"", false, vector<int>{}, vector<int>{}}},
    {1470,{"", false, vector<int>{}, vector<int>{}}},
    {1520,{"", false, vector<int>{}, vector<int>{}}},
    {1550,{"", false, vector<int>{}, vector<int>{}}},
    {1560,{"", false, vector<int>{}, vector<int>{}}},
    {1610,{"Roane Hill Cementery", false, vector<int>{}, vector<int>{}}},
    {1620,{"", false, vector<int>{}, vector<int>{}}},
    {1630,{"", false, vector<int>{}, vector<int>{}}},
    {1640,{"", false, vector<int>{}, vector<int>{}}},
    {1650,{"", false, vector<int>{}, vector<int>{}}},
    {1660,{"", false, vector<int>{}, vector<int>{}}},
    {1720,{"Hopper's Cabin", false, vector<int>{}, vector<int>{}}},
    {1760,{"Hawkins National Laboratory", false, vector<int>{}, vector<int>{}}},
};

const map<int,vector<string>> plotMap = {
    {10,vector<string>{"You: Knock knock! Will! You there?", "Will is not at home", "Neither is his brother Jonathan"}},
    {30,vector<string>{"You knocked on the door of the Wheeler's", "Mike's mom opened the door", "Mrs. Wheeler: Those kids have gone to school. Catch up!"}},
    {100,vector<string>{"You woke up, feeling awkwardly cold", "Somethings not right...", "But what is it?", "Anyways, you have to go to school today"}},
    {110,vector<string>{"You walked by Will's house", "Should you check him out?"}},
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
    {120,220,20,130,110,-1,-1,-1},
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