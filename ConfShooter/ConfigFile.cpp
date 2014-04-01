#include "ConfigFile.h"
#include "pugixml.hpp"
using namespace pugi;

ConfigFile::ConfigFile(const std::string& file)
{
	xml_document doc;
	doc.load_file(file.c_str());
	ReadGraphics(doc);
	ReadOptions(doc);
}

ConfigFile::~ConfigFile(void)
{
}

void ConfigFile::ReadGraphics(pugi::xml_document &doc)
{
	xml_node graphics = doc.child("graphics");
	width = graphics.child("width").text().as_int();
	height = graphics.child("height").text().as_int();
	mode = graphics.child("screenMode").text().as_bool();
}

void ConfigFile::ReadOptions(pugi::xml_document &doc)
{
	xml_node options = doc.child("options");
	level = options.child("level").text().as_string();
}