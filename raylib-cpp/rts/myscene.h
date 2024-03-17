#ifndef MYSCENE_H
#define MYSCENE_H

#include "scene.h"
#include "raylib.h"

class Myscene : public Scene
{
public:
    Myscene();
    virtual ~Myscene();

    virtual void update(float deltaTime);

private:
};

#endif // MYSCENE_H