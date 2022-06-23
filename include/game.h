#ifndef GAME_H
#define GAME_H

#include <vector>
#include <typeinfo>
#include "object.h"
#include "button.h"

struct Game {
	SDL_Window * window;
	SDL_Renderer * renderer;
	SDL_Event event;
	std::vector<Object *> templates;
	std::vector<Object *> objects;
	//vector<vector<Plant*>> plants;
	//vector<vector<Projectile*>> projectiles;
	//vector<vector<Zombie*>> zombies;
	int game_state;
	int timer;
	bool is_mouse_pressed;
	
	Game();
	~Game();

	void Initialize();
	void Update();
	void Draw();
	
	void AddObject(Object * object);
	void DeleteObject(Object * object);
	void DeleteObjectGroup();
	void DeleteAllObjects();
	Object * GetObject(std::string key_word);
};

#endif // GAME_H