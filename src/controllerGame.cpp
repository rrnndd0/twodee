
#include "controllerGame.hpp"

ControllerGame::ControllerGame()
{
}

ControllerGame::~ControllerGame()
{
}
void ControllerGame::Update(double)
{
}
void ControllerGame::Draw(SDL_Renderer* p_renderer)
{
	int width = 1024.0;
	int height = 768.0;
	
	//Clear screen
	SDL_SetRenderDrawColor( p_renderer, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_RenderClear( p_renderer );

	//Render red filled quad
	SDL_Rect fillRect = { width / 4, height / 4, width / 2, height / 2 };
	SDL_SetRenderDrawColor( p_renderer, 0xFF, 0x00, 0x00, 0xFF );		
	SDL_RenderFillRect( p_renderer, &fillRect );

	//Render green outlined quad
	SDL_Rect outlineRect = { width / 6, height / 6, width * 2 / 3, height * 2 / 3 };
	SDL_SetRenderDrawColor( p_renderer, 0x00, 0xFF, 0x00, 0xFF );		
	SDL_RenderDrawRect( p_renderer, &outlineRect );

	//Draw blue horizontal line
	SDL_SetRenderDrawColor( p_renderer, 0x00, 0x00, 0xFF, 0xFF );		
	SDL_RenderDrawLine( p_renderer, 0, height / 2, width, height / 2 );

	//Draw vertical line of yellow dots
	SDL_SetRenderDrawColor( p_renderer, 0xFF, 0xFF, 0x00, 0xFF );
	for( int i = 0; i < height; i += 4 )
	{
		SDL_RenderDrawPoint( p_renderer, width / 2, i );
	}
}
void ControllerGame::LoadScene(std::string)
{
}