#include "GameSceneh.h"
#include "DxLib.h"

GameScene::GameScene()
{

}

GameScene::~GameScene()
{

}

void GameScene::Draw()
{
	DrawBox(32, 32, 32 + 32, 32 + 32,
		GetColor(255, 255, 255), true);
}