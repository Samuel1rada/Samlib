#include <scene.h>

Scene::Scene() : Entity() 
{
	std::cout << "################ new Scene ################" << std::endl;

    
    // Initialize the window for raylib
    InitWindow(screenWidth, screenHeight, title);
    SetWindowState(FLAG_VSYNC_HINT);    
}

Scene::~Scene()
{   
    CloseWindow();
}

void Scene::update(float deltaTime)
{

}

void Scene::tick(float deltaTime)
{
    BeginDrawing();

            this->updateEntity(this, deltaTime);
            this->update(deltaTime);

    EndDrawing();
}

void Scene::draw()
{
}

void Scene::updateEntity(Entity* child, float deltaTime)  
{
    // update() all childeren 
    for (Entity* child : this->children()) {
        child->update(deltaTime);
    }

    // Clear the background
    ClearBackground(RAYWHITE);
    DrawFPS(25, 25);

    //draw all children 
    for (Entity* child : this->children())
    {

    }
}