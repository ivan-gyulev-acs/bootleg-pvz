#ifndef GLOBAL_H
#define GLOBAL_H

#include <cmath>
#include <string>
#include <fstream>
#include <SDL2/SDL.h>

SDL_Texture * LoadTexture(SDL_Renderer * renderer, std::string file_path);

const int SCALE = 4;
const SDL_Rect RESOLUTION = {0, 0, 480 * SCALE, 270 * SCALE};

const int GAME_STATE_QUE_EXIT = 1;
const int GAME_STATE_IDLE = 2;
const int GAME_STATE_MAIN = 3;
const int GAME_STATE_LEVELS = 4;
const int GAME_STATE_PLAYING = 5;

const int BUTTON_STATUS_IDLE = 1;
const int BUTTON_STATUS_PRESSED = 2;

const int OBJECT_STATUS_DELETE = 0;

#endif // GLOBAL_H