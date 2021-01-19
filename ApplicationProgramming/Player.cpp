#include "Player.h"
#include "DxLib.h"
#include "Camera.h"
#include "MapChip.h"

const float PlayerWidth = (72.0f * 1.5f);
const float PlayerHeight = (72.0f * 1.5f);

static MapChip g_MapChip;
extern Camera g_Camera;


Player::Player()
{
     Vector = Vec2(0.0f, 0.0f);
     Position = Vec2(100.0f, 100.0f);
     Speed = Vec2(4.0f, 4.0f);
}

Player::~Player()
{

}

Vec2& Player::GetPlayerPos()
{
    return Position;
}

Vec2 Player::GetPlayerCenterPos()
{
    return Vec2(Position.X + PlayerWidth / 2.0f, Position.Y + PlayerHeight / 2.0f);
}

void Player::Update()
{
    //Player画像サイズ
    Vec2 size = Vec2(40.0f, 40.0f);

    //移動処理
    if (CheckHitKey(KEY_INPUT_LEFT) != 0)
    {
        Vector.X = -Speed.X;
        //Position.X -= Speed.X;
        
    }

    if (CheckHitKey(KEY_INPUT_RIGHT) != 0)
    {
        Vector.X = Speed.X;
        //Position.X += Speed.X;
    }

    //if (CheckHitKey(KEY_INPUT_UP) != 0)
    //{
    //    Vector.X = Speed.X;
    //    //Position.X -= Speed.X;

    //}

    //if (CheckHitKey(KEY_INPUT_DOWN) != 0)
    //{
    //    Vector.X = -Speed.X;
    //    //Position.X += Speed.X;
    //}

    if (g_MapChip.OncollisionRectAndMapChip(
        // 現在値に移動量を加算した座標
        Vec2(Position.X + Vector.X, Position.Y + Vector.Y),
        // 矩形のサイズ
        size) == false)
    {
        Position.X += Vector.X;
        Position.Y += Vector.Y;
    }


    
}

void Player::Draw()
{
    Vec2 Screen_Pos = g_Camera.Update(Position);

    LoadGraphScreen(Screen_Pos.X, Screen_Pos.Y, "Res/Player.png", true);
}