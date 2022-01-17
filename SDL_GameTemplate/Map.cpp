#include "Map.h"
#include "TextureManager.h"
#include <SDL.h>
#include "collider.h"

int Map::mapindex = 0;

int lvl1[20][25] = {
	0,0,0,0,9,0,0,9,9,0,9,9,0,9,0,9,0,9,0,9,5,0,9,0,0,
	0,0,0,0,9,0,5,9,9,0,9,9,0,9,0,9,0,9,5,9,0,5,9,0,5,
	0,0,5,0,9,0,0,9,9,5,9,9,5,9,5,9,0,9,0,9,0,0,9,0,0,
	0,0,0,0,9,0,0,9,9,0,9,9,0,9,0,9,5,9,0,9,0,5,9,5,0,
	0,5,0,0,9,5,0,9,9,0,9,9,0,9,0,9,0,9,0,9,0,0,9,0,0,
	0,0,0,0,9,0,0,9,9,0,9,9,0,9,0,3,0,9,5,9,0,0,9,0,0,
	0,0,0,0,9,0,0,9,3,0,3,3,5,9,0,0,0,3,0,3,0,0,9,0,5,
	5,0,0,0,3,0,0,3,0,5,0,0,0,3,0,0,0,0,0,0,0,0,3,0,0,
	0,0,0,0,0,0,5,0,0,0,0,5,0,0,0,0,0,5,0,0,5,0,0,5,0,
	0,0,5,0,0,0,0,0,0,0,11,0,0,0,5,0,0,11,0,11,0,0,0,0,17,
	7,7,7,7,7,13,7,13,7,7,12,13,7,7,13,7,7,12,7,12,7,13,7,7,7,
	1,1,1,1,1,8,1,8,1,1,8,8,1,1,8,1,1,8,1,8,1,8,1,1,1,
	1,1,1,1,1,8,1,8,1,1,8,8,1,1,8,1,1,8,1,8,1,8,1,1,1,
	1,1,1,1,1,8,1,8,1,1,8,8,1,1,8,1,1,8,1,10,1,8,1,1,1,
	1,1,1,1,1,8,1,8,1,1,10,10,1,1,8,1,1,8,1,1,1,8,1,1,1,
	1,1,1,1,1,8,1,10,1,1,1,1,1,1,8,1,1,8,1,1,1,8,1,1,1,
	1,1,1,1,1,8,1,1,1,1,1,1,1,1,10,1,1,8,1,1,1,8,1,1,1,
	1,1,1,1,1,8,1,1,1,1,1,1,1,1,1,1,1,8,1,1,1,8,1,1,1,
	1,1,1,1,1,8,1,1,1,1,1,1,1,1,1,1,1,10,1,1,1,10,1,1,1,
	1,1,1,1,1,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,

}; 
int lvl2[20][25] = {
	0,0,0,0,9,0,0,9,9,0,9,9,0,9,9,9,0,9,9,0,9,0,9,0,0,
	0,0,0,0,9,0,5,9,9,0,9,9,0,9,9,9,0,9,9,0,9,5,9,0,5,
	0,0,5,0,9,0,0,9,9,5,9,9,5,9,9,9,0,9,3,0,9,0,9,0,0,
	0,0,0,0,9,0,0,9,9,0,9,9,0,9,9,9,5,9,0,0,9,5,9,5,0,
	0,5,0,0,9,5,0,9,9,0,9,9,0,9,9,9,0,9,0,0,9,0,9,0,0,
	0,0,0,0,9,0,0,9,9,0,9,9,0,9,9,3,0,3,5,0,9,0,9,0,0,
	0,0,0,0,3,0,0,3,3,0,3,3,5,9,9,0,0,0,0,0,3,0,9,0,5,
	5,0,0,0,0,0,0,0,0,5,0,0,0,3,3,0,0,0,0,0,0,0,3,0,0,
	0,0,0,0,0,0,5,0,0,0,0,5,0,0,0,0,0,11,0,0,5,0,0,5,0,
	0,0,5,0,0,11,0,0,0,0,11,0,0,0,5,0,0,9,11,0,0,0,0,0,17,
	7,7,13,7,7,12,7,13,7,13,12,13,7,7,13,7,7,12,12,7,7,13,7,7,7,
	1,1,8,1,1,8,1,8,1,8,8,8,1,1,8,1,1,8,8,1,1,8,1,1,1,
	1,1,8,1,1,8,1,8,1,8,8,8,1,1,8,1,1,8,8,1,1,8,1,1,1,
	1,1,8,1,1,8,1,8,1,8,8,8,1,1,8,1,1,8,10,1,1,8,1,1,1,
	1,1,10,1,1,8,1,8,1,1,10,10,1,1,8,1,1,8,1,1,1,8,1,1,1,
	1,1,1,1,1,8,1,10,1,1,1,1,1,1,8,1,1,8,1,1,1,8,1,1,1,
	1,1,1,1,1,8,1,1,1,1,1,1,1,1,10,1,1,8,1,1,1,8,1,1,1,
	1,1,1,1,1,8,1,1,1,1,1,1,1,1,1,1,1,8,1,1,1,8,1,1,1,
	1,1,1,1,1,8,1,1,1,1,1,1,1,1,1,1,1,10,1,1,1,10,1,1,1,
	1,1,1,1,1,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,

}; 
int lvl3[20][25] = {
	0,0,0,0,9,0,0,9,9,0,9,9,0,9,0,9,0,9,9,0,9,0,9,9,0,
	0,0,0,0,9,0,5,9,9,0,9,9,0,9,0,9,0,9,9,0,9,5,9,9,5,
	0,0,5,0,9,0,0,9,9,5,9,9,5,9,0,9,0,9,3,0,9,0,9,9,0,
	0,0,0,0,9,0,0,9,9,0,9,9,0,9,0,9,5,9,0,0,9,5,9,9,0,
	0,5,0,0,9,5,0,9,9,0,9,9,0,9,0,9,0,9,0,0,9,0,9,9,0,
	0,0,0,0,9,0,0,9,9,0,9,9,0,9,0,3,0,3,5,0,9,0,9,9,0,
	0,0,0,0,3,0,0,9,3,0,3,3,5,9,0,0,0,0,0,0,3,0,3,3,5,
	5,0,11,0,0,0,0,3,0,5,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,
	0,0,9,0,0,0,5,0,0,0,0,5,0,0,0,0,0,11,0,0,5,0,0,5,0,
	0,0,9,0,0,0,0,0,0,0,11,0,0,0,5,0,0,9,11,0,0,11,0,0,17,
	7,7,12,7,7,13,7,13,7,13,12,7,7,7,13,7,7,12,12,7,7,12,7,7,7,
	1,1,8,1,1,10,1,8,1,8,8,1,1,1,8,1,1,8,8,1,1,8,1,1,1,
	1,1,8,1,1,1,1,8,1,8,8,1,1,1,8,1,1,8,8,1,1,8,1,1,1,
	1,1,8,1,1,1,1,8,1,8,8,1,1,1,8,1,1,8,10,1,1,10,1,1,1,
	1,1,10,1,1,1,1,8,1,1,10,1,1,1,8,1,1,10,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,10,1,1,1,1,1,1,8,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,10,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};


