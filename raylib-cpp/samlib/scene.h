/*
* Copyright 2024 Rowan Pijnaker
*/

#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <fstream>
#include <entity.h>
#include <vector>
#include <map>

class Scene : public Entity 
{ 
 public:
	Scene();
	~Scene();
	void draw();

	virtual void update(float deltaTime) = 0;
	virtual void tick(float deltaTime);

	bool isActive() { return !WindowShouldClose(); };

	int screenWidth = 1700;
    int screenHeight = 900;
	const char* title = "Scene" ;

private:

	void updateEntity(Entity* child, float deltaTime);


};

#endif /* SCENE_H */
