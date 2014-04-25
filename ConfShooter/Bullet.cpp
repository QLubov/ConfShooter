#include "Bullet.h"

Bullet::Bullet(float x, float y, float z, float pitch, float yaw, float roll)
{
	Init(x, y, z, pitch, yaw, roll);
}

Bullet::Bullet(Handle object)
{
	Init(xEntityX(object, true),xEntityY(object, true),xEntityZ(object, true), xEntityPitch(object, true), xEntityYaw(object, true), xEntityRoll(object, true));
}

Bullet::~Bullet(void)
{
	xFreeEntity(mStartpos);
	xFreeEntity(mBullet);
}

void Bullet::Init(float x, float y, float z, float pitch, float yaw, float roll)
{
	mStartpos = xCreatePivot();
	xPositionEntity(mStartpos, x,y,z);
	xRotateEntity(mStartpos, pitch, yaw, roll);

	mBullet = xCreateSphere(8);
	
	int r = rand() % 255 + 1;
	int g = rand() % 255 + 1;
	int b = rand() % 255 + 1;

	xEntityColor(mBullet, r, g, b);

	xPositionEntity(mBullet, x,y,z);
	xRotateEntity(mBullet, pitch, yaw, roll);
}

void Bullet::Update(float dt)
{
	xMoveEntity(mBullet, 0, 0, 5.5f * dt);
}