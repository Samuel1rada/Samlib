#include <iostream>

#include "entity.h"

Entity::Entity()
{

    Entity entity;
    entity.position = {0.0f,0.0f,0.0f};
    entity.rotation = {0.0f,0.0f,0.0f};
    entity.scale = {1.0f,1.0f,0.0f};

    texture = { 0 };
}
Entity::~Entity()
{
    UnloadTexture(texture);
}

void Entity::update(float deltaTime)
{

}

void Entity::addSprite(const std::string& path) 
{
    // Load the texture from the given path
    texture = LoadTexture(path.c_str());
}