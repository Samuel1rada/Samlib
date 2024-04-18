#ifndef MAINBASE_H
#define MAINBASE_H

#include "raylib.h"
#include "entity.h"

class Mainbase : public Entity
{
public:
    Mainbase();
    virtual ~Mainbase();

    virtual void update(float deltaTime);

private:
};

#endif // MYSCENE_H