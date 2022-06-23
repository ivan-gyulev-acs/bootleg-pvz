#ifndef UI_H
#define UI_H

#include "object.h"

struct UI: public Object {
	int * game_state;
	int return_value;

	UI();
	UI(UI & copy);
	UI & operator=(UI & copy);
	virtual ~UI();

	int Initialize(std::fstream * file, int * game_state);
	virtual void Update(int mouse_x, int mouse_y, bool is_mouse_pressed, int timer);
	virtual void Draw(SDL_Renderer * renderer);
};

#endif // UI_H