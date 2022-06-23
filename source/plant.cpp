#include "plant.h"

Plant::Plant(): cost(0), cooldown(0), fire_rate(0) {}

Plant::Plant(Plant & copy): Static(copy), cost(copy.cost), cooldown(copy.cooldown), fire_rate(copy.fire_rate) {}

Plant & Plant::operator=(Plant & copy) {
	if (&copy == this) return *this;
	Static::operator=(copy);
	cost = copy.cost;
	cooldown = copy.cooldown;
	fire_rate = copy.fire_rate;
	return *this;
}

Plant::~Plant() {}

int Plant::Initialize(std::fstream *file) {
	if (Static::Initialize(file)) return 1;
	(*file) >> cost;
	(*file) >> cooldown;
	(*file) >> fire_rate;
	return 0;
}

void Plant::Update(int mouse_x, int mouse_y, bool is_mouse_pressed, int timer) {}

void Plant::Draw(SDL_Renderer * renderer) {
	SDL_RenderCopy(renderer, texture, &sprite, &position);
}