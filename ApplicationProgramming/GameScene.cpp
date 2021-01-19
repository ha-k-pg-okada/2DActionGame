#include "GameSceneh.h"
#include "Scene.h"
#include "DxLib.h"
#include "Player.h"
#include "MapChip.h"

extern SceneID g_Scene;
extern SceneStep g_SceneStep;


GameScene::GameScene()
{

}

GameScene::~GameScene()
{

}

void GameScene::Update()
{

	
	//char buf[256];z

	////キー状態を全部取得	
	//GetHitKeyStateAll(buf);

	////左キーが押されていれば
	//if (buf[KEY_INPUT_RETURN] == 1)
	//{
	//	//g_Scene = SceneID::SceneID_Title;

	//	g_SceneStep = SceneStep::Run;

	//}

	// マップチップと矩形の当たり判定
	

	
	//DrawString(100, 100, "GameScene", GetColor(255, 255, 255), 0);
}

void GameScene::Draw()
{
	DrawString(100, 100, "GameScene", GetColor(255, 255, 255), 0);
}