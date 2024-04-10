/**
 * @file entity.h
 * 
 * @brief the Entity header file.
 */
#ifndef ENTITY_H
#define ENTITY_H

#include <raylib.h>
#include <string>
#include <vector>

class Entity
{
public: 
    Entity();
    virtual ~Entity();

    virtual void update(float deltaTime);

    Vector3 position;
    Vector3 rotation;
    Vector3 scale;  


    void addChild(Entity* child);
    void removeChild( Entity* child);
    void addTexture(char *filePath);


    int guid() const { return _guid; };

    const std::vector<Entity *> &children() { return _children; };

    Entity* parent() { return _parent; };

    Texture2D texture() {return _texture; };

    Color color() { return _textureColor; };
        
private:

    Texture2D _texture;
    Color _textureColor;
    std::vector<Entity*> _children;
    Entity* _parent;
    int _guid;
};

#endif // ENTITY_H
