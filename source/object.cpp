#include "object.h"

Object::Object(): key_word(""), texture(nullptr), status(BUTTON_STATUS_IDLE) {
	sprite = {0, 0, 0, 0};
	position = {0, 0, 0, 0};
}

Object::Object(Object & copy):	key_word(copy.key_word),
								texture(copy.texture),
								sprite(copy.sprite),
								position(copy.position),
								status(copy.status) {}

Object & Object::operator=(Object & copy) {
	if (&copy == this) return *this;
	key_word = copy.key_word;
	texture = copy.texture;
	sprite = copy.sprite;
	position = copy.position;
	status = copy.status;
	return *this;
}

Object::~Object() {}

int Object::Initialize(std::fstream* file) {
	(*file) >> key_word;
	std::string placeholder;
	(*file) >> placeholder;
	texture = LoadTexture(renderer, placeholder);
	(*file) >> sprite.w;
	(*file) >> sprite.h;
	position.w = sprite.w * SCALE;
	position.h = sprite.h * SCALE;
	return 0;
}

void Object::Update(int mouse_x, int mouse_y, bool is_mouse_pressed, int timer) {}

void Object::Draw(SDL_Renderer * renderer) {
	SDL_RenderCopy(renderer, texture, &sprite, &position);
}