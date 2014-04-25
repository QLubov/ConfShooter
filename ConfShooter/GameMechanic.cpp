#include "GameMechanic.h"
using namespace std;


GameMechanic::GameMechanic()
:mPlayer(0)
{	
	xTurnEntity(xCreateLight(), 45, 45, 45);

	aim = xLoadImage("textures/aim.png");
}

GameMechanic::~GameMechanic(void)
{
	delete mPlayer;
	for(size_t i = 0; i < mBots.size(); ++i)
		delete mBots[i];
}
void GameMechanic::CreateBot()
{
}
void GameMechanic::CreateBot(Handle handle)
{
	const float BOT_REACTION_RADIUS = 200.f;

	Bot* bot = new Bot(BOT_REACTION_RADIUS, handle, mPlayer->getHandle());
	mBots.push_back(bot);
}

void GameMechanic::Update(float dt)
{
	for(size_t i = 0; i < mBots.size(); ++i)
		if(mBots[i]->GetReactionRadius() >= xEntityDistance(mBots[i]->GetHandle(), mPlayer->getHandle()))
			mBots[i]->React();
		else
			mBots[i]->update();
	if(mPlayer)
		mPlayer->Update(dt);
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
			if(xEntityDistance(bot->GetHandle(), bullet->GetHandle()) < 50.f)
			{
				bot->DealDamage(mPlayer->GetDamage());
				if(bot->GetHealth() == 0)
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

bool GameMechanic::CreatePlayer(Handle handle)
{
	if(mPlayer == 0)
	{
		mPlayer = new Player(handle);
		return true;
	}
	return false;
}

void GameMechanic::ResetPlayer(Handle handle)
{
	if (mPlayer)
	{
		xPositionEntity(mPlayer->getHandle(), xEntityX(handle,true), xEntityY(handle,true), xEntityZ(handle,true));
	}
}