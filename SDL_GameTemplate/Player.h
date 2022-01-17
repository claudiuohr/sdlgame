#pragma once
#include "Component.h"
#include "SDL.h"
#include "SDL_mixer.h"

class Player : public Component
{
public:
	SDL_Texture* texture1{};
	SDL_Texture* texture2{};
	SDL_Texture* texture3{};
	SDL_Texture* texture4{};
	SDL_Texture* texture5{};
	SDL_Texture* texture6{};
	SDL_Renderer* renderer{};

	SDL_Rect srcRect{}, destRect{};

	Mix_Music* backgroundSound = Mix_LoadMUS("assets/background.mp3");
	Mix_Chunk* jumpEffect = Mix_LoadWAV("assets/jump.flac");

	int xvelocity = 0;
	int yvelocity = 0;

	static bool sare;
	static bool coliziune;
	static int saritura;
	static int animatie;

    Player() = default;
    Player(const char* path1, const char* path2, const char* path3, const char* path4, const char* path5, const char* path6, SDL_Renderer* renderer);

	void checkCollision();
	void setTex(const char* path1, const char* path2,const char* path3, const char* path4,const char* path5, const char* path6);

	void init() override;

	void update() override;

	void draw() override;
};
