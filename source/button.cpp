#include "button.h"
#include <iostream>

Button::Button() {}

Button::Button(Button & copy): UI(copy) {}

Button & Button::operator=(Button & copy) {
	if (&copy == this) return *this;
	UI::operator=(copy);
	return *this;
}

Button::~Button() {}

int Button::Initialize(std::fstream * file, int * game_state) {
	if (!UI::Initialize(file, game_state)) {}
	return 0;
}

void Button::Update(int mouse_x, int mouse_y, bool is_mouse_pressed, int timer) {
	if (is_mouse_pressed &&
		mouse_x >= position.x && mouse_x <= position.x + position.w - 4 * SCALE &&
		mouse_y >= position.y && mouse_y <= position.y + position.h - 4 * SCALE ) status = BUTTON_STATUS_PRESSED;
	if (status == BUTTON_STATUS_PRESSED) {
		status = BUTTON_STATUS_IDLE;
		(*game_state) = return_value;
	}
}

void Button::Draw(SDL_Renderer * renderer) {
	std::cout << key_word << " was rendered\n";
	SDL_RenderCopy(renderer, texture, &sprite, &position);
}