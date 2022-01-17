#pragma once
#include<iostream>
#include"TextureManager.h"
#include"Player.h"

struct Animation
{
	static void draw(SDL_Texture* texture1, SDL_Texture* texture2, SDL_Rect srcRect, SDL_Rect destRect,int speed)
	{
		if (Player::animatie <= (speed/2))
		{
			Player::animatie += 1;
			TextureManager::Draw(texture1, srcRect, destRect);
		}
		else
		{
			if (Player::animatie <= speed)
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