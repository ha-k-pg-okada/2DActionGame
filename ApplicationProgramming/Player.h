#ifndef PLAYER_H
#define PLAYER_H

#include "Common/Vec.h"

class Collision 
{
public:
	Vec2 Pos;
	Vec2 Size;
	void SetCollision(float posX, float posY, float sizeX, float sizeY)
	{
		Pos.X = posX;
		Pos.Y = posY;
		Size.X = sizeX;
		Size.Y = sizeY;
	}
};

class Player
{
public:
	Player();
	~Player();

public:
	void Init();
	void Update();
	void Draw();

	Vec2& GetPlayerPos();


	void StartJump();
	bool HitBox(Vec2 pos0, int width0, int height0, Vec2 pos1, int width1, int height1);
	//bool Collision01(Vec2 position, Vec2 size);
	


private:
	Vec2 Position;
	Vec2 Speed;

	Collision HeadCol;
	Collision LegCol;
	Collision RightCol;
	Collision LeftCol;

	float Velocity;
	float Gravity;
	
	bool CanJump;
};


#endif // !PLAYER_H
