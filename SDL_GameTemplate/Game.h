#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include"Coordonate.h"
#include"SDL_mixer.h"

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update() const;
	void render() const;
	void clean() const;

	bool running() const { return isRunning;  }

	static SDL_Event event;

	static bool mousepressedstart;
	static bool startFlag;
	static bool exitflag;
	static bool musicflag;
	static bool onoffmusic;
	static bool isRunning;
	static int chooseCharacterflag;
	static bool characterChosen;
	static bool replayflag;
	static bool levelpassed;
	static bool mapChosen;
	static int chooseMapFlag;
	static bool levelPassedSoundEffect;

	static SDL_Renderer* renderer;
	static SDL_Window* window;

	static Mix_Music* backgroundSound; 
	static Mix_Chunk* winEffect ;

	static bool mouse(SDL_Rect temp);
	static Coordonate mouse();
	static void wineffect();
	static void PlayorStopMusic();
};
