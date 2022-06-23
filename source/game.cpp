#include "game.h"
#include <iostream>

Game::Game():	window(nullptr),
				renderer(nullptr),
				templates(),
				objects(),
				game_state(GAME_STATE_IDLE),
				timer(0),
				is_mouse_pressed(false) {}

Game::~Game() {
	for (Object * object: objects) delete object;
	objects.clear();
	for (Object * object: templates) {
		SDL_DestroyTexture(object->texture);
		delete object;
	}
	templates.clear();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::Initialize() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Plants vs Zombies", RESOLUTION.x, RESOLUTION.y, RESOLUTION.w, RESOLUTION.h, 0);
	renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
	std::fstream file;
	file.open("..\\assets\\objects.txt", std::ios_base::in);
	std::cout << file.is_open() << '\n';
	for (std::string placeholder; !file.eof();) {
		file >> placeholder;
		if (placeholder != ".") {
			if (placeholder == "object") {
				Object* tmp = new Object();
				tmp->Initialize(&file);
				templates.push_back(tmp);
			} else if (placeholder == "button") {
				Button* tmp = new Button();
				tmp->Initialize(&file, &game_state);
				templates.push_back(tmp);
			}
			std::cout << "line: ";
			getline(file, placeholder);
			std::cout << placeholder << '\n';
		}
	}
	file.close();
	game_state = GAME_STATE_IDLE;
}

void Game::Update() {
	timer = timer++ % 1000;
	for (Object * object : objects) if (object->status == OBJECT_STATUS_DELETE) DeleteObject(object);

	switch (game_state) {
		case GAME_STATE_QUE_EXIT: {
			game_state = 0;
			return;
		}
		case GAME_STATE_IDLE: { break; }
		case GAME_STATE_MAIN: {
			DeleteAllObjects();

			Object* background;
			if (Object* prototype = dynamic_cast<Object *>(GetObject("background1"))) background = new Object(*prototype);
			background->position.x = 0;
			background->position.y = 0;
			AddObject(background);

			Button* menu_button1;
			if (Button* prototype = dynamic_cast<Button *>(GetObject("play"))) menu_button1 = new Button(*prototype);
			menu_button1->position.x = RESOLUTION.w / 2 - menu_button1->position.w / 2;
			menu_button1->position.y = RESOLUTION.h / 3 * 1 + menu_button1->position.h / 2;
			AddObject(menu_button1);

			Button* menu_button2;
			if (Button* prototype = dynamic_cast<Button *>(GetObject("exit"))) menu_button2 = new Button(*prototype);
			menu_button2->position.x = RESOLUTION.w / 2 - menu_button2->position.w / 2;
			menu_button2->position.y = RESOLUTION.h / 3 * 1 + menu_button2->position.h / 2;
			AddObject(menu_button2);
			
			game_state = GAME_STATE_IDLE;
			break;
		}
		case GAME_STATE_LEVELS: {
			DeleteAllObjects();

			Object* background = nullptr;
			if (Object* prototype = dynamic_cast<Object *>(GetObject("background1"))) background = new Object(*prototype);
			background->position.x = 0;
			background->position.y = 0;
			AddObject(background);

			Button* menu_button1 = nullptr;
			if (Button* prototype = dynamic_cast<Button *>(GetObject("lvl1"))) menu_button1 = new Button(*prototype);
			menu_button1->position.x = RESOLUTION.w / 2 - menu_button1->position.w / 2;
			menu_button1->position.y = RESOLUTION.h / 7 * 1 - menu_button1->position.h / 2;
			AddObject(menu_button1);

			Button* menu_button2 = nullptr;
			if (Button* prototype = dynamic_cast<Button *>(GetObject("lvl2"))) menu_button2 = new Button(*prototype);
			menu_button2->position.x = RESOLUTION.w / 2 - menu_button2->position.w / 2;
			menu_button2->position.y = RESOLUTION.h / 7 * 2 - menu_button2->position.h / 2;
			AddObject(menu_button2);

			Button* menu_button3 = nullptr;
			if (Button* prototype = dynamic_cast<Button *>(GetObject("lvl3"))) menu_button3 = new Button(*prototype);
			menu_button3->position.x = RESOLUTION.w / 2 - menu_button3->position.w / 2;
			menu_button3->position.y = RESOLUTION.h / 7 * 3 - menu_button3->position.h / 2;
			AddObject(menu_button3);

			Button* menu_button4 = nullptr;
			if (Button* prototype = dynamic_cast<Button *>(GetObject("lvl4"))) menu_button4 = new Button(*prototype);
			menu_button4->position.x = RESOLUTION.w / 2 - menu_button4->position.w / 2;
			menu_button4->position.y = RESOLUTION.h / 7 * 4 - menu_button4->position.h / 2;
			AddObject(menu_button4);

			Button* menu_button5 = nullptr;
			if (Button* prototype = dynamic_cast<Button *>(GetObject("lvl5"))) menu_button5 = new Button(*prototype);
			menu_button5->position.x = RESOLUTION.w / 2 - menu_button5->position.w / 2;
			menu_button5->position.y = RESOLUTION.h / 7 * 5 - menu_button5->position.h / 2;
			AddObject(menu_button5);

			Button* menu_button6 = nullptr;
			if (Button* prototype = dynamic_cast<Button *>(GetObject("back"))) menu_button6 = new Button(*prototype);
			menu_button6->position.x = RESOLUTION.w / 2 - menu_button6->position.w / 2;
			menu_button6->position.y = RESOLUTION.h / 7 * 6 - menu_button6->position.h / 2;
			AddObject(menu_button6);

			game_state = GAME_STATE_IDLE;
			break;
		}
		case GAME_STATE_PLAYING: {
			game_state = GAME_STATE_IDLE;
			break;
		}
	}
	SDL_PollEvent(&event);
	if (is_mouse_pressed && event.button.state == SDL_RELEASED) is_mouse_pressed = false;
	else if (!is_mouse_pressed && event.button.state == SDL_PRESSED) is_mouse_pressed = true;
	for (Object * object: objects) if (object != nullptr) object->Update(event.button.x, event.button.y, is_mouse_pressed, timer);
}

void Game::Draw() {
	std::cout << "I got to here";
	for (Object * object: templates) object->Draw(renderer);
	std::cout << ", but maybe not here.";
	SDL_RenderPresent(renderer);
	SDL_Delay(10000);
}

void Game::AddObject(Object * object) {
	objects.push_back(object);
}

void Game::DeleteObject(Object * object) {
	for (std::vector<Object  *>::iterator itr = objects.begin(); itr != objects.end(); itr++) {
		if (object == (*itr)) {
			delete *itr;
			objects.erase(itr);
			return;
		}
	}
}

void Game::DeleteAllObjects() {
	for (std::vector<Object  *>::iterator itr = objects.begin(); itr != objects.end(); itr++) delete *itr;
	objects.clear();
}

Object * Game::GetObject(std::string key_word) {
	for (Object * object: objects) if (object->key_word == key_word) return object;
	return nullptr;
}