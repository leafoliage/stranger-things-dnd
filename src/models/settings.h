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
    {10,{"Wheelers House", false, {}, {}}},
    {11,{"", false, {}, {14,21}}},
    {20,{"Sinclairs House", false, {}, {}}},
    {21,{"", false, {}, {13}}},
    {30,{"Your Home", false, {}, {}}},
    {31,{"", false, {}, {2}}},
    {32,{"Your Room", false, {2}, {}}},
    {70,{"Starcourt", false, {}, {}}},
    {71,{"", false, {7}, {}}},
    {72,{"Scoop Ahoy", false, {}, {7,13}}},
    {100,{"Byers House", false, {}, {}}},
    {101,{"", false, {}, {3}}},
    {110,{"Maple Street", false, {}, {}}},
    {120,{"Maple Street", false, {}, {}}},
    {130,{"Maple Street", false, {}, {}}},
    {140,{"", false, {}, {}}},
    {150,{"Hawkins Community Pool", false, {}, {}}},
    {151,{"", false, {}, {16}}},
    {160,{"", false, {}, {}}},
    {170,{"", false, {}, {10}}},
    {220,{"Hawkins Police Station", false, {}, {}}},
    {221,{"", false, {}, {36}}},
    {230,{"", false, {}, {}}},
    {240,{"The War Zone", false, {}, {}}},
    {241,{"", false, {}, {18}}},
    {260,{"", false, {}, {}}},
    {300,{"Hawkins Memorial Hospital", false, {}, {}}},
    {301,{"", false, {}, {33,34}}},
    {320,{"Melvald's General", false, {}, {}}},
    {321,{"", false, {}, {19}}},
    {330,{"Hawkins High", false, {}, {}}},
    {331,{"Hallway", false, {}, {4,8}}},
    {332,{"Classroom", false, {}, {5,23}}},
    {340,{"", false, {9}, {}}},
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
    {452,{"Munson Trailer", false, {}, {}}},
    {453,{"", false, {}, {1}}},
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
    {722,{"Eleven's Room", false, {}, {}}},
    {723,{"Jim's Room", false, {4}, {}}},
    {760,{"Hawkins National Laboratory", false, {}, {}}},
    {1070,{"Starcourt", false, {}, {28}}},
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
    {2023,{"You WON", true, {}, {}}},
};

