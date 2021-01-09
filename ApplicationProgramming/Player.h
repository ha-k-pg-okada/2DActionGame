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

private:

	Vec2 Position;
	Vec2 Speed;
};


#endif // !PLAYER_H
