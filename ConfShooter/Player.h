#pragma once
#include "xors3d.h"
#include "ObjectTypes.h"
#include <vector>
#include "bullet.h"

class Player
{
	Handle player, camera, gun;
	unsigned int mDamage;
public:
	Player(Handle pos);
	unsigned int GetDamage() const {return mDamage;}
	int getHandle() {return player;}
	void Update(float dt);
};