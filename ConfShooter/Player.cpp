#pragma once
#include "Player.h"
#include "GameMechanic.h"
using namespace std;
Player::Player(Handle pos)
	:mDamage(15)
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

void Player::Update(float dt)
{
	xTurnEntity(getHandle(), xMouseYSpeed() * .3f, 0, 0);
	xTurnEntity(getHandle(), 0, -xMouseXSpeed() * .3f, 0, true);

	if (xKeyDown(KEY_W))
		xMoveEntity(getHandle(), 0,0, 3.f);
	if (xKeyDown(KEY_S))
		xMoveEntity(getHandle(), 0,0, -3.f);

	if(xMouseDown(MOUSE_LEFT))
	{
		GAME.Shoot(camera);
	}
}