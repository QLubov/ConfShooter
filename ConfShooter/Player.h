#pragma once
#include "xors3d.h"
#include "ObjectTypes.h"

class Player
{
	Handle player, camera, gun;
public:
	Player(Handle pos);
	int getHandle() {return player;}
};