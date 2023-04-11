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
    {10,{"The Byer's", false, {}, {}}},
    {11,{"", false, {}, {3}}},
    {20,{"", false, {}, {}}},
    {30,{"The Wheeler's", false, {}, {}}},
    {31,{"", false, {}, {14,21}}},
    {70,{"Starcourt", false, {}, {}}},
    {71,{"", false, {}, {}}},
    {72,{"Scoop Ahoy", false, {}, {7,13}}},
    {100,{"Your Home", false, {}, {}}},
    {101,{"", false, {}, {2}}},
    {102,{"Your Room", false, {2}, {}}},
    {110,{"The Sinclair's", false, {}, {}}},
    {111,{"", false, {}, {}}},
    {120,{"", false, {}, {}}},
    {130,{"", false, {}, {}}},
    {140,{"", false, {}, {}}},
    {150,{"Hawkins Community Pool", false, {}, {}}},
    {151,{"", false, {}, {16,17}}},
    {160,{"", false, {}, {}}},
    {170,{"", false, {}, {}}},
    {220,{"Hawkins Police Station", false, {}, {}}},
    {221,{"", false, {}, {20}}},
    {230,{"", false, {}, {}}},
    {240,{"The War Zone", false, {}, {}}},
    {241,{"", false, {}, {18}}},
    {260,{"", false, {}, {}}},
    {300,{"Hawkins Memorial Hospital", false, {}, {}}},
    {301,{"", false, {}, {34}}},
    {302,{"", false, {}, {}}},
    {303,{"", false, {}, {33,34}}},
    {310,{"", false, {}, {}}},
    {320,{"Melvald's General", false, {}, {}}},
    {321,{"", false, {}, {19}}},
    {330,{"Hawkins High", false, {}, {}}},
    {331,{"", false, {}, {5,23}}},
    {332,{"", false, {}, {4,8}}},
    {340,{"", false, {}, {}}},
    {350,{"", false, {}, {22}}},
    {360,{"", false, {}, {}}},
    {370,{"The Creel's", false, {}, {}}},
    {371,{"", false, {}, {}}},
    {410,{"Hawkins Middle", false, {}, {}}},
    {420,{"Palace Arcade", false, {}, {}}},
    {421,{"", false, {}, {0,6}}},
    {430,{"Radio Shack", false, {}, {}}},
    {431,{"", false, {}, {15}}},
    {440,{"", false, {}, {}}},
    {450,{"Forest Hills Trailer Park", false, {}, {}}},
    {451,{"", false, {}, {}}},
    {452,{"", false, {}, {1}}},
    {453,{"Munson Trailer", false, {}, {}}},
    {454,{"", false, {}, {}}},
    {460,{"", false, {}, {}}},
    {470,{"", false, {}, {}}},
    {520,{"", false, {}, {}}},
    {550,{"", false, {}, {}}},
    {560,{"", false, {}, {}}},
    {600,{"Roane Hill Cementery", false, {}, {32}}},
    {610,{"", false, {}, {}}},
    {620,{"", false, {}, {}}},
    {650,{"", false, {}, {}}},
    {660,{"", false, {}, {}}},
    {720,{"Hopper's Cabin", false, {}, {}}},
    {721,{"", false, {}, {}}},
    {760,{"Hawkins National Laboratory", false, {}, {}}},
    // {1010,{"The Byer's", false, {}, {}}},
    // {1020,{"", false, {}, {}}},
    // {1030,{"The Wheeler's", false, {}, {}}},
    {1070,{"Starcourt", false, {}, {28}}},
    // {1100,{"Your Home", false, {2}, {2}}},
    // {1110,{"The Sinclair's", false, {}, {}}},
    // {1120,{"", false, {}, {}}},
    // {1130,{"", false, {}, {}}},
    // {1140,{"", false, {}, {}}},
    // {1150,{"Hawkins Community Pool", false, {}, {}}},
    {1160,{"", false, {}, {}}},
    {1170,{"", false, {}, {}}},
    {1220,{"Hawkins Police Station", false, {}, {29,29,29}}},
    {1230,{"", false, {}, {30,30,31,31,31}}},
    {1240,{"The War Zone", false, {}, {31,31,31,31}}},
    {1260,{"", false, {}, {29,29,29}}},
    {1300,{"Hawkins Memorial Hospital", false, {}, {}}},
    {1310,{"", false, {}, {30,30,30}}},
    {1320,{"Melvald's General", false, {}, {30,32}}},
    {1330,{"Hawkins High", false, {}, {}}},
    {1340,{"", false, {}, {29,29}}},
    {1350,{"", false, {}, {30,31,31}}},
    {1360,{"", false, {}, {}}},
    {1370,{"The Creel's", false, {}, {31}}},
    {1410,{"Hawkins Middle", false, {}, {30,30,31,31}}},
    {1420,{"Palace Arcade", false, {}, {}}},
    {1430,{"Radio Shack", false, {}, {31,31}}},
    {1440,{"", false, {}, {}}},
    {1450,{"Forest Hills Trailer Park", false, {}, {28}}},
    {1460,{"", false, {}, {29,30}}},
    {1470,{"", false, {}, {}}},
    {1520,{"", false, {}, {29,31}}},
    {1550,{"", false, {}, {}}},
    {1560,{"", false, {}, {}}},
    {1600,{"The Upside Down", false, {}, {}}},
    {1610,{"", false, {}, {31}}},
    {1620,{"", false, {}, {32}}},
    {1650,{"", false, {}, {}}},
    {1660,{"", false, {}, {27,30}}},
    {1720,{"Hopper's Cabin", false, {}, {}}},
    {1760,{"Hawkins National Laboratory", false, {}, {26,27,24,25,25,11}}},
};

