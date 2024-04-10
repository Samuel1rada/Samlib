// scene.h
#ifndef SCENE_H
#define SCENE_H

#include <raylib.h>
#include "entity.h"

class Scene : public Entity
{
public:
    Scene();
    virtual ~Scene();

    virtual void update(float deltaTime) = 0;

    virtual void updateScene(float detlaTime);

    bool isActive() { return !WindowShouldClose(); };

    int screenWidth = 900;
    int screenHeight = 800;

private:

    // void updateEntitys(Entity* child, float deltaTime);
    // void DrawEntitys();

    const char* title = "scene";
};

#endif // SCENE_H