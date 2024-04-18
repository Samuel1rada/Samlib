/*
* Copyright 2024 Rowan Pijnaker
*/

#ifndef SCENE_H
#define SCENE_H

#include <entity.h>
#include <vector>
#include <map>

class Scene : public Entity 
{ 
 public:
  	/// @brief Constructor of a Scene
	Scene();

	/// @brief Deconstructor of a scene
	~Scene();

    /// @brief draw the scene
	/// @return void
	void draw();

	/// @brief Update the scene. This function is PURE VIRTUAL. You MUST implement it when extending from Scene.
	/// @param deltaTime Time elapsed since last frame draw.
	/// @return void
	virtual void update(float deltaTime) = 0;
	/// @brief update this Scene
	/// @param deltaTime the number of seconds since the last update
	/// @return void
	virtual void tick(float deltaTime);
	/// @brief Wether the scene is active or not
	bool isActive() { return !WindowShouldClose(); };

   
	int screenWidth = 900;
    int screenHeight = 700 ;
	const char* title = "test" ;

private:
	/// @brief draw & Update each entity from the list entities
	/// @param entity the Entity to update
	/// @param deltaTime the number of seconds since the last update
	/// @return void
	void updateEntity(Entity* child, float deltaTime);


};

#endif /* SCENE_H */
