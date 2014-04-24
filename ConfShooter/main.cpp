#include "xors3d.h"
#include <iostream>
#include "Application.h"
#include "GameMechanic.h"
using namespace std;

int main()
{
	Application app("config.xml");
	app.CreateObjects();

	while(app.update(1));
}

