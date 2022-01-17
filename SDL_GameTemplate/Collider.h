#pragma once
#include"string"
#include"SDL.h"
#include"Game.h"
#include"Component.h"
#include"Map.h"

using namespace std;

class ColliderComponent:public Component
{
public:

	static bool epamantflag;

	SDL_Rect collider;
	string tag;

	SDL_Texture* tex;
	SDL_Rect srcR, destR;

	ColliderComponent(string t, int xpos, int ypos, int size);
	void init();

	void update() override;
	void draw();
	static bool AABB(const SDL_Rect& A, const SDL_Rect& B);
	static bool Ecollision(SDL_Rect player);
};
