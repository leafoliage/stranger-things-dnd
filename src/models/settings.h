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
    int strength;
    int dexterity;
    int constitution;
    int wisdom;
    int skill[3];
    int weaponId; // type, elapse time, power
    vector<int> commodity;
};

const map<int,CharaterRecord> characterMap = {
    {0, {"Lucas Sinclair", ALLY, MAX_HEALTH, jobAilities[BASKETBALL_PLAYER][0]+1, jobAilities[BASKETBALL_PLAYER][1]+1, jobAilities[BASKETBALL_PLAYER][2]-1, jobAilities[BASKETBALL_PLAYER][3]-1, {jobSkills[BASKETBALL_PLAYER][0], jobSkills[BASKETBALL_PLAYER][1], jobSkills[BASKETBALL_PLAYER][2]}, 0}},
    {1, {"Eddie Munson", ALLY, MAX_HEALTH, jobAilities[GUITARIST][0]+1, jobAilities[GUITARIST][1]-1, jobAilities[GUITARIST][2]+1, jobAilities[GUITARIST][3]-1, {jobSkills[GUITARIST][0], jobSkills[GUITARIST][1], jobSkills[GUITARIST][2]}, 1}},
    {2, {"Mom", NEUTRAL, MAX_HEALTH,-1,-1,-1,-1,{-1,-1,-1},-1,vector<int>{}}},
    {3, {"Joyce Byers", NEUTRAL, MAX_HEALTH,-1,-1,-1,-1,{-1,-1,-1},-1,vector<int>{}}},
    {4, {"Will Byers", NEUTRAL, MAX_HEALTH,-1,-1,-1,-1,{-1,-1,-1},-1,vector<int>{}}},
    {5, {"Dustin Henderson", NEUTRAL, MAX_HEALTH,-1,-1,-1,-1,{-1,-1,-1},-1,vector<int>{}}},
    {6, {"Max Mayfield", NEUTRAL, MAX_HEALTH,-1,-1,-1,-1,{-1,-1,-1},-1,vector<int>{}}},
    {7, {"Robin Buckley", NEUTRAL, MAX_HEALTH,-1,-1,-1,-1,{-1,-1,-1},-1,vector<int>{}}},
    {8, {"Mike Wheeler", NEUTRAL, MAX_HEALTH,-1,-1,-1,-1,{-1,-1,-1},-1,vector<int>{}}},
    {9, {"Vecna", NEUTRAL, MAX_HEALTH,-1,-1,-1,-1,{-1,-1,-1},-1,vector<int>{}}},
    {10, {"Mews", NEUTRAL, MAX_HEALTH,-1,-1,-1,-1,{-1,-1,-1},-1,vector<int>{}}},
    {11, {"Eleven", NEUTRAL, MAX_HEALTH,-1,-1,-1,-1,{-1,-1,-1},-1,vector<int>{}}},
    {12, {"Scott Clarke", NEUTRAL, MAX_HEALTH,-1,-1,-1,-1,{-1,-1,-1},-1,vector<int>{}}},
    {13, {"Erica Sinclair", NEUTRAL, MAX_HEALTH,-1,-1,-1,-1,{-1,-1,-1},-1,vector<int>{}}},
    {14, {"Jonathan Byers", NEUTRAL, MAX_HEALTH,-1,-1,-1,-1,{-1,-1,-1},-1,vector<int>{}}},
    {15, {"Bob Newby", NEUTRAL, MAX_HEALTH,-1,-1,-1,-1,{-1,-1,-1},-1,vector<int>{}}},
    {16, {"Billy Hargrove", NEUTRAL, MAX_HEALTH,-1,-1,-1,-1,{-1,-1,-1},-1,vector<int>{}}},
    {17, {"Heather Holloway", NEUTRAL, MAX_HEALTH,-1,-1,-1,-1,{-1,-1,-1},-1,vector<int>{}}},
    {18, {"Tom Holloway", NEUTRAL, MAX_HEALTH,-1,-1,-1,-1,{-1,-1,-1},-1,vector<int>{}}},
    {19, {"Bruce Lowe", NEUTRAL, MAX_HEALTH,-1,-1,-1,-1,{-1,-1,-1},-1,vector<int>{}}},
    {20, {"Jim Hopper", NEUTRAL, MAX_HEALTH,-1,-1,-1,-1,{-1,-1,-1},-1,vector<int>{}}},
    {21, {"Nancy Wheeler", ALLY, MAX_HEALTH, jobAilities[REPORTER][0]+1, jobAilities[REPORTER][1]+1, jobAilities[REPORTER][2]-1, jobAilities[REPORTER][3]-1, {jobSkills[REPORTER][0], jobSkills[REPORTER][1], jobSkills[REPORTER][2]}, 0}},
    {22, {"Chrissy Cunningham", ALLY, MAX_HEALTH, jobAilities[CHEERLEADER][0]+1, jobAilities[CHEERLEADER][1]+1, jobAilities[CHEERLEADER][2]-1, jobAilities[CHEERLEADER][3]-1, {jobSkills[CHEERLEADER][0], jobSkills[CHEERLEADER][1], jobSkills[CHEERLEADER][2]}, 0}},
    {23, {"Steve Harrington", ALLY, MAX_HEALTH, jobAilities[SCOOPS_AHOY][0]+1, jobAilities[SCOOPS_AHOY][1]+1, jobAilities[SCOOPS_AHOY][2]-1, jobAilities[SCOOPS_AHOY][3]-1, {jobSkills[SCOOPS_AHOY][0], jobSkills[SCOOPS_AHOY][1], jobSkills[SCOOPS_AHOY][2]}, 0}},
    {24, {"Martin Brenner", ENEMY, MAX_HEALTH,2,2,2,2,{-1,-1,-1},16}},
    {25, {"Lab Guard", ENEMY, MAX_HEALTH,1,1,1,1,{-1,-1,-1},17}},
    {26, {"Vecna", ENEMY, MAX_HEALTH,5,5,5,0,{CLOCKED,7,10},-1}},
    {27, {"Mind Flayer", ENEMY, MAX_HEALTH,4,4,0,1,{PUPPETIZED,1,7},-1}},
    {28, {"The Spider Monster", ENEMY, MAX_HEALTH,5,5,0,0,{-1,-1,-1},18}},
    {29, {"Demogorgon", ENEMY, MAX_HEALTH,3,1,0,0,{-1,-1,-1},19}},
    {30, {"Demodog", ENEMY, MAX_HEALTH,3,1,0,0,{-1,-1,-1},19}},
    {31, {"Demobat", ENEMY, MAX_HEALTH,0,6,0,0,{-1,-1,-1},-1}},
    {32, {"Vine", ENEMY, MAX_HEALTH,2,-2,0,0,{-1,-1,-1},-1}},
};

const map<int,vector<string>> scriptMap = {
    {0, vector<string>{"Hi"}}
};

#endif // SETTINGS_H_INCLUDED