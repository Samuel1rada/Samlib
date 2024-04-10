#ifndef MAINBASE_H
#define MAINBASE_H


#include "entity.h"

class MainBase : public Entity {
public:
    MainBase();
    virtual~MainBase();
    virtual void update(float deltaTime);

    float wheel = GetMouseWheelMove();
};

#endif //MAINBASE_H//