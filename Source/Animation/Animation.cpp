#include "Animation.h"
#include "TextureManager.h"

void Animation::Update() {

	SpriteFrame = (SDL_GetTicks() / AnimationSpeed) % FrameCount;
}

void Animation::Draw(float x, float y, int spriteWidth, int spriteHeight) {

	TextureManager::GetInstance()->DrawFrame(TextureID, x, y, spriteWidth, spriteHeight, SpriteRow, SpriteFrame, Flip);
}

void Animation::SetProps(std::string textureID, int spriteRow, int frameCount, int animationSpeed, SDL_RendererFlip flip) {

	TextureID = textureID;
	SpriteRow = spriteRow;
	FrameCount = frameCount;
	AnimationSpeed = animationSpeed;
	Flip = flip;
}