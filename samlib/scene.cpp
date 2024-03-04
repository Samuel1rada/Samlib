#include <iostream>
#include "scene.h"
#include "systemcore.h"

Scene::Scene()
{
    _isActive = true;

    InitWindow(ScreenWidth, ScreenHeight, "raylib [textures] example - texture loading and drawing");
     Texture2D texture = LoadTexture("rts/assets/nick.jng"); 

    while (!WindowShouldClose())
    {
        BeginDrawing();

        DrawTexture(texture, ScreenWidth / 2, ScreenHeight / 2, GRAY );

        ClearBackground(RAYWHITE); 
        EndDrawing();
    }
}

Scene::~Scene()
{
    CloseWindow();
}

void Scene::update(float deltaTime)
{
    // Implement update logic here
}

