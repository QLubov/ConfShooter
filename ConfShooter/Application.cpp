#include "Application.h"

Application::Application(const std::string& path)
	: config(path)
{
	xGraphics3D(config.width, config.height, 32, config.mode, true);
	loader = new LevelLoader(config.level);
}
void Application::CreateObjects()
{
	Handle pDummy = loader->GetObjectByName("player");
	player = new Player(xEntityX(pDummy), xEntityY(pDummy), xEntityZ(pDummy));	
	xTurnEntity(xCreateLight(), 45, 45, 45);

	//test
	Handle door = loader ->GetObjectByName("door");
	xEntityType(door, 1);
	xEntityType(player->getHandle(), 2);
	xEntityRadius(player->getHandle(), 15);
	xCollisions(2, 1, 2, 1);

}
void Application::update(float delta)
{		
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
}