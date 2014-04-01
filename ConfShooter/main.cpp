#include "xors3d.h"
#include <iostream>
#include "Application.h"
using namespace std;

int main()
{
	Application app("config.xml");
	app.CreateObjects();

	while(!xKeyHit(KEY_ESCAPE))
	{
		app.update(1);
	}
}

