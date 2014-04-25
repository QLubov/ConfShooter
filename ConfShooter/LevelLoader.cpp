#include "LevelLoader.h"
#include "GameMechanic.h"
using namespace std;

LevelLoader::LevelLoader(const std::string& file)
{
	level = xLoadAnimMesh(file.c_str());
}

LevelLoader::~LevelLoader(void)
{
}

Handle LevelLoader::GetObjectByName(const std::string& name)
{
	for(size_t i = 0; i < xCountChildren(level); i++)
	{
		Handle child = xGetChild(level, i);
		if(name == xEntityName(child))
			return child;
	}
	return 0;
}

std::vector<Handle> LevelLoader::GetObjectArray(const std::string& name)
{
	vector<Handle> objects;
	for(size_t i = 0; i < xCountChildren(level); i++)
	{
		Handle child = xGetChild(level, i);
		if(name == xEntityName(child))
			objects.push_back(child);
	}
	return objects;
}


void LevelLoader::LoadBots()
{
	vector<Handle> bots = GetObjectArray("bot");
	for(size_t i = 0; i < bots.size(); ++i)
	{
		GAME.CreateBot(bots[i]);
	}
}

void LevelLoader::LoadPlayer()
{
	GAME.CreatePlayer(GetObjectByName("player"));
}

void LevelLoader::LoadDoors()
{
	Handle door = GetObjectByName("door");
	xEntityType(door,tDoor);
	xCollisions(tPlayer, tDoor, 2, 1);
}

void LevelLoader::LoadKeys()
{
	//TODO: Implement logic
}