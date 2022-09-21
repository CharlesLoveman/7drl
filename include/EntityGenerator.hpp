#ifndef __ENTITYGEN_H_
#define __ENTITYGEN_H_

#include "Entity.hpp"
#include <memory>

class EntityGenerator {
public:
    virtual ~EntityGenerator() {}
    virtual std::unique_ptr<Entity> generate() = 0;
};

#endif