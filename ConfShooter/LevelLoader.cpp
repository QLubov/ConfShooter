#include "LevelLoader.h"
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