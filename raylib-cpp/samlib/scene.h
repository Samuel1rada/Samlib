// scene.h
#ifndef SCENE_H
#define SCENE_H

#include "raylib.h"

class Scene {
public:
    Scene(int screenWidth, int screenHeight, const char* title);
    ~Scene();

    void BeginDrawing();
    void EndDrawing();
    void ClearBackground(Color color);

private:
    int screenWidth = 900;
    int screenHeight = 800;
    const char* title = "scene";
};

#endif // SCENE_H