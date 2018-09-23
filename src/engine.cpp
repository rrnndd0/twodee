#include "engine.hpp"

void Engine::Run()
{
	bool bRunning = true;
	p_cntrMenu = new ControllerMenu();
	p_cntrGame = new ControllerGame();
	
	//Set the menu as the current controller object
	p_cntrCurrent = p_cntrMenu;
	p_cntrCurrent->SetForegroundStatus();
	bShowMenu = true;
	std::cout << "Assign Menu to Controller Pointer" << std::endl;
	
	SDL_Init( SDL_INIT_EVERYTHING );

	p_window = SDL_CreateWindow( "TwoDee", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 768, SDL_WINDOW_SHOWN );
	p_renderer = SDL_CreateRenderer( p_window, -1, SDL_RENDERER_ACCELERATED );
	SDL_Event event;

	double timeDelta = 1.0/30.0;
	double timeAccumulator = 0;
	double timeStart = SDL_GetTicks();
	double timeSimulatedThisIteration;
	while(bRunning)
	{
		timeStart = SDL_GetTicks();
		timeSimulatedThisIteration = 0;
		
    	while( SDL_PollEvent( &event ) )
		{
        	switch( event.type )
			{
				case SDL_QUIT:
					bRunning = false;
			}
		}
		
		while ( timeAccumulator >= timeDelta )
		{
			Update(timeDelta);
			timeAccumulator -= timeDelta;
			timeSimulatedThisIteration += timeDelta;
		}
		
		Draw();
		SDL_RenderPresent( p_renderer ); 
		timeAccumulator += SDL_GetTicks(); - timeStart;
	}
	SDL_DestroyRenderer( p_renderer );
	SDL_DestroyWindow( p_window );
	SDL_Quit();
	
}
void Engine::Update(double dt)
{
	p_cntrCurrent->Update(dt);
	
	if (!p_cntrCurrent->GetForegroundStatus())
	{
		//Current controller has slipped into the background, bring other controller to the front 
		ToggleMenu();
	}
	
}
void Engine::Draw()
{
	p_cntrCurrent->Draw(p_renderer);
}
void Engine::ToggleMenu()
{
	if (!bShowMenu)
	{ //Show menu
		std::cout << "Assign Menu to Controller Pointer" << std::endl;
		p_cntrCurrent = p_cntrMenu;
		p_cntrCurrent->SetForegroundStatus();
		bShowMenu = true;
	}
	else
	{ //Show game
		std::cout << "Assign Game to Controller Pointer" << std::endl;
		p_cntrCurrent = p_cntrGame;
		p_cntrCurrent->SetForegroundStatus();
		bShowMenu = false;
	}
}

