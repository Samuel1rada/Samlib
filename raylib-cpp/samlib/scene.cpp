// scene.cpp
#include "scene.h"

Scene::Scene(int screenWidth, int screenHeight, const char* title) 
    : screenWidth(screenWidth), screenHeight(screenHeight), title(title) {
    InitWindow(screenWidth, screenHeight, title);
}

Scene::~Scene() {
    CloseWindow();
}

void Scene::BeginDrawing() {
    ::BeginDrawing();
}

void Scene::EndDrawing() {
    ::EndDrawing();
}

void Scene::ClearBackground(Color color) {
    ::ClearBackground(color);
}