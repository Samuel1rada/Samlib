/*
* Copyright 2024 Rowan Pijnaker
*/

#ifndef Entity_H
#define Entity_H

#include "raylib.h"
#include <map>
#include <vector>
#include <string>
#include <iostream>
	

class Entity
{
public:
	/// @brief Constructor of Entity
	Entity();
	/// @brief Destructor of Entity
	virtual ~Entity();

	virtual void update(float deltaTime) = 0;

    void addChild(Entity* child);
    void removeChild(Entity* child);
	void addTexture(char *filePath);
	void removeTexture();
	void draw();

	Vector3 position;
    Vector3 rotation;
    Vector3 scale;

	const std::vector<Entity *> &children() { return _children; };

	Entity *parent() { return _parent; };

	Texture2D texture() {return _texture; };

protected:
	Vector2 _worldPosition;

private:

	Texture2D _texture;
	
	std::vector<Entity*> _children; 

	Entity* _parent;
};

#endif /* Entity_H */