const map<int,vector<string>> plotMap = {
    {10,{"You: Knock knock! Will! You there?", "Will is not at home", "Neither is his brother Jonathan"}},
    {30,{"You knocked on the door of the Wheeler's", "Mike's mom opened the door", "Mrs. Wheeler: Those kids have gone to school. Catch up!"}},
    {100,{"You woke up, feeling awkwardly cold", "Somethings not right...", "But what is it?", "Anyways, you have to go to school today"}},
    {110,{"You walked by Will's house", "Should you check him out?"}},
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
    {1,{"Crackled Red 1983 BC Rich NJ Warlock", tMELEE, 18, 20}},
    {2,{"Bat", tMELEE, 8, 3}},
    {3,{"Mace", tMELEE, 12, 5}},
    {4,{"Torch", tMELEE, 20, 5}},
    {5,{"Pistol", tRANGE, 16, 15}},
    {6,{"Shotgun", tRANGE, 18, 20}},
    {7,{"Molotov", tRANGE, 20, 20}},
    {8,{"Javelin", tRANGE, 12, 10}},
    {9,{"Basketball", tRANGE, 4, 5}},
    {10,{"Swim Suit", tARMOR, 4, 2}},
    {11,{"Wizard Robe", tARMOR, 8, 4}},
    {12,{"Handmade Armor", tARMOR, 10, 6}},
    {13,{"Police Uniform", tARMOR, 12, 12}},
    {14,{"Football Uniform", tARMOR, 14, 15}},
    {15,{"Army Uniform", tARMOR, 16, 30}},
    {16,{"Brenner's Weapon",tRANGE, 14, 20}},
    {17,{"Rifle", tRANGE, 16, 20}},
    {18,{"Spider Monster's Claw", tMELEE, 16, 100}},
    {19,{"Demogorgon's Claw", tMELEE, 12, 100}},
};

struct CharaterRecord {
    string name;
    int characterType;
    int hp;
    int abilities[4];
    int skill[3];
    int weaponId; // type, elapse time, power
    vector<int> commodity;
};

