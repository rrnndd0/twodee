#ifndef CONTROLLERGAME_H
#define CONTROLLERGAME_H

#include "controller.hpp"
#include "scene.hpp"
#include "Entities/player.hpp"
#include "camera.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
 
class ControllerGame : public Controller
{
public:
	ControllerGame();
	~ControllerGame();
	ControllerGame(SDL_Renderer* p_renderer, int ScreenWidth, int ScreenHeight);

	virtual void SetInput(SDL_Event &events);
	virtual void Update(double timeStep);
	virtual void Draw(SDL_Renderer*);

private:
	// Pointer to Renderer passed in from engine
	SDL_Renderer* renderer;

	// Scene data
	Scene *currScene;
	Player *newPlayer;
	Player *AIPlayer;
};
#endif