const map<int,vector<string>> plotMap = {
    {20,{"You knocked on the door of the Wheeler's", "Nancy: Oh hey! Mike isn't here. Come on in."}},
    {30,{"Hint: Go north to the school"}},
    {32,{"You woke up in your bedroom, feeling awkwardly cold", "Somethings not right...", "But what is it?", "Looking at the clock, you noticed that you're already late for school", "Anyways, you have to go to school first"}},
    {221,{"You: Hello Mr. Powell. Is Chief Hopper here?", "Powell: Hello!", "Unfortunately, he isn\'t here.", "We were looking for Eleven for the whole day, he's probably still out there searching.", "Why don't you check out his cabin first?"}},
    {331,{"You see Will and Mike walking by. Seems like they're talking about something.", "Will: You sure you didn't see her?", "Mike: Not at all, I've searched through every corner but there's no sign of her", "Will: Well, maybe she slept over.", "Mike: Impossible, El never comes to school late", "You: Hi! What's the matter?", "Mike: Eleven's didn't come to school today!", "Will: Let's wait for her, alight. Easy", "Mike can't but sit at his desk unwillingly", "", "***", "", "Will, Mike and You waited for the whole day, but Eleven didn't show up.", "After school, Mike has decided to go find her"}},
    {332,{"Dustin and Steve are in the classroom.", "Hint: Steve is a ally of yours, who can help find Eleven with you.", "You would meet several other potential allies on the exploring of this world.", "Talk to Steve to invite him."}},
    {421,{"Max and Lucas are playing DigDug."}},
    {720,{"Jim Hopper is pacing back and forth in front of his cabin, but no signs of Eleven", "You: Mr. Hopper! Did you find El?", "Hopper: (A long sigh) No. I don't know where she is. Where the hell could she be...", "You: Could she be at the lab? The National Hawkins Lab?", "Hopper: I've just gone there. I tried to break in, but then I was expelled.", "You're right, something's not right with that place.", "You: Thank you, Mr. Hopper!", "Jim Hopper hop on his jeep and drove away."}},
    {760,{"You saw a man wearing lab coat running out of the lab.", "You: Hey sir, what happened?", "The scientist: People are disappearing! Everyone is gone!", "You: Why are they gone?", "The scientist: It must be Vecna! He has come after us! Kid, don't get close!", "The scientist ran away.", "You: Wait!", "He did not come back. Seems that the only way now is to find the Upside Down and Vecna."}},
    {1600,{"\"This is it. The Upside Down.\" You think.", "It's dark and creepy here, and you feel pretty cold."}},
    {1760,{"There are several figures stading in front of the vine-covered Hawkins Lab. You recognized the one in the center with grim, ferocious face.", "It's Vecna", "Aside of him is Dr. Martin Brenner.", "You: What have you done to him?", "Vecna: He's become my puppet.", "And so will you.", "You: Hmph!"}}
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
    {31,-1,-1,-1,-1,32,30,-1},
    {32,-1,-1,-1,-1,-1,31,-1},
    {71,-1,72,-1,-1,-1,70,-1},
    {72,71,-1,-1,-1,-1,-1,-1},
    {331,-1,-1,-1,-1,332,330,-1},
    {332,-1,-1,-1,-1,-1,331,-1},
    {451,-1,-1,452,-1,-1,450,-1},
    {452,-1,-1,-1,451,453,-1,-1},
    {453,-1,-1,-1,-1,-1,452,-1},
    {721,722,-1,-1,723,-1,720,-1},
    {722,-1,721,-1,-1,-1,-1,-1},
    {723,-1,-1,721,-1,-1,-1,-1},
    {600,-1,-1,610,-1,-1,-1,1600},
    {1600,-1,-1,1610,-1,-1,-1,600},
    {1370,1470,-1,-1,1360,-1,-1,370},
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
    {5,{"Pistol", tRANGE, 14, 15}},
    {6,{"Nancy Drew Never-Miss Shotgun", tRANGE, 18, 20}},
    {7,{"Molotov", tRANGE, 20, 20}},
    {8,{"Spears", tRANGE, 12, 10}},
    {9,{"Basketball", tRANGE, 4, 5}},
    {10,{"Swim Suit", tARMOR, 4, 2}},
    {11,{"Wizard Robe", tARMOR, 8, 4}},
    {12,{"Handmade Armor", tARMOR, 9, 6}},
    {13,{"Police Uniform", tARMOR, 10, 12}},
    {14,{"Football Uniform", tARMOR, 11, 15}},
    {15,{"Army Uniform", tARMOR, 13, 30}},
    {16,{"Brenner's Brain",tRANGE, 14, 20}},
    {17,{"Rifle", tRANGE, 16, 20}},
    {18,{"Spider Monster's Claw", tMELEE, 16, 100}},
    {19,{"Demogorgon's Claw", tMELEE, 12, 100}},
    {20,{"King Steve Dingus Mace", tMELEE, 16, 20}},
    {21,{"Chrissy's Alarm Clock", tRANGE, 14, 20}},
    {22,{"Spiked Trash Can Cover", tMELEE, 10,6}},
    {23,{"Shotgun", tRANGE, 16, 20}},
    {24,{"Thick Jacket", tARMOR, 12, 10}},
};

struct CharaterRecord {
    string name;
    int characterType;
    int hp;
    int abilities[4];
    int skill[3]; // type, elapse time, power
    int weaponId;
    vector<int> commodity;
};

