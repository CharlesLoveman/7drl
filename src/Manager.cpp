#include "Manager.hpp"

bool Manager::handleEvent(RenderEvent&) {
    return false;
}

bool Manager::handleEvent(MovementEvent&) {
    return false;
}

bool Manager::handleEvent(FovEvent&) {
    return false;
}
Manager::~Manager() {

}