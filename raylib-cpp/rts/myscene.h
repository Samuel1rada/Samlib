#ifndef MYSCENE_H
#define MYSCENE_H

#include "scene.h"
#include "raylib.h"
#include "mainbase.h"

class Myscene : public Scene
{
public:
    Myscene();
    virtual ~Myscene();

    virtual void update(float deltaTime);

    void PlayerMainBase();
    void EnemyMainBase();

private:

    Mainbase* playerMainBase;
    Mainbase* enemyMainBase;
};

#endif // MYSCENE_H