const map<int,CharaterRecord> characterMap = {
    {0, {"Lucas Sinclair", ALLY, MAX_HEALTH, {jobAilities[BASKETBALL_PLAYER][0]+1, jobAilities[BASKETBALL_PLAYER][1]+1, jobAilities[BASKETBALL_PLAYER][2]-1, jobAilities[BASKETBALL_PLAYER][3]-1}, {jobSkills[BASKETBALL_PLAYER][0], jobSkills[BASKETBALL_PLAYER][1], jobSkills[BASKETBALL_PLAYER][2]}, 0}},
    {1, {"Eddie Munson", ALLY, MAX_HEALTH, {jobAilities[GUITARIST][0]+1, jobAilities[GUITARIST][1]-1, jobAilities[GUITARIST][2]+1, jobAilities[GUITARIST][3]-1}, {jobSkills[GUITARIST][0], jobSkills[GUITARIST][1], jobSkills[GUITARIST][2]}, 1}},
    {2, {"Mom", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {3, {"Joyce Byers", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{11}}},
    {4, {"Will Byers", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {5, {"Dustin Henderson", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {6, {"Max Mayfield", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {7, {"Robin Buckley", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {8, {"Mike Wheeler", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    // {9, {"Vecna", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {10, {"Mews", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {11, {"Eleven", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {12, {"Scott Clarke", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {13, {"Erica Sinclair", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {14, {"Jonathan Byers", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {15, {"Bob Newby", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {16, {"Billy Hargrove", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{10}}},
    // {17, {"Heather Holloway", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {18, {"Clerk Jason", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{3,8,12,15,22,23}}},
    {19, {"Clerk Jeffery", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{14,24}}},
    {20, {"Jim Hopper", NEUTRAL, MAX_HEALTH,{-1,-1,-1,-1},{-1,-1,-1},-1,{}}},
    {21, {"Nancy Wheeler", ALLY, MAX_HEALTH, {jobAilities[REPORTER][0]+1, jobAilities[REPORTER][1]+1, jobAilities[REPORTER][2]-1, jobAilities[REPORTER][3]-1}, {jobSkills[REPORTER][0], jobSkills[REPORTER][1], jobSkills[REPORTER][2]}, 6}},
    {22, {"Chrissy Cunningham", ALLY, MAX_HEALTH, {jobAilities[CHEERLEADER][0]+1, jobAilities[CHEERLEADER][1]+1, jobAilities[CHEERLEADER][2]-1, jobAilities[CHEERLEADER][3]-1}, {jobSkills[CHEERLEADER][0], jobSkills[CHEERLEADER][1], jobSkills[CHEERLEADER][2]}, 0}},
    {23, {"Steve Harrington", ALLY, MAX_HEALTH, {jobAilities[SCOOPS_AHOY][0]+1, jobAilities[SCOOPS_AHOY][1]+1, jobAilities[SCOOPS_AHOY][2]-1, jobAilities[SCOOPS_AHOY][3]-1}, {jobSkills[SCOOPS_AHOY][0], jobSkills[SCOOPS_AHOY][1], jobSkills[SCOOPS_AHOY][2]}, 20}},
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
    {36, {"Calvin Powell", NEUTRAL, MAX_HEALTH, {-1,-1,-1,-1},{-1,-1,-1},-1,{5,13}}},
};

const map<int,vector<string>> scriptMap = {
    {0, {"Lucas: If there is something out there, I'm gonna shoot it in the eyes.", "You: I'm looking for Eleven. Did you see her?", "Lucas: I didn't. But I think I should help you find her."}},
    {1, {"Eddie: So uh, this place is like Hawkins with monsters and nasty shit?", "You: I'm looking for a girl called Eleven. Did you see her?", "Eddie: No. Want me to help you?"}},
    {2, {"Mom: Hurry up, you gotta go to school"}},
    {3, {"Joyce: This is not yours to fix alone. You act like you're all alone out there in the world, but you're not!"}},
    {4, {"Will: I've tried to calm him down, but it didn't work.", "Mike's thinking about her all day long.", "Can you help us?"}},
    {5, {"Dustin: You know that Eleven is gone, right?", "My mews was gone too. Just last night."}},
    {6, {"Max: Ha! I beated my record!"}},
    {7, {"Robin: Hey dingus! Your children are here."}},
    {8, {"Mike: We gotta find where El is.", "You should help too!"}},
    {10, {"Mews: Meow", "You: Meow meow?", "Mews: Meow"}},
    {11, {"After defeating all the enemies, you see Eleven lying on the ground.", "You: Eleven!", "You tried to wake her up, but she seems severely unconscious.", "Anyways, it's time to take her back..."}},
    {13, {"Erica: You can't spell America without Erica."}},
    {14, {"Jonathan: Being a freak is the best, alright? I'm a freak."}},
    {15, {"Bob: Mr. Mom! Whoo, perfect"}},
    {18, {"Jason: Welcome to the War Zone. Buy any weapon you want and battle."}},
    {19, {"Jeffery: Welcome to the Melvald's General. May I help you?"}},
    {21, {"Nancy: I wanna finish what we started.", "Nancy: What?! Eleven is gone?", "You: (Nodded)", "Nancy: I'm helping!"}},
    {22, {"Chrissy: Yeah!", "You: Hey, I'm looking for my friend Eleven. Did you see her?", "Chrissy: I'm sorry... I didn't see anyone. But let me help you."}},
    {23, {"Steve: I'm stealthy. Like a ninja.", "Steve: Wanna go find that girl?", "I'll help"}},
    {33, {"Doctor: Hello"}},
    {34, {"Nurse: Hello"}},
    {36, {"May I help you?"}},
};

#endif // SETTINGS_H_INCLUDED