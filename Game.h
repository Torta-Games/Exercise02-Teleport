#pragma once

#include "SDL/include/SDL.h"
#include "SDL_image/include/SDL_image.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )
#pragma comment( lib, "SDL_image/libx86/SDL2_image.lib" )


#include "Entity.h"

#define WINDOW_WIDTH	1024
#define WINDOW_HEIGHT	768
#define MAX_KEYS		256
#define MAX_SHOTS		32

class Game
{
public:
	Game();
	~Game();

	bool Init();
	bool LoadImages();
	void Release();
	
	bool Input();
	bool Update();
	void Draw();

private:
	SDL_Window *Window;
	SDL_Renderer *Renderer;
	SDL_Texture *img_background, *img_player, *img_shot, *img_box, *img_platform;

	Entity Player, Box, Platform1, Platform2, Shots[MAX_SHOTS], Scene;
	int idx_shot;

	bool god_mode;
	SDL_Rect rc;
	SDL_Rect ra;
	SDL_Rect rp;
	SDL_Rect rp2;

	int cameraY;
	int currentPlatform;
	float previousTime = 0;
	
	int changePosition1 = 600;
	int changePosition2 = 20;

	bool right = true;

	enum KEY_STATE { KEY_IDLE, KEY_DOWN, KEY_REPEAT, KEY_UP	};
	KEY_STATE keys[MAX_KEYS]; 
};
