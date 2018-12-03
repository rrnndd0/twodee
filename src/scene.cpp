#include "scene.hpp"

Scene::Scene()
{
	// Default Constructor
}

Scene::~Scene()
{
	// Destructor
}

void Scene::CreateRectangle(int x, int y, int h, int w)
{
	Shape newShape;
	newShape.CreateRectangle(x, y, h, w);
	walls.push_back(newShape);
}

int Scene::GetLevelWidth()
{
	return LEVEL_WIDTH;
}

int Scene::GetLevelHeight()
{
	return LEVEL_HEIGHT;
}

void Scene::Update(int cameraX, int cameraY)
{
	for (int i = 0; i < walls.size(); i++)
	{
		walls[i].UpdateRectangle(cameraX, cameraY);
	}
}

void Scene::Draw(SDL_Renderer* p_renderer)
{
	// Clear Screen 
	SDL_SetRenderDrawColor(p_renderer, 255, 255, 255, 255);
	SDL_RenderClear(p_renderer);
	
	// Draw wall
	SDL_SetRenderDrawColor(p_renderer, 0, 0, 255, 255);

	for (int i = 0; i < walls.size(); i++)
	{
		walls[i].Draw(p_renderer);
	}
}