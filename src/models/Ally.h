#ifndef Ally_H_INCLUDED
#define Ally_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"

using namespace std;

class Ally: public GameCharacter
{
private:
    Weapon* weapon;
    vector<string> script;
public:
    Ally();
    Ally(string name, Weapon* weapon, vector<string> script, int strength, int dexterity, int constitution, int wisdom);

    /* Virtual function that you need to complete   */
    /* In Ally, this function should deal with   */
    /* teaming up with the ally  */
    bool triggerEvent(Object*);
    Item* getWeapon();

    /* Set & Get function*/
    void setScript(vector<string>);
    vector<string> getScript() const;
    void setWeapon(Weapon*);
};


#endif // Ally_H_INCLUDED
