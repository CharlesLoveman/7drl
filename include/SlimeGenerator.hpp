#ifndef __SLIMEGEN_H_
#define __SLIMEGEN_H_

#include "EntityGenerator.hpp"
#include "StaticSingleRenderer.hpp"
#include "BasicUpdate.hpp"

class SlimeGenerator : public EntityGenerator {
public:
    ~SlimeGenerator() {}
    void generate(Room &room) override;
};

#endif