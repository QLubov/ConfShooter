#pragma once
#include "xors3d.h"
#include "AI.h"

class Bot : public AI
{
	float LowLimit, UpperLimit;
	Handle mHandle, mPlayer;
	bool up;
	unsigned int mHealth;
public:
	virtual ~Bot(){}
	void React();
	Bot(float radius, Handle handle, Handle player);// : AI(radius), mHandle(handle) {}
	int GetHandle() {return mHandle;}
	void update();
	void DealDamage(unsigned int dmg) { mHealth -= dmg; }
	unsigned int GetHealth() const {return mHealth;}
};