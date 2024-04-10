#ifndef SCENE_H
#define SCENE_H

#include "raylib.h"
#include <vector>
#include "entity.h"

class Scene : public Entity
{
public:
    Scene();
    virtual ~Scene();

    virtual void update(float deltaTime) = 0;

    virtual void updateScene(float detlaTime);

    bool isActive() { return !WindowShouldClose(); };

    void AddEntity(Entity* entity);


    Entity entity;
private:

    int screenWidth = 900;
    int screenHeight = 800;
    const char* title = "scene";
    std::vector<Entity*> entities;
};

#endif //SCENE_H//