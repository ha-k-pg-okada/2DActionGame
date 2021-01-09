#include "../ResultScene.h"
#include "DxLib.h"
#include "Scene.h"

extern SceneID g_Scene;
extern SceneStep g_SceneStep;

ResultScene::ResultScene()
{

}

ResultScene::~ResultScene()
{

}

void ResultScene::Update()
{
	char buf[256];

	//キー状態を全部取得	
	GetHitKeyStateAll(buf);

	//左キーが押されていれば
	if (buf[KEY_INPUT_RETURN] == 1)
	{
		//g_Scene = SceneID::SceneID_Title;

		g_SceneStep = SceneStep::Run;

	}

	DrawString(100, 100, "ResultScene", GetColor(255, 255, 255), 0);
}

void ResultScene::Draw()
{
	DrawString(100, 100, "GameScene", GetColor(255, 255, 255), 0);
}