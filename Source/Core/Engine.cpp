#include "Engine.h"
#include "TextureManager.h"
#include "Warrior.h"

Engine* Engine::Instance = nullptr;
Warrior* player = nullptr;

bool Engine::Init() {

	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_JPG) != 0) {
		SDL_Log("Failed to INITIALIZE SDL: %s", SDL_GetError());
		return false;
	}

	// Create a Window
	Window = SDL_CreateWindow("Scratch Engine", SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);
	// Check if Window was created
	if (Window == nullptr) {
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}

	// Create a Renderer
	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | 
		SDL_RENDERER_PRESENTVSYNC);
	// Check if Renderer was created
	if (Renderer == nullptr) {
		SDL_Log("Failed to create Renderer: %s", SDL_GetError());
		return false;
	}

	// Game Code comes here...
	TextureManager::GetInstance()->Load("Player", "Assets/PSD\ Exports/IronMan.png");
	player = new Warrior(new Properties("Player", 50, 50, 200, 200));

	Is_Running = true;

	return true;
}

void Engine::Clean() {
	
	TextureManager::GetInstance()->Clean();
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	IMG_Quit();
	SDL_Quit();
}

void Engine::Quit() {
	Is_Running = false;
}

void Engine::Update() {

	player->Update(0);
}

void Engine::Render() {
	//SDL_SetRenderDrawColor(Renderer, 124, 218, 254, 255);
	SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
	SDL_RenderClear(Renderer);

	player->Draw();
	SDL_RenderPresent(Renderer);
}

void Engine::Events() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		Quit();
		break;
	default:
		break;
	}
}