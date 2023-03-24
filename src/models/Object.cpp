#include "Object.h"
#include "enums.h"

Object::Object() {}

Object::Object(string name, ObjectType type):
    name(name), objectType(type) {}

string Object::getName() const {
    return name;
}

ObjectType Object::getObjectType() const {
    return objectType;
}

void Object::setName(string newName) {
    name = newName;
}

void Object::setObjectType(ObjectType newType) {
    objectType = newType;
}
