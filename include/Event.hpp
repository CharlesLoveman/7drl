#ifndef __EVENT_H__
#define __EVENT_H__

class Entity;
class Manager;
enum class ManagerID;

class Event {
public:
    Event(Entity&);
    virtual ~Event();
    virtual bool accept(Manager&) = 0;
    virtual ManagerID id() = 0;
    Entity &entity;
};

#endif