#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <SDL2/SDL.h>
#include <vector>
#include "structs.hpp"
#include "shape.hpp"

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	void SetCurrSceneCollisions(std::vector<Shape>* cObjects, int WORLD_WIDTH, int WORLD_HEIGHT);
	void UpdateCollidableObjectsOnScreen();
	void playerCollision(float xVelocity, float yVelocity, float* xNewPos, float* yNewPos, SDL_Rect currentPos);

private:
	std::vector<Shape>* cObjects;
	std::vector<Shape*> objOnScreen;
	int currWorldWidth, currWorldHeight;

};

#endif