#pragma once
#include "xors3d.h"
#include <string>
#include <vector>

class LevelLoader
{
	Handle level;
public:
	LevelLoader(const std::string& file);
	~LevelLoader(void);
	Handle GetObjectByName(const std::string& name);
	std::vector<Handle> GetObjectArray(const std::string& name);

	void LoadDoors();
	void LoadKeys();
	void LoadBots();
	void LoadPlayer();
};
