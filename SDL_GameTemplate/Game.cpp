#include "Game.h"
#include <iostream>
#include "Map.h"
#include "Player.h"
#include "TextureManager.h"
#include "Coordonate.h"
#include "Animation.h"
#include "Collider.h"
#include "SDL_mixer.h"

using namespace std;

int  Game::chooseCharacterflag = 0;
bool Game::isRunning = false;
bool Game::mousepressedstart = false;
bool Game::exitflag = false;
bool  Game::musicflag =false;
bool Game::onoffmusic = false;
bool Game::startFlag = false;
bool Game::characterChosen = false;
bool Game::replayflag = false;
bool Game::levelpassed = false;
bool Game::mapChosen = false;
int  Game::chooseMapFlag = 0;
bool Game::levelPassedSoundEffect = false;

Map* map;
Player *player;

Mix_Music* Game::backgroundSound;
Mix_Chunk* Game::winEffect;

SDL_Texture* start;
SDL_Texture* chooseCharacter;
SDL_Texture* level1Passed;
SDL_Texture* level2Passed;
SDL_Texture* level3Passed;
SDL_Texture* gameover;
SDL_Texture* levels;
SDL_Texture* congrats;

SDL_Renderer* Game::renderer = 0;
SDL_Window* Game::window = 0;
SDL_Event Game::event;

Game::Game(){}

Game::~Game()
{
   delete player;
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING|SDL_INIT_AUDIO) == 0)
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2,2048);
		std::cout << "Subsystems initialized" << std::endl;
		auto window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window!=nullptr)
		{
			std::cout << "Window created" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer != nullptr)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255,255);
			std::cout << "Renderer created" << std::endl;
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	Mix_Music* backgroundSound = Mix_LoadMUS("assets/background.mp3");
	Mix_Chunk* winEffect = Mix_LoadWAV("assets/win.wav");

	Mix_PlayMusic(backgroundSound, -1);

	start = TextureManager::LoadTexture("assets/start.png");
	chooseCharacter= TextureManager::LoadTexture("assets/choosecharacter.png");
	level1Passed = TextureManager::LoadTexture("assets/level1.png");
	level2Passed = TextureManager::LoadTexture("assets/level2.png");
	level3Passed = TextureManager::LoadTexture("assets/level3.png");
	gameover = TextureManager::LoadTexture("assets/gameover.png");
	levels = TextureManager::LoadTexture("assets/levels.png");
	congrats = TextureManager::LoadTexture("assets/congrats.png");

    map = new Map(renderer);

    player = new Player ("assets/player1.png", "assets/player2.png", "assets/player3.png", "assets/player4.png", "assets/player5.png", "assets/player6.png", renderer);
    player->init();
}

