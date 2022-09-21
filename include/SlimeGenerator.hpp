#ifndef __SLIMEGEN_H_
#define __SLIMEGEN_H_

#include "EntityGenerator.hpp"
#include "StaticSingleRenderer.hpp"

class SlimeGenerator : public EntityGenerator {
public:
    SlimeGenerator(std::shared_ptr<StaticSingleRenderer> _renderer) : EntityGenerator() {
        renderer = _renderer;
    }
    ~SlimeGenerator() {}
    std::unique_ptr<Entity> generate() override;
private:
    std::shared_ptr<StaticSingleRenderer> renderer;
};

#endif