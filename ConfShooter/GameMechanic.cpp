#include "GameMechanic.h"
using namespace std;

GameMechanic* GameMechanic::mInst = 0;

GameMechanic::GameMechanic(LevelLoader* loader)
{	
	xTurnEntity(xCreateLight(), 45, 45, 45);

	player = new Player(loader->GetObjectByName("player"));	
	vector<Handle> bots = loader->GetObjectArray("bot");
	for(size_t i = 0; i < bots.size(); ++i)
	{
		Bot* bot = new Bot(200, bots[i], player->getHandle());
		mBots.push_back(bot);
	}

	Handle door = loader ->GetObjectByName("door");
	xEntityType(door,tDoor);

	xCollisions(tPlayer, tDoor, 2, 1);
	xCollisions(tPlayer, tBot, 2, 1);

	aim = xLoadImage("textures/aim.png");
}

GameMechanic::~GameMechanic(void)
{
	delete player;
	for(size_t i = 0; i < mBots.size(); ++i)
		delete mBots[i];
}

void GameMechanic::Update(float dt)
{
	for(size_t i = 0; i < mBots.size(); ++i)
		if(mBots[i]->GetReactionRadius() >= xEntityDistance(mBots[i]->GetHandle(), player->getHandle()))
			mBots[i]->React();
		else
			mBots[i]->update();
	player->Update(dt);
	UpdateShoot(dt);
	
}

void GameMechanic::Shoot(Handle owner)
{
	mBullets.push_back(new Bullet(owner));
}

void GameMechanic::UpdateShoot(float dt)
{
	vector<Bullet*>::iterator it;
	for(it = mBullets.begin(); it != mBullets.end(); ++it)
	{
		Bullet* bullet = *it;
		bullet->Update(dt);
		
		vector<Bot*>::iterator botIt;
		for (botIt = mBots.begin(); botIt != mBots.end(); ++botIt )
		{
			Bot* bot = *botIt;
			if(xEntityDistance(bot->GetHandle(), bullet->GetHandle() < 5.f))
			{
				bot->DealDamage(player->GetDamage());
				if(bot->GetHealth() <= 0)
					RemoveBot(botIt);
				RemoveBullet(it);
				return;
			}
		}

		//todo: investigate how to remove group of objects from collection
		float distance = xEntityDistance(bullet->GetHandle(), bullet->GetStartPositionPivot());
		if( distance > 1000.f)
		{
			RemoveBullet(it);
			return;
		}
	}
}

void GameMechanic::RemoveBullet(vector<Bullet*>::iterator iterator)
{
	delete *iterator;
	mBullets.erase(iterator);
	return;
}

void GameMechanic::RemoveBot(vector<Bot*>::iterator iterator)
{
	delete *iterator;
	mBots.erase(iterator);
	return;
}