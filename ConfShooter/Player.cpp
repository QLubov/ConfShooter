#pragma once
#include "Player.h"

Player::Player(Handle pos)
{
	player = xCreatePivot();
	camera = xCreateCamera(player);
	gun = xCreateCube(player);
	xScaleEntity(gun, 1, 1, 4);
	xPositionEntity(gun, 5, -5, 15);
	xEntityColor(gun, 102, 109, 179);

	xPositionEntity(player, xEntityX(pos), xEntityY(pos), xEntityZ(pos));
	xEntityType(player, tPlayer);
	xEntityRadius(player, 15);
	}