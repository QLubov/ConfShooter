#pragma once
#include <xors3d.h>

class Bullet
{
	Handle mBullet;
	Handle mStartpos;
	void Init(float x, float y, float z, float pitch, float yaw, float roll);
public:
	Bullet(Handle object);
	Bullet(float x, float y, float z, float pitch, float yaw, float roll);
	~Bullet(void);

	Handle GetStartPositionPivot() const {return mStartpos;}
	Handle GetHandle() const {return mBullet;}
	void Update(float dt);
};
