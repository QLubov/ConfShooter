#pragma once
#include "xors3d.h"
#include "Player.h"
#include "ConfigFile.h"
#include "LevelLoader.h"
#include "Bot.h"

class Application 
{
	float GetDistance(Handle firstObj, Handle secondObj);
	std::vector<Bot*> mBots;
	Player *player;
	ConfigFile config;
	LevelLoader *loader;
public:
	Application(const std::string& path);
	void CreateObjects();
	void update(float delta);
	~Application();
};
