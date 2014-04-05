#include "Application.h"
#include <iostream>
#include <math.h> 
#include "ObjectTypes.h"
using namespace std;

Application::Application(const std::string& path)
	: config(path)
{
	xGraphics3D(config.width, config.height, 32, config.mode, true);
	loader = new LevelLoader(config.level);
}
void Application::CreateObjects()
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
}
void Application::update(float delta)
{
	for(size_t i = 0; i < mBots.size(); ++i)
		if(mBots[i]->GetReactionRadius() >= GetDistance(mBots[i]->GetHandle(), player->getHandle()))
			mBots[i]->React();
		else
			mBots[i]->update();
	xTurnEntity(player->getHandle(), xMouseYSpeed() * .3f, 0, 0);
	xTurnEntity(player->getHandle(), 0, -xMouseXSpeed() * .3f, 0, true);
	if (xKeyDown(KEY_W))
		xMoveEntity(player->getHandle(), 0,0, 3.f);
	if (xKeyDown(KEY_S))
		xMoveEntity(player->getHandle(), 0,0, -3.f);
	xUpdateWorld();
	xRenderWorld();
	xFlip();
}
Application::~Application()
{
	delete player;
	delete loader;
	for(size_t i = 0; i < mBots.size(); ++i)
		delete mBots[i];
}

float Application::GetDistance(Handle firstObj, Handle secondObj)
{
	float x, y, z;
	x = xEntityX(firstObj) - xEntityX(secondObj);
	y = xEntityY(firstObj) - xEntityY(secondObj);
	z = xEntityZ(firstObj) - xEntityZ(secondObj);
	return sqrt(x*x + y*y + z*z);
}