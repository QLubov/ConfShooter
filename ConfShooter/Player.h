#pragma once
#include "xors3d.h"

class Player
{
	Handle player, camera, gun;
public:
	Player(float x, float y, float z)
	{
		player = xCreatePivot();
		camera = xCreateCamera(player);
		gun = xCreateCube(player);
		xScaleEntity(gun, 1, 1, 4);
		xPositionEntity(gun, 5, -5, 15);
		xEntityColor(gun, 102, 109, 179);

		xPositionEntity(player, x, y, z);
	}
	int getHandle() {return player;}
};