void Game::handleEvents()
{
	switch (Game::event.type)
	{
	case SDL_QUIT: {
		isRunning = false;
		break;
	}
	default:
		break;
	}
}
void Game::update() const
{
	if (startFlag == false)//verificam daca a fost apasat o data pe start
	{
		mousepressedstart = mouse({ 344,232,311,60 }) ? true : false;//verificam daca a fost apast cu click stanga dreptunghiul de start
		if (mousepressedstart)
			startFlag = true;//daca da,trecem la urmatorul ecran
		exitflag = mouse({ 392,370,216,60 }) ? true : false;//verificam daca a fost apasat cu click stanga dreptunghiul exit
		if (exitflag)
			isRunning = 0;//daca da, oprim jocul
	}

	if (characterChosen == false && startFlag == true)// verificam daca si ce caracter a ales
	{
		SDL_Rect first{ 190,352,128,96 };// dreptunghiurile pentru cele trei caractere din care putem alege
		SDL_Rect second{ 436,352,128,96 };
		SDL_Rect third{ 682,352,128,96 };

		Coordonate aux = mouse();//punem in aux coordonatele locului in care s a apasat click stanga

		if (aux.x > first.x && aux.x < first.x + first.w)//in urmatoarele 3 for uri verificam daca a fost ales vreun caracter si care
		{
			if (aux.y > first.y && aux.y < first.y + first.h)
			{
				chooseCharacterflag = 1;
				characterChosen = true;//vom iesi din acest if si vom trece la urmatorul ecran
			}
		}

		if (aux.x > second.x && aux.x < second.x + second.w)
		{
			if (aux.y > second.y && aux.y < second.y + second.h)
			{
				chooseCharacterflag = 2;
				characterChosen = true;
			}
		}

		if (aux.x > third.x && aux.x < third.x + third.w)
		{
			if (aux.y > third.y && aux.y < third.y + third.h)
			{
				chooseCharacterflag = 3;
				characterChosen = true;
			}
		}
	}
	if (characterChosen == true && mapChosen == false)// verificam daca a ales mapa si care anume
	{
		SDL_Rect lvl1{ 380,135,239,60 };//coordonatele patratelor celor 3 nivele din care poate alege jucatorul
		SDL_Rect lvl2{ 374,295,251,60 };
		SDL_Rect lvl3{ 374,455,251,60 };

		Coordonate aux = mouse();//punem in aux coordonatele locului in care s a apasat click stanga

		if (aux.x > lvl1.x && aux.x < lvl1.x + lvl1.w)//in urmatoarele 3 for uri verificam daca a fost ales vreun caracter si care
		{
			if (aux.y > lvl1.y && aux.y < lvl1.y + lvl1.h)
			{
				Map::mapindex = 1;
				mapChosen = true;//vom iesi din acest if si vom trece la urmatorul ecran
			}
		}

		if (aux.x > lvl2.x && aux.x < lvl2.x + lvl2.w)
		{
			if (aux.y > lvl2.y && aux.y < lvl2.y + lvl2.h)
			{
				Map::mapindex = 2;
				mapChosen = true;
			}
		}

		if (aux.x > lvl3.x && aux.x < lvl3.x + lvl3.w)
		{
			if (aux.y > lvl3.y && aux.y < lvl3.y + lvl3.h)
			{
				Map::mapindex = 3;
				mapChosen = true;
			}
		}
	}

	player->update();
}

