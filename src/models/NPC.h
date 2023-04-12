#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"
#include "Item.h"
#include "Logger.h"

using namespace std;

class NPC: public GameCharacter
{
private:
    vector<string> script;
    vector<Item*> commodity;
public:
    NPC();
    NPC(string name, vector<string> script);
    NPC(string name, vector<string> script, vector<Item*> commodity);
    void listCommodity(); /*print all the Item in this NPC*/

    /* Virtual function that you need to complete   */
    /* In NPC, this function should deal with the   */
    /* transaction in easy implementation           */
    bool triggerEvent(Object*);
    Item* getWeapon();
    void add(Item*);

    /* Set & Get function*/
    void setScript(vector<string>);
    void setCommodity(vector<Item*>);
    vector<string> getScript() const;
    vector<Item*> getCommodity() const;
};


#endif // NPC_H_INCLUDED
