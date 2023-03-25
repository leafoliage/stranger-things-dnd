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
    vector<string> script;
public:
    Ally();
    Ally(string, vector<string>,int,int,int,int);

    /* Virtual function that you need to complete   */
    /* In Ally, this function should deal with   */
    /* teaming up with the ally  */
    bool triggerEvent(Object*);

    /* Set & Get function*/
    void setScript(vector<string>);
    vector<string> getScript() const;
};


#endif // Ally_H_INCLUDED
