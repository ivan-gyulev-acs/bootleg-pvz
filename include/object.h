#ifndef OBJECT_H
#define OBJECT_H

#include "global.h"

struct Object {
	std::string key_word;
	SDL_Renderer * renderer;
	SDL_Texture * texture;
	SDL_Rect sprite;
	SDL_Rect position;
	int status;
	
	Object();
	Object(Object & copy);
	Object & operator=(Object & copy);
	virtual ~Object();

	int Initialize(std::fstream * file);
	virtual void Update(int mouse_x, int mouse_y, bool is_mouse_pressed, int timer);
	virtual void Draw(SDL_Renderer * renderer);
};

#endif // OBJECT_H