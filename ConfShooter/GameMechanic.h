#pragma once
#include "LevelLoader.h"
#include "Bot.h"
#include "Player.h"
#include "Bullet.h"
#include <vector>

class GameMechanic
{
	std::vector<Bot*> mBots;
	Player *mPlayer;
	std::vector<Bullet*> mBullets;	
	Handle aim;
	
	void UpdateShoot(float dt);
	GameMechanic();
	void RemoveBullet(std::vector<Bullet*>::iterator iterator);
	void RemoveBot(std::vector<Bot*>::iterator iterator);
public:
	void Update(float dt);
	void Shoot(Handle owner);
	
	void CreateBot();
	void CreateBot(Handle);
	bool CreatePlayer(Handle);
	void ResetPlayer(Handle);
	static GameMechanic& Instance() { static GameMechanic inst; return inst;}
	Handle GetAim() const {return aim;}

	~GameMechanic(void);
};

#define GAME GameMechanic::Instance()
