#include "ui.h"

UI::UI(): game_state(nullptr), return_value(GAME_STATE_IDLE) {}

UI::UI(UI & copy): Object(copy), game_state(copy.game_state), return_value(copy.return_value) {}

UI & UI::operator=(UI & copy) {
	if (&copy != this)
	{
		Object::operator=(copy);
		game_state = copy.game_state;
		return_value = copy.return_value;
	}
	return *this;
}

UI::~UI() {}

int UI::Initialize(std::fstream * file, int * game_state) {
	if (Object::Initialize(file)) return 1;
	this->game_state = game_state;
	(*file) >> return_value;
	return 0;
}

void UI::Update(int mouse_x, int mouse_y, bool is_mouse_pressed, int timer) {}

void UI::Draw(SDL_Renderer * renderer) {
	SDL_RenderCopy(renderer, texture, &sprite, &position);
}