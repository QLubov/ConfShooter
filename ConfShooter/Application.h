#pragma once
#include "xors3d.h"
#include "Player.h"
#include "ConfigFile.h"
#include "LevelLoader.h"
#include "Bot.h"

class Application 
{
	float GetDistance(Handle firstObj, Handle secondObj);
	ConfigFile config;
	LevelLoader *loader;
	void UpdateHud();
public:
	Application(const std::string& path);
	void CreateObjects();
	bool update(float delta);
	~Application();
};
