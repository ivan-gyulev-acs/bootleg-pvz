#ifndef PLANT_H
#define PLANT_H

#include "static.h"

struct Plant: public Static {
	int cost;
	int cooldown;
	int fire_rate;
	
	Plant();
	Plant(Plant & copy);
	Plant &operator=(Plant & copy);
	virtual ~Plant();

	virtual int Initialize(std::fstream * file);
	virtual void Update(int mouse_x, int mouse_y, bool is_mouse_pressed, int timer);
	virtual void Draw(SDL_Renderer * renderer);
};

#endif // PLANT_H