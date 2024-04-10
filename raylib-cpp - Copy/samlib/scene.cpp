// scene.cpp
#include "scene.h"

Scene::Scene() : Entity()
{
    InitWindow(screenWidth, screenHeight, title);
}
Scene::~Scene() 
{
    CloseWindow();
}

void Scene::updateScene(float deltaTime)
{
    
    DrawFPS(25, 25);
    BeginDrawing();
    ClearBackground(RAYWHITE);
    this->update(deltaTime);
    //this->updateEntitys(this, deltaTime);
    // this->DrawEntitys();
    EndDrawing();
}
// void Scene::updateEntitys(Entity* child, float deltaTime)  
// {
//     // update() all childeren 
//     for (Entity* child : this->children()) {
//         child->update(deltaTime);
//     }
// }
// void Scene::DrawEntitys()
// {
//     //draw all children 
//     for (Entity* child : this->children()) 
//     {
//         DrawTexture(child->texture(), static_cast<int>(child->position.x), static_cast<int>(child->position.y), WHITE);
//     }
// }