const map<int,CharaterRecord> characterMap = {
    {0, {"Lucas Sinclair", ALLY, MAX_HEALTH, {jobAilities[BASKETBALL_PLAYER][0]+1, jobAilities[BASKETBALL_PLAYER][1]+1, jobAilities[BASKETBALL_PLAYER][2]-1, jobAilities[BASKETBALL_PLAYER][3]-1}, {jobSkills[BASKETBALL_PLAYER][0], jobSkills[BASKETBALL_PLAYER][1], jobSkills[BASKETBALL_PLAYER][2]}, 0}},
    {1, {"Eddie Munson", ALLY, MAX_HEALTH, {jobAilities[GUITARIST][0]+1, jobAilities[GUITARIST][1]-1, jobAilities[GUITARIST][2]+1, jobAilities[GUITARIST][3]-1}, {jobSkills[GUITARIST][0], jobSkills[GUITARIST][1], jobSkills[GUITARIST][2]}, 1}},
    {2, {"Mom", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {3, {"Joyce Byers", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {4, {"Will Byers", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {5, {"Dustin Henderson", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {6, {"Max Mayfield", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {7, {"Robin Buckley", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {8, {"Mike Wheeler", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {9, {"Vecna", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {10, {"Mews", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {11, {"Eleven", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {12, {"Scott Clarke", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {13, {"Erica Sinclair", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {14, {"Jonathan Byers", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {15, {"Bob Newby", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {16, {"Billy Hargrove", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {17, {"Heather Holloway", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {18, {"Clerk Jason", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {19, {"Clerk Jeffery", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {20, {"Jim Hopper", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {21, {"Nancy Wheeler", ALLY, MAX_HEALTH, {jobAilities[REPORTER][0]+1, jobAilities[REPORTER][1]+1, jobAilities[REPORTER][2]-1, jobAilities[REPORTER][3]-1}, {jobSkills[REPORTER][0], jobSkills[REPORTER][1], jobSkills[REPORTER][2]}, 0}},
    {22, {"Chrissy Cunningham", ALLY, MAX_HEALTH, {jobAilities[CHEERLEADER][0]+1, jobAilities[CHEERLEADER][1]+1, jobAilities[CHEERLEADER][2]-1, jobAilities[CHEERLEADER][3]-1}, {jobSkills[CHEERLEADER][0], jobSkills[CHEERLEADER][1], jobSkills[CHEERLEADER][2]}, 0}},
    {23, {"Steve Harrington", ALLY, MAX_HEALTH, {jobAilities[SCOOPS_AHOY][0]+1, jobAilities[SCOOPS_AHOY][1]+1, jobAilities[SCOOPS_AHOY][2]-1, jobAilities[SCOOPS_AHOY][3]-1}, {jobSkills[SCOOPS_AHOY][0], jobSkills[SCOOPS_AHOY][1], jobSkills[SCOOPS_AHOY][2]}, 0}},
    {24, {"Martin Brenner", ENEMY, MAX_HEALTH, {2,2,2,2}, {-1,-1,-1},16}},
    {25, {"Lab Guard", ENEMY, MAX_HEALTH, {1,1,1,1}, {-1,-1,-1},17}},
    {26, {"Vecna", ENEMY, MAX_HEALTH*2, {5,5,5,0}, {CLOCKED,7,10},-1}},
    {27, {"Mind Flayer", ENEMY, MAX_HEALTH, {4,4,0,1}, {PUPPETIZED,1,7},-1}},
    {28, {"The Spider Monster", ENEMY, MAX_HEALTH, {5,5,0,0}, {-1,-1,-1},18}},
    {29, {"Demogorgon", ENEMY, MAX_HEALTH, {3,1,0,0}, {-1,-1,-1},19}},
    {30, {"Demodog", ENEMY, MAX_HEALTH, {3,1,0,0}, {-1,-1,-1},19}},
    {31, {"Demobat", ENEMY, MAX_HEALTH, {0,6,0,0}, {-1,-1,-1},-1}},
    {32, {"Vine", ENEMY, MAX_HEALTH, {2,-2,0,0}, {-1,-1,-1},-1}},
    {33, {"Doctor", NEUTRAL, MAX_HEALTH, {-1,-1,-1,-1},{-1,-1,-1},-1}},
    {34, {"Nurse", NEUTRAL, MAX_HEALTH, {-1,-1,-1,-1},{-1,-1,-1},-1}},
    {35, {"Lab Scientist", NEUTRAL, MAX_HEALTH, {-1,-1,-1,-1},{-1,-1,-1},-1}},
};

const map<int,vector<string>> scriptMap = {
    {0, {"Hi"}}
};

#endif // SETTINGS_H_INCLUDED