void Game::render() const
{
	if (mousepressedstart == true) //test daca iese din start
	{
		if (chooseCharacterflag != 0) //test daca a ales caracterul
		{
			if (mapChosen == true)//test daca a ales mapa
			{
				if (Player::coliziune == 0 && levelpassed == 0)//test daca a trecut nivelul sau s a lovit
				{
					SDL_RenderClear(renderer);
					map->DrawMap();
					player->draw();
					SDL_RenderPresent(renderer);
				}
				else
				{
					if (levelpassed == 1)//caz in care trece nivelul
					{
						levelPassedSoundEffect = 1;
						switch (Map::mapindex)//afisarea ecranelor de nivel trecut in functie de numarul nivelului
						{
						case 1:

							SDL_RenderClear(renderer);
							TextureManager::Draw(level1Passed, { 0,0,1000,800 }, { 0,0,1000,800 });
							SDL_RenderPresent(renderer);
							break;
						case 2:
							SDL_RenderClear(renderer);
							TextureManager::Draw(level2Passed, { 0,0,1000,800 }, { 0,0,1000,800 });
							SDL_RenderPresent(renderer);
							break;
						case 3:
							SDL_RenderClear(renderer);
							TextureManager::Draw(level3Passed, { 0,0,1000,800 }, { 0,0,1000,800 });
							TextureManager::Draw(congrats, { 0,0,1000,800 }, { 0,0,1000,800 });
							SDL_RenderPresent(renderer);
							SDL_Delay(2000);
							isRunning = 0;
							break;
						default:
							break;
						}
						
						if (Map::mapindex < 4)//caz in care termina nivelele
						{
							SDL_Delay(3000);
							Map::mapindex++;
							levelpassed = 0;
							Player::coliziune = 0;
							player->destRect = { 0,0,32,24 };
							ColliderComponent::epamantflag = 1;
						}
					}
					if (Player::coliziune == 1)//caz in care s a lovit
					{
						SDL_RenderClear(renderer);
						TextureManager::Draw(gameover, { 0, 0, 1000, 800 }, { 0, 0, 1000, 800 });//afisam meniul de game over 
						SDL_RenderPresent(renderer);
						replayflag = mouse({ 303,370,394,60 }) ? true : false;//poate alege daca doreste sa reia nivelul de la inceput sau sa nu mai joace
						exitflag = mouse({ 392,494,216,60 }) ? true : false;
						if (exitflag)//daca alege sa nu mai joace ,jocul se va inchide
							isRunning = 0;
						if (replayflag == 1)//daca doreste sa joace din nou va fi incepe nivelul de la pozitia initiala
						{
							Player::coliziune = 0;
							player->destRect = { 0,0,32,24 };
							ColliderComponent::epamantflag = 1;
						}
					}
				}
			}
			else
			{
				SDL_RenderClear(renderer);
				TextureManager::Draw(levels, { 0, 0, 1000, 800 }, { 0, 0, 1000, 800 });//afisare meniu de a alege nivelele
				SDL_RenderPresent(renderer);
			}
		}
		else
		{
			SDL_RenderClear(renderer);
			TextureManager::Draw(chooseCharacter, { 0, 0, 1000, 800 }, { 0, 0, 1000, 800 });//afisare meniu de caractere
			Animation::draw(player->texture1, player->texture2, player->srcRect, { 190,352,128,96 },60);
			Animation::draw(player->texture3, player->texture4, player->srcRect, { 436,352,128,96 },60);
			Animation::draw(player->texture5, player->texture6, player->srcRect, { 682,352,128,96 },60);
			SDL_RenderPresent(renderer);
		}
	}
	else
	{
		SDL_RenderClear(renderer);//afisare ecran start
		TextureManager::Draw(start, { 0, 0, 1000, 800 }, { 0, 0, 1000, 800 });
		SDL_RenderPresent(renderer);
	}
}

void Game::clean() const
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	Mix_FreeMusic(backgroundSound);
	Mix_CloseAudio();
	SDL_QUIT;
	std::cout << "Game cleaned" << std::endl;
}


bool Game::mouse(SDL_Rect temp)// returneaza daca mouse ul este apasat intr un anume patrat
{
	Uint32 buttons;
	int x, y;
	SDL_PumpEvents();
	buttons = SDL_GetMouseState(&x, &y);//primeste coordonatele locului in care s a apasat click stanga
	
	if ((buttons & SDL_BUTTON_LEFT) != 0)
	{
		SDL_Log("Mouse Button 1 (left) is pressed.");
		cout << "Coords : " << x << ' ' << y << '\n';
		if (x > temp.x && x < temp.x + temp.w)
		{
			if (y > temp.y && y < temp.y + temp.h)
			{
				return true;
			}
		}
	}
	return false;
}
Coordonate Game::mouse() // returneaza coordonatele punctului apasat de mouse
{
	Uint32 buttons;
	int x, y;
	SDL_PumpEvents();
	buttons = SDL_GetMouseState(&x, &y);
	if ((buttons & SDL_BUTTON_LMASK) != 0)
	{
		Coordonate a(x, y);
		return a;
	}
}

void Game::PlayorStopMusic()//opreste muzica daca este pornita si o porneste daca este oprita
{
	if (Game::musicflag == true)
	{
		if (Game::onoffmusic == true )//verifica daca e pornita si o opreste
		{
			Mix_PauseMusic();
			Game::musicflag = false;
			Game::onoffmusic = false;
		}
		else
		{
			if (Game::onoffmusic == false)//verifica daca e oprita si o porneste
			{
				Mix_PlayMusic(backgroundSound, -1);
				Game::musicflag = false;
				Game::onoffmusic = true;
			}
		}
	}
}
