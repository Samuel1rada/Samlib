#ifndef MAINBASE_H
#define MAINBASE_H

#include "raylib.h"
#include "entity.h"

class Mainbase : public Entity
{
public:
    Mainbase(int Type);
    virtual ~Mainbase();

    virtual void update(float deltaTime);
    int getType() const;
    int type;
private:


};

#endif // MYSCENE_H