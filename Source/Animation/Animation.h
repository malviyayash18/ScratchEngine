#pragma once

#include "string"
#include "SDL.h"

class Animation {

public:
	Animation() {  }

	void Update();
	void Draw(float x, float y, int spriteWidth, int spriteHeight);
	void SetProps(std::string textureID, int sprintRow, int frameCount, int animationSpeed, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	int SpriteRow, SpriteFrame;
	int AnimationSpeed, FrameCount;
	std::string TextureID;
	SDL_RendererFlip Flip;
};

