#include <iostream>

#include "entity.h"

Entity::Entity()
{
    position = {0.0f,0.0f,0.0f};
    rotation = {0.0f,0.0f,0.0f};
    scale = {1.0f,1.0f,0.0f};
}
Entity::~Entity()
{
    UnloadTexture(this->_texture);
}

void Entity::update(float deltaTime)
{

}

void Entity::addChild(Entity* child)
{
    if (child->_parent == this) 
    {
        return;
    }
    if (child->_parent != nullptr) 
    {
        child->_parent->removeChild(child);
    }
    child->_parent = this;

    _children.emplace_back(child);
}
void Entity::removeChild(Entity* child) 
{
    std::vector<Entity*>::iterator it = _children.begin();
    while (it != _children.end()) 
    {
        if ((*it)->guid() == child->guid())
        {
            (*it)->_parent = nullptr;
            it = _children.erase(it);
        }
        else 
        {
            ++it;
        }
    }
}

void Entity::addTexture(char *filePath) 
{
    if(IsPathFile(filePath))
    {
        this->_texture = LoadTexture(filePath);
    }
    else if (_texture.id == 0)
    {
        perror(" ########### Failed to load texture ##########" );
    }
}