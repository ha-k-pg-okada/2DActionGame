#ifndef PLAYER_H
#define PLAYER_H

#include "Common/Vec.h"

class Player
{
public:
	Player();
	~Player();

public:
	void Update();
	void Draw();

	Vec2& GetPlayerPos();
	Vec2 GetPlayerCenterPos();

	Vec2 Position;

private:
	
    Vec2 Vector;
	Vec2 Speed;
};


#endif // !PLAYER_H
