//#pragma once
//#include"Component.h"
//#include"SDL.h"
//#include"TextureManager.h"
//#include<map>
//
//struct Animation
//{
//	int index;
//	int frames;
//	int speed;
//
//	Animation() {}
//	Animation(int i, int f, int s)
//	{
//		index = i;
//		frames = f;
//		speed = s;
//	}
//};
//
//class SpriteComponent :public Component
//{
//private:
//	SDL_Texture* texture;
//	SDL_Rect srcRect, destRect;
//
//	bool animated = false;
//	int frames = 0;
//	int speed = 100;
//
//public:
//
//	int animIndex = 0;
//
//	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;
//
//	SpriteComponent(const char* path, bool isAnimated)
//	{
//		animated = isAnimated;
//
//		Animation walk = Animation(1, 2, 100);
//		Animation idle = Animation(0, 2, 100);
//		animations.emplace("Idle", idle);
//		animations.emplace("Walk", walk);
//
//		Play("Idle");
//		setTex(path);
//	}
//	~SpriteComponent()
//	{
//		SDL_DestroyTexture(texture);
//	}
//
//	void setTex(const char* path)
//	{
//		texture = TextureManager::LoadTexture(path);
//	}
//	void init() override
//	{
//		transform = &entity->getComponent<TransformComponent>();
//
//		srcRect.x = srcRect.y = 0;
//		srcRect.w = transform->width;
//		srcRect.h = transform->height;
//	}
//	void update() override
//	{
//		if (animated)
//		{
//			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
//		}
//
//		srcRect.y = animIndex * transform->height;
//
//		destRect.x = static_cast<int>(transform->position.x);
//		destRect.y = static_cast<int>(transform->position.y);
//		destRect.w = transform->width * transform->scale;
//		destRect.h = transform->height * transform->scale;
//	}
//	void draw() override
//	{
//		TextureManager::Draw(texture, srcRect, destRect, spriteFlip);
//	}
//
//	void Play(const char* animName)
//	{
//		frames = animations[animName].frames;
//		animIndex = animations[animName].index;
//		speed = animations[animName].speed;
//	}
//};