int Map::map1[20][25];
int Map::map2[20][25];
int Map::map3[20][25];

Map::Map(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	 zero = TextureManager::LoadTexture("assets/0.png");
	 unu = TextureManager::LoadTexture("assets/1.png");
	 doi = TextureManager::LoadTexture("assets/2.png");
	 trei = TextureManager::LoadTexture("assets/3.png");
	 cinci = TextureManager::LoadTexture("assets/5.png");
	 opt = TextureManager::LoadTexture("assets/8.png");
	 noua = TextureManager::LoadTexture("assets/9.png");
	 zece = TextureManager::LoadTexture("assets/10.png");
	 unspe = TextureManager::LoadTexture("assets/11.png");
	finish = TextureManager::LoadTexture("assets/finish.png");
	sapte = TextureManager::LoadTexture("assets/7.png");
	doispe = TextureManager::LoadTexture("assets/12.png");
	treispe = TextureManager::LoadTexture("assets/13.png");
	LoadMap(lvl1,lvl2,lvl3);
		
	src = { 0,0,32,32 };
	dest = { 0,0,40,40 };
}

Map::~Map(){}

void Map::LoadMap(int arr1[20][25], int arr2[20][25], int arr3[20][25])//incarcam pozitiile pentru mape
{
	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			map1[row][column] = arr1[row][column];
			map2[row][column] = arr2[row][column];
			map3[row][column] = arr3[row][column];
		}
	}
}

void Map::LoadMap(int arr1[20][25],int arr2[20][25])
{
	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			arr1[row][column] = arr2[row][column];
		}
	}
}

void Map::DrawMap()
{
	int type = 0;
	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			switch (mapindex)//verificam mapa pe care o incarcam
			{
			case 1:
				type = map1[row][column];
				break; 
			case 2:
				type = map2[row][column];
				break;
			case 3:
				type = map3[row][column];
				break;
			default:
				break;
			}
			
			dest.x = column * 40;//setam dimensiunile pentru patratelele mapei
			dest.y = row * 40;
			switch (type)//in functie de indice incarcam patratelul potrivit
			{
			case 0:
				TextureManager::Draw(zero, src, dest);
				break;
			case 1:
				TextureManager::Draw(unu, src, dest);
				break;
			case 2:
				TextureManager::Draw(doi, src, dest);
				break;
			case 3:
				TextureManager::Draw(trei, src, dest);
				break;
			case 5:
				TextureManager::Draw(cinci, src, dest);
				break;
			case 8:
				TextureManager::Draw(opt, src, dest);
				break;
			case 7:
				TextureManager::Draw(sapte, src, dest);
				break;
			case 9:
				TextureManager::Draw(noua, src, dest);
				break;
			case 10:
				TextureManager::Draw(zece, src, dest);
				break;
			case 11:
				TextureManager::Draw(unspe, src, dest);
				break;
			case 12:
				TextureManager::Draw(doispe, src, dest);
				break;
			case 13:
				TextureManager::Draw(treispe, src, dest);
				break;
			case 17:
				TextureManager::Draw(finish, src, dest);
				break;
			default:
				break;
			}
		}
	}
}
