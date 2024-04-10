#include "scene.h"

Scene::Scene() : Entity()
{
    InitWindow(screenWidth, screenHeight, title);
}
Scene::~Scene() 
{
    CloseWindow();
}
void Scene::update(float deltaTime)
{

}
void Scene::updateScene(float deltaTime)
{
    DrawFPS(25, 25);
    BeginDrawing();
    ClearBackground(RAYWHITE);

    this->update(deltaTime);

    for (const auto& entity : entities) 
    {
        entity->Draw();
    }
    EndDrawing();
}
void Scene::AddEntity(Entity* entity) 
{
    entities.push_back(entity);
}
