#include "Object.h"
#include "enums.h"

Object::Object() {}

Object::Object(string name, int type):
    name(name), objectType(type) {}

string Object::getName() const {
    return name;
}

int Object::getObjectType() const {
    return objectType;
}

void Object::setName(string newName) {
    name = newName;
}

void Object::setObjectType(int newType) {
    objectType = newType;
}
