#include "Player.h"
#include "TextureManager.h"
#include"Game.h"
#include"Collider.h"
#include"Animation.h"

bool Player::coliziune = 0;
bool Player::sare = 0;
int Player ::saritura = 0;
int Player ::animatie = 0;

Player::Player(const char* path1, const char* path2, const char* path3, const char* path4, const char* path5, const char* path6, SDL_Renderer* renderer)
{
	setTex(path1,path2,path3,path4,path5,path6);
}

void Player::setTex(const char* path1, const char* path2, const char* path3, const char* path4, const char* path5, const char* path6)
{
   texture1 = TextureManager::LoadTexture(path1);
   texture2 = TextureManager::LoadTexture(path2);
   texture3 = TextureManager::LoadTexture(path3);
   texture4 = TextureManager::LoadTexture(path4);
   texture5 = TextureManager::LoadTexture(path5);
   texture6 = TextureManager::LoadTexture(path6);
}


void Player::init()
{
   srcRect.x = srcRect.y = 0;
   srcRect.w = 32;
   srcRect.h = 24;
   destRect.w = 32;
   destRect.h = 24;
}

void Player::update()
{
	SDL_PollEvent(&Game::event);
	if (Game::event.type == SDL_KEYDOWN)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:                              //buton de sarit in fata
			if (Game::mapChosen)
			{
				sare = true;
				Mix_PlayChannel(-1, jumpEffect, 0);
			}
			break;
		case SDLK_a:
			if (Game::mapChosen)
			{
				xvelocity = -1;
			}
			break;
		case SDLK_m:                        //buton pentru oprit/pornit muzica
			if (Game::onoffmusic)
			{
				Game::onoffmusic = false;
				Mix_PlayMusic(backgroundSound, -1);
				break;
			}
			else
			{
				Mix_PauseMusic();
				Game::onoffmusic = true;
			}
			break;
		default:
			break;
		}
	}
	if (Game::event.type == SDL_KEYUP)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			yvelocity = 0;
			break;
		case SDLK_a:
			xvelocity = 0;
			break;
		case SDLK_ESCAPE:
			Game::isRunning = false;
			break;
		default:
			break;
		}
	}
}

void Player::draw()
{
	if (Game::characterChosen)
	{
		switch (Game::chooseCharacterflag)
		{
		case 1:
			Animation::draw(texture1, texture2, srcRect, destRect, 30);
			break;
		case 2:
			Animation::draw(texture3, texture4, srcRect, destRect, 30);
			break;
		case 3:
			Animation::draw(texture5, texture6, srcRect, destRect, 30);
			break;
		default:
			break;
		}
	}
	checkCollision();
}

void Player::checkCollision()// verificam daca au loc coliziuni printr o variabila temporara si apoi dam update pozitiilor daca nu 
{                            //sau oprim jocul daca au loc coliziuni cu obiecte nepermise
	int gravity = 2;
	int pspeed = 2;
	int tempx, tempy;
	tempx = destRect.x + xvelocity * pspeed;
	if (sare == 1)
	{
		tempy = destRect.y - 4;
	}
	else
	{
		if (saritura == 0)
			tempy = destRect.y + gravity;
		else
			tempy = destRect.y;
	}
	if (tempx < 0)
		destRect.x = 0;
	if (tempy < 0)
		destRect.y = 0;
	if (tempx > 1000)
		destRect.x = 1000;
	if (!ColliderComponent::Ecollision({ tempx, tempy, 29, 21 }))
	{
		if (saritura != 0)
		{
			destRect.x += xvelocity * pspeed;
		}
		else
		{
			destRect.x += xvelocity * pspeed;
			destRect.y += gravity;
		}
	}
	else
	{
		if (ColliderComponent::epamantflag == 0)
		{
			coliziune = 1;
		}
		{
			if (saritura != 0)
			{
				destRect.x += xvelocity * pspeed;
			}
			else
			{
				destRect.x += xvelocity * pspeed;
			}
		}
	}
	if (Player::sare == 1)
	{
		destRect.y -= 3;
		destRect.x += 3;
		if (Player::saritura == 27)
		{
			Player::sare = 0;
			Player::saritura = 0;
		}
		else
		{
			Player::saritura += 3;
		}
	}
}