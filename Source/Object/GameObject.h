#pragma once

#include "SDL.h"
#include "Object.h"
#include "Transform.h"

struct Properties {

public:
	Properties(std::string textureID, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE) {

		X = x;
		Y = y;
		Flip = flip;
		Width = width;
		Height = height;
		TextureID = textureID;
	}

public:
	std::string TextureID;
	int Width, Height;
	float X, Y;
	SDL_RendererFlip Flip;
};

class GameObject : public Object {

public:
	GameObject(Properties* Props): TextureID(Props->TextureID), Width(Props->Width), Height(Props->Height), Flip(Props->Flip) { 
		transform = new Transform(Props->X, Props->Y);
	}

	virtual void Draw() = 0;
	virtual void Update(float dt) = 0;
	virtual void Clean() = 0;

protected:
	Transform* transform;
	int Width, Height;
	std::string TextureID;
	SDL_RendererFlip Flip;
};