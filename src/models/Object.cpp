#include "Object.h"

Object::Object() {}

Object::Object(string name, int type):
    name(name), objectType(type) {}

int Object::getType() {
    return objectType * TYPE_BOUND;
}

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
