#include "Player.h"
#include "DxLib.h"

Player::Player()
{
     Position = Vec2(200.0f, 200.0f);
     Speed = Vec2(2.0f, 2.0f);
}

Player::~Player()
{

}

void Player::Update()
{
    //à⁄ìÆèàóù
    if (CheckHitKey(KEY_INPUT_LEFT) != 0)
    {
        Position.X -= Speed.X;
    }

    if (CheckHitKey(KEY_INPUT_RIGHT) != 0)
    {
        Position.X += Speed.X;
    }
}

void Player::Draw()
{
    LoadGraphScreen(Position.X, Position.Y, "Res/Player.png", true);
}