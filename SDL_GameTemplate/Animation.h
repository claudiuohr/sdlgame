#pragma once
#include<iostream>
#include"TextureManager.h"
#include"Player.h"

struct Animation
{
	static void draw(SDL_Texture* texture1, SDL_Texture* texture2, SDL_Rect srcRect, SDL_Rect destRect,int speed)//functie pentru a afisa o animatie
	{
		if (Player::animatie <= (speed/2))//de atatea ori va afisa prima imagine plus cazul in care punem animatie pe 0 pentru a reseta efectul
		{
			Player::animatie += 1;
			TextureManager::Draw(texture1, srcRect, destRect);
		}
		else
		{
			if (Player::animatie <= speed)//de atatea ori va afisa a doua imagine pentru ca afisarea celor 2 imagini sa fie egala si sa para mai realista
			{
				Player::animatie += 1;
				TextureManager::Draw(texture2, srcRect, destRect);
			}
			else
			{
				Player::animatie = 0;
				TextureManager::Draw(texture1, srcRect, destRect);
			}
		}

	}
};
