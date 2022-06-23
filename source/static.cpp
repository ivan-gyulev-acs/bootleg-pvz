#include "static.h"

Static::Static(): health(0) {}

Static::Static(Static & copy): Object(copy), health(copy.health) {}

Static & Static::operator=(Static & copy) {
	if (&copy == this) return *this;
	Object::operator=(copy);
	health = copy.health;
	return *this;
}

Static::~Static() {}

int Static::Initialize(std::fstream* file) {
	if (Object::Initialize(file)) return 1;
	(*file) >> health;
	return 0;
}

void Static::Update(int mouse_x, int mouse_y, bool is_mouse_pressed, int timer) {}

void Static::Draw(SDL_Renderer * renderer) {
	SDL_RenderCopy(renderer, texture, &sprite, &position);
}
