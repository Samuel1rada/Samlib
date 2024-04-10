#ifndef MYSCENE_H
#define MYSCENE_H

#include "scene.h"
#include "mainbase.h"

class MyScene : public Scene 
{
public:
    MyScene();
    virtual ~MyScene();
    virtual void update(float deltaTime);

    void CreatePlayerMainBase();

    MainBase* mainBase;
    
private:

    

};

#endif //MYSCNE_H//