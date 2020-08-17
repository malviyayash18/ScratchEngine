#pragma once

#include "iostream"
#include "SDL.h"
#include "SDL_image.h"

#define SCREEN_WIDTH 1200

#define SCREEN_HEIGHT 700

class Engine {

public:
	
	static Engine* GetInstance() {
		return Instance = (Instance != nullptr) ? Instance : new Engine();
	}

	bool Init();
	void Clean();
	void Quit();

	void Update();
	void Render();
	void Events();

	inline bool IsRunning() { return Is_Running; }
	inline SDL_Renderer* GetRenderer() { return Renderer; };

private:
	
	bool Is_Running;

	Engine() {
		Is_Running = false;
		Window = nullptr;
		Renderer = nullptr;
	};
	

	SDL_Window* Window;
	SDL_Renderer* Renderer;

	static Engine* Instance;

};

