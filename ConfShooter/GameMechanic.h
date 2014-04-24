#pragma once
#include "LevelLoader.h"
#include "Bot.h"
#include "Player.h"
#include "Bullet.h"
#include <vector>

class GameMechanic
{
	std::vector<Bot*> mBots;
	Player *player;
	std::vector<Bullet*> mBullets;	
	Handle aim;
	
	void UpdateShoot(float dt);
	GameMechanic(LevelLoader* );
	static GameMechanic* mInst;
	void RemoveBullet(std::vector<Bullet*>::iterator iterator);
	void RemoveBot(std::vector<Bot*>::iterator iterator);
public:
	void Update(float dt);
	void Shoot(Handle owner);

	static void Init(LevelLoader* loader) { mInst = new GameMechanic(loader); } 
	static GameMechanic* Instance() { if(mInst) return mInst; else return 0; }
	Handle GetAim() const {return aim;}

	~GameMechanic(void);
};
