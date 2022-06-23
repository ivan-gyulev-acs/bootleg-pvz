#include "global.h"

SDL_Texture * LoadTexture(SDL_Renderer * renderer, std::string file_path) {
	SDL_Texture * texture = nullptr;
	SDL_Surface * surface = SDL_LoadBMP(file_path.c_str());
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	return texture;
}