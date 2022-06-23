#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "ui.h"

struct Button: public UI {
	Button();
	Button(Button & copy);
	Button& operator=(Button & copy);
	virtual ~Button();

	int Initialize(std::fstream * file, int * game_state);
	virtual void Update(int mouse_x, int mouse_y, bool is_mouse_pressed, int timer);
	virtual void Draw(SDL_Renderer * renderer);
};

#endif // BUTTON_HPP