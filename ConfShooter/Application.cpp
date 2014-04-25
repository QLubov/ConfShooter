#include "Application.h"
#include <iostream>
#include <math.h> 
#include "ObjectTypes.h"
#include "GameMechanic.h"
using namespace std;

Application::Application(const std::string& path)
	: config(path)
{
	xGraphics3D(config.width, config.height, 32, config.mode, true);
	loader = new LevelLoader(config.level);
}
void Application::CreateObjects()
{
	loader->LoadPlayer();
	loader->LoadBots();
	loader->LoadDoors();
	loader->LoadKeys();
}
bool Application::update(float delta)
{
	if(xKeyHit(KEY_ESCAPE))
		return false;
	GAME.Update(delta);
	xUpdateWorld();
	xRenderWorld();
	UpdateHud();
	xFlip();
	xMoveMouse(config.width / 2, config.height / 2);
	return true;
}
Application::~Application()
{	
	delete loader;	
}


float Application::GetDistance(Handle firstObj, Handle secondObj)
{
	float x, y, z;
	x = xEntityX(firstObj) - xEntityX(secondObj);
	y = xEntityY(firstObj) - xEntityY(secondObj);
	z = xEntityZ(firstObj) - xEntityZ(secondObj);
	return sqrt(x*x + y*y + z*z);
}


void Application::UpdateHud()
{
	xDrawImage(GAME.GetAim(), (float)config.width / 2, (float)config.height / 2);
}