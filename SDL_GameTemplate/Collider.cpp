#include"Collider.h"
#include"TextureManager.h"
#include"Map.h"

bool ColliderComponent::epamantflag=0;

ColliderComponent::ColliderComponent(string t, int xpos, int ypos, int size)//
{
	tag = t;
	collider.x = xpos;
	collider.y = ypos;
	collider.w = collider.h = size;
}
void ColliderComponent::init()
{
	tex = TextureManager::LoadTexture("assets/grass.png");
	srcR = { 0,0,32,32 };
	destR = { collider.x,collider.y,collider.w,collider.h };

}

void ColliderComponent::update()
{
	destR.x = collider.x;
	destR.y = collider.y;
}
void ColliderComponent::draw() 
{
	TextureManager::Draw(tex, srcR, destR);
}
bool ColliderComponent::AABB(const SDL_Rect& A, const SDL_Rect& B)//verificam toate cazurile in care 2 dreptunghiuri se pot intersecta
{
	if (
		A.x + A.w >= B.x &&
		B.x + B.w >= A.x &&
		A.y + A.h >= B.y &&
		B.y + B.h >= A.y
		)
	{
		return true;
	}

	return false;
}
bool ColliderComponent::Ecollision(SDL_Rect player)
{
	int map[20][25];
	switch (Map::mapindex)//verificam pe ce mapa suntem pentru a o verifica pe cea corecta
	{
	case 1:
		Map::LoadMap(map, Map::map1);
		break;
	case 2:
		Map::LoadMap(map, Map::map2);
		break;
	case 3:
		Map::LoadMap(map, Map::map3);
		break;
	default:
		break;
	}
	bool trece = false;
	for (int i = 0; i < 20; i++)// verificam interactiunile jucatorului cu mapa
	{
		for (int j = 0; j < 25; j++)
		{
			if (map[i][j] == 1)
			{
				if (AABB({ j * 40,i * 40,40,40 }, player))
				{
					trece = true;
					epamantflag = 1;
				}
			}
			if (map[i][j] == 2)
			{
				if (AABB({ j * 40,i * 40,40,40 }, player))
				{
					trece = true;
					epamantflag = 0;
				}
			}
			if (map[i][j] == 3)
			{
				if (AABB({ j * 40,i * 40,40,40 }, player))
				{
					trece = true;
					epamantflag = 0;
				}
			}
			if (map[i][j] == 8)
			{
				if (AABB({ j * 40,i * 40,40,40 }, player))
				{
					trece = true;
					epamantflag = 0;
				}
			}
			if (map[i][j] == 9)
			{
				if (AABB({ j * 40,i * 40,40,40 }, player))
				{
					trece = true;
					epamantflag = 0;
				}
			}
			if (map[i][j] == 10)
			{
				if (AABB({ j * 40,i * 40,40,40 }, player))
				{
					trece = true;
					epamantflag = 0;
				}
			}
			if (map[i][j] == 11)
			{
				if (AABB({ j * 40,i * 40,40,40 }, player))
				{
					trece = true;
					epamantflag = 0;
				}
			}
			if (map[i][j] == 17)
			{
				if (AABB({ j * 40,i * 40,40,40 }, player))
				{
					trece = true;
					epamantflag = 0;
					Game::levelpassed = 1;//daca player ajunge pe acest patratel va trece nivelul
				}
			}
			if (map[i][j] == 12)
			{
				if (AABB({ j * 40,i * 40,40,40 }, player))
				{
					trece = true;
					epamantflag = 0;
				}
			}
			if (map[i][j] == 13)
			{
				if (AABB({ j * 40,i * 40,40,40 }, player))
				{
					trece = true;
					epamantflag = 0;
				}
			}
		}
	}
	return trece;
}
