#pragma once
#include <string>
#include "pugixml.hpp"

class ConfigFile
{
	void ReadGraphics(pugi::xml_document& doc);
	void ReadOptions(pugi::xml_document& doc);
public:
	int width, height;
	bool mode;
	std::string level;
	ConfigFile(const std::string& file);
	~ConfigFile(void);
};
