#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

#include <string>
#include <vector>
#include <map>
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
    {100,{"Your Home", false, vector<int>{}, vector<int>{}}},
    {110,{"", false, vector<int>{}, vector<int>{}}},
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

#endif // SETTINGS_H_INCLUDED