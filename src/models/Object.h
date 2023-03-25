#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Object
{
private:
    string name;
    int objectType;
public:
    Object();
    Object(string,int);

    /* pure virtual function */
    virtual bool triggerEvent(Object*) = 0;

    /* Set & Get function*/
    void setName(string);
    void setObjectType(int);
    string getName() const;
    int getObjectType() const;
};

#endif // OBJECT_H_INCLUDED
