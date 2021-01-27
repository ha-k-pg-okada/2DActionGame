#include "Slider.h"
#include "DxLib.h"
#include "Scene.h"

extern SceneID g_SceneID;
extern SceneStep g_SceneStep;

Slider::Slider()
{
	Position = Vec2(0.0f, 0.0f);
	Size = Vec2(384, 64);
	MinValue = 0.0f;		// �ŏ��l
	MaxValue = 600.0f;      //�ő�l
    CurrentValue = 0.0f;	// ���ݒl
	Counter = 0;
}

Slider::~Slider()
{

}

Vec2 Slider::GetSliderPos()
{
	return Position;
}

void Slider::Init()
{
	MinValue = 0.0f;		// �ŏ��l
	MaxValue = 600.0f;      //�ő�l
	CurrentValue = 0.0f;	// ���ݒl
	Counter = 0;
}

void Slider::Update()
{

}

void Slider::Draw()
{
	Counter++;
	CurrentValue = (Counter - MinValue) / (MaxValue - MinValue);
	if (Counter >= 600)
	{
		g_SceneID = SceneID::SceneID_Game;
		g_SceneStep = SceneStep::Finish;
	}
	
	DrawBox(Position.X, Position.Y, (Size.X * (1.0 - CurrentValue)), Size.Y, GetColor(255, 0, 0), true);
	//LoadGraphScreen(Position.X, Position.Y, "Res/Slider01.png", true);
}