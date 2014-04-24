#include "Bot.h"
#include <iostream>
#include "objectTypes.h"

Bot::Bot(float radius, Handle handle, Handle player)
: AI(radius), mHandle(handle), mPlayer(player), mHealth(100)
{
	xEntityType(mHandle, tBot);
	xEntityRadius(mHandle, 5);
	up = true;
	UpperLimit = xEntityY(mHandle) + 4.0f;
	LowLimit = xEntityY(mHandle) - 4.0f;
}

void Bot::React()
{
	//std::cout<<mHandle<<std::endl;
	xMoveEntity(mHandle, 0, 0, 0.5);
	xPointEntity(mHandle, mPlayer);// collision between bot and player doesn't occur :(
}

void Bot::update()
{
	if(xEntityY(mHandle) < UpperLimit && up )
		xMoveEntity(mHandle, 0, 0.05f, 0);
	else
	{
		xMoveEntity(mHandle, 0, -0.08f, 0);
		up = false;
	}
	if (xEntityY(mHandle) <= LowLimit)
		up = true;
}
