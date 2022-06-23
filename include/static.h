#ifndef STATIC_H
#define STATIC_H

#include "object.h"

struct Static: public Object {
	int health;
	
	Static();
	Static(Static & copy);
	Static & operator=(Static & copy);
	virtual ~Static();

	int Initialize(std::fstream * file);
	virtual void Update(int mouse_x, int mouse_y, bool is_mouse_pressed, int timer);
	virtual void Draw(SDL_Renderer * renderer);
};

#endif // STATIC_H