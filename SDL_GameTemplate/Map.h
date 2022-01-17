#pragma once
#include <SDL_image.h>

class Map
{
public:
	Map(SDL_Renderer* renderer);
	~Map();
	static int map1[20][25];
	static int map2[20][25];
	static int map3[20][25];
	void LoadMap(int arr1[20][25], int arr2[20][25], int arr3[20][25]);
	static void LoadMap(int arr1[20][25],int arr2[20][25]);
	void DrawMap();	

	static int mapindex;

private:

	SDL_Renderer* renderer;
	SDL_Rect src, dest;

	SDL_Texture* zero;
	SDL_Texture* unu;
	SDL_Texture* doi;
	SDL_Texture* trei;
	SDL_Texture* cinci;
	SDL_Texture* opt;
	SDL_Texture* noua;
	SDL_Texture* zece;
	SDL_Texture* unspe;
	SDL_Texture* finish;
	SDL_Texture* doispe;
	SDL_Texture* treispe;
	SDL_Texture* sapte;
};