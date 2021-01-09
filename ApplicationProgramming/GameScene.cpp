#include "GameSceneh.h"
#include "Scene.h"
#include "DxLib.h"
#include "Player.h"

extern SceneID g_Scene;
extern SceneStep g_SceneStep;

static Player g_Player;

GameScene::GameScene()
{

}

GameScene::~GameScene()
{

}

void GameScene::Update()
{
	//char buf[256];

	////キー状態を全部取得	
	//GetHitKeyStateAll(buf);

	////左キーが押されていれば
	//if (buf[KEY_INPUT_RETURN] == 1)
	//{
	//	//g_Scene = SceneID::SceneID_Title;

	//	g_SceneStep = SceneStep::Run;

	//}

	g_Player.Update();
	g_Player.Draw();
	
	DrawString(100, 100, "GameScene", GetColor(255, 255, 255), 0);
}

void GameScene::Draw()
{
	DrawString(100, 100, "GameScene", GetColor(255, 255, 255), 0);
}