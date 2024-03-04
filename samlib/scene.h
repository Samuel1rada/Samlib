/**
 * @file scene.h
 * 
 * @brief the Scene header file.
 */
#ifndef SCENE_H
#define SCENE_H

#include <raylib.h>

class Scene
{
public:
    Scene();
    virtual ~Scene();

    void update(float deltaTime);

    bool IsActive() { return _isActive; };

    bool _isActive;

    int ScreenWidth = 1700;
    int ScreenHeight = 900;

};

#endif // SCENE_H