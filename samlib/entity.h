/**
 * @file entity.h
 * 
 * @brief the Entity header file.
 */
#ifndef ENTITY_H
#define ENTITY_H

#include <raylib.h>
#include <string>

class Entity
{
public: 
    Entity();
    virtual ~Entity();

    virtual void update(float deltaTime);

    Vector3 position;
    Vector3 rotation;
    Vector3 scale;  

    void addSprite(const std::string& path);

private:

     Texture2D texture;
};

#endif // ENTITY_H