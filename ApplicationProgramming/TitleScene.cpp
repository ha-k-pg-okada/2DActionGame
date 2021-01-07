#include "../TitleScene.h"
#include "Definition.h"
#include "DxLib.h"

extern SceneID g_Scene;

TitleScene::TitleScene()
{

}

TitleScene::~TitleScene()
{

}

void TitleScene::Update()
{
	char buf[256];
		
		//キー状態を全部取得	
		GetHitKeyStateAll(buf);

		//左キーが押されていれば
		if (buf[KEY_INPUT_RETURN] == 1) 
		{
			g_Scene = SceneID::SceneID_Game;
			//DrawString(100, 100, "TitleScene", GetColor(255, 255, 255), 0);
		}

		

}

void TitleScene::Draw()
{
	DrawString(100, 100, "TItleScene", GetColor(255, 255, 255), 0);
}