
// entity.h
#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"
#include <string>

class Entity {
public:
    Entity();
    virtual ~Entity();
    virtual void update(float deltaTime);

    void SetTexture(const std::string& path);
    virtual void Draw() const;

    Vector3 position;
    Vector3 rotation;
    Vector3 scale;  

protected:
    std::string texturePath;
    Texture2D texture;
private:

};

#endif //ENTITY//