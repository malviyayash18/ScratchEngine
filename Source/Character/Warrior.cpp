#include "Warrior.h"
#include "TextureManager.h"
#include "SDL.h"

Warrior::Warrior(Properties* Props): Character(Props) {
	//Frame = 0;
	animation = new Animation();
	animation->SetProps(TextureID, 1, 8, 50, SDL_FLIP_NONE);
}

void Warrior::Draw() {

	animation->Draw(transform->X, transform->Y, Width, Height);
}

void Warrior::Clean() {

	TextureManager::GetInstance()->Clean();
}

void Warrior::Update(float dt) {

	animation->Update();
}