#include "myscene.h"

MyScene::MyScene() : Scene() 
{
    Camera2D camera = { 0 };
    camera.zoom = 1.0f;
    
}
MyScene::~MyScene() 
{

}
void MyScene::update(float deltaTime) 
{
    // Implementation of MyScene update
}

void MyScene::CreatePlayerMainBase()
{
    mainBase = new MainBase;
    AddEntity(mainBase);
    mainBase->position = Vector3{100.0f, 100.0f, 0.0f};
}

