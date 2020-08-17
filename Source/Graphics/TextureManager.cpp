#include "TextureManager.h"
#include "Engine.h"

TextureManager* TextureManager::Instance = nullptr;

bool TextureManager::Load(std::string id, std::string filename) {

	SDL_Surface* Surface = IMG_Load(filename.c_str());
	if (Surface == nullptr) {
		SDL_Log("Failed to load texture : %s %s", filename.c_str(), SDL_GetError());
		return false;
	}

	SDL_Texture* Texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), Surface);
	if (Texture == nullptr) {
		SDL_Log("Failed to create texture from surface : %s %s", filename.c_str(), SDL_GetError());
		return false;
	}

	Texture_Map[id] = Texture;
	return true;
}

void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip) {

	SDL_Rect srcRect = {0, 0, width, height};
	SDL_Rect dstRect = { x, y, width, height };
	SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), Texture_Map[id], &srcRect, &dstRect, 0, nullptr, flip);
}

void TextureManager::DrawFrame(std::string id, int x, int y, int width, int height,int row, int frame, SDL_RendererFlip flip) {

	SDL_Rect srcRect = { width*frame, height*(row-1), width, height };
	SDL_Rect dstRect = { x, y, width, height };
	SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), Texture_Map[id], &srcRect, &dstRect, 0, nullptr, flip);
}

void TextureManager::Drop(std::string id) {

	SDL_DestroyTexture(Texture_Map[id]);
	Texture_Map.erase(id);
}

void TextureManager::Clean() {

	std::map<std::string, SDL_Texture*>::iterator it;
	for (it = Texture_Map.begin(); it != Texture_Map.end(); it++) {
		SDL_DestroyTexture(it->second);
	}

	Texture_Map.clear();

	SDL_Log("Texture Map Cleaned");
}




