#include "entity.h"

Entity::Entity()
{   
    position = {0.0f,0.0f,0.1f};
    rotation = {0.0f,0.0f,0.0f};
    scale = {1.0f,1.0f,0.0f};
    
    texturePath = "";
    texture.id = 0; // Set texture id to 0 to indicate it's not loaded
}

Entity::~Entity() 
{
    if (texture.id != 0) {
        UnloadTexture(texture);
    }
}
void Entity::update(float deltaTime)
{

}
void Entity::SetTexture(const std::string& path)
{
    // Unload previous texture if it exists
    if (texture.id != 0) 
    {
        UnloadTexture(texture);
    }

    texturePath = path;
    texture = LoadTexture(path.c_str());
}
void Entity::Draw() const
{
    if (texture.id != 0) {
        DrawTexture(texture, static_cast<int>(position.x), static_cast<int>(position.y), WHITE);
    }
}
