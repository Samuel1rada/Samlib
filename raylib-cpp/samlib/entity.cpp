#include <entity.h>
#include <iostream>

Entity::Entity() 
{
    position = {0.0f, 0.0f, 0.0f};
    rotation = {0.0f, 0.0f, 0.0f};
    scale = {1.0f, 1.0f, 0.0f};



}   

Entity::~Entity() 
{
	removeTexture();
}

void Entity::update(float deltaTime) 
{
   
}

void Entity::draw()
{
    DrawTexture(this->_texture, position.x, position.y, WHITE);
}

void Entity::addChild(Entity* child)
{
    _children.push_back(child);

}

void Entity::removeChild(Entity* child)
{
    delete child;
}

void Entity::removeTexture()
{
    if(IsTextureReady(this->_texture))
    UnloadTexture(this->_texture);
}

void Entity::addTexture(char *filePath)
{
    removeTexture();
    if (IsPathFile(filePath))
        this->_texture = LoadTexture(filePath);

    if(_texture.id == 0){ 
        perror(" ########### Failed to load texture ##########" ); 
    }
}


