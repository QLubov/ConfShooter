#pragma once

class AI
{
protected:
	float mReactionRadius;

public:
	AI(float radius) : mReactionRadius(radius){}
	virtual void React() = 0;
	float GetReactionRadius() const {return mReactionRadius;}
	virtual ~AI(){}
};
