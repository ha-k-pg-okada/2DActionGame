#include "Player.h"
#include "DxLib.h"
#include "Camera.h"
#include "MapChip.h"
#include "Scene.h"

extern SceneID g_SceneID;
extern SceneStep g_SceneStep;

static MapChip g_MapChip;
extern Camera g_Camera;


Player::Player()
{
     Position = Vec2(100.0f, 100.0f);
     Speed = Vec2(4.0f, 4.0f);
     Velocity = 10.0f;
     Gravity = 1.0f;
     CanJump = false;
    
}

Player::~Player()
{
    
}

void Player::Init()
{
    CanJump = false;
    Position = Vec2(100.0f, 100.0f);
}

Vec2& Player::GetPlayerPos()
{
    return Position;
}

void Player::StartJump()
{
    if (CanJump == true)
    {
        Velocity = 20.0f;
        CanJump = false;
    }
}

bool Player::HitBox(Vec2 pos0, int width0, int height0, Vec2 pos1, int width1, int height1)
{

    //オブジェクトの距離
    int x = pos1.X - pos0.X;
    int y = pos1.Y - pos0.Y;

    //abs関数は絶対値を返す
    if (abs(x) < width0 / 2 + width1 / 2 && abs(y) < height0 / 2 + height1 / 2) {
        return true;
    }

    return false;
}



void Player::Update()
{

    //Player画像サイズ
    Vec2 size = Vec2(40.0f, 40.0f);
    Vec2 Vector = Vec2(0.0f, 0.0f);
    Vec2 hitBlockPos = Vec2(0.0f, 0.0f);
    int no = 0;
    

    HeadCol.SetCollision(Position.X, Position.Y - size.Y / 2, 10, 1); //大きすぎたり小さすぎたりしたらお互いの判定が干渉してしまう
    LegCol.SetCollision(Position.X, Position.Y + size.Y / 2, 10, 1);
    RightCol.SetCollision(Position.X + size.X / 2, Position.Y, 1, 10);
    LeftCol.SetCollision(Position.X - (50 / 2), Position.Y, 1, 10);

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

    if (CheckHitKey(KEY_INPUT_SPACE) != 0)
    {
        StartJump();
        //Position.Y += Speed.Y;

    }
    
    if (CanJump == false)
            {

                Velocity -= Gravity;
                Vector.Y = -Velocity;
            }

    


     if (g_MapChip.OncollisionRectAndMapChip(
         Vec2(Position.X + Vector.X, Position.Y + Vector.Y),size, 0) == true)
     {
    
         

         
            Position.X += Vector.X;
            Position.Y += Vector.Y;

         


     }


     int x = Position.X / 64;
     int y = Position.Y / 64;

     //if (MapChipList[y][x] == TwoBlock)
     //{
         //Onblockの座標算出
     Vec2 g_Position = Vec2(x * 64, y * 64);

     if (g_MapChip.OncollisionRectAndMapChip(Vec2(Position.X + Vector.X, Position.Y + Vector.Y), size, 1) == true)
     {
         //LegCol.Pos.Y = (g_Position.Y - 64 / 2) - (50 / 2);
         CanJump = true;

     }


     if (g_MapChip.OncollisionRectAndMapChip(Vec2(Position.X + Vector.X, Position.Y + Vector.Y), size, 2) == true)
     {
         //{
         if (Position.X >= 64)
         {
             Position.X = (g_Position.X + (64 / 2) - (40 / 2)) - 8;
         }
         
         if (Position.X >= 1000)
         {
             Position.X = (g_Position.X + (64 / 2) - (40 / 2)) + 8;
         }
         
     }


     if (g_MapChip.OncollisionRectAndMapChip(Vec2(Position.X + Vector.X, Position.Y + Vector.Y), size, 3) == true)
     {
         //g_MapChip.isActive = false;
         g_SceneID = SceneID::SceneID_Result;
         g_SceneStep = SceneStep::Finish;

     }

   
}

void Player::Draw()
{
    Vec2 Screen_Pos = g_Camera.Update(Position);

    LoadGraphScreen(Screen_Pos.X, Screen_Pos.Y, "Res/Player.png", true);
}