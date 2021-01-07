#include "../ResultScene.h"
#include "DxLib.h"

ResultScene::ResultScene()
{

}

ResultScene::~ResultScene()
{

}

void ResultScene::Draw()
{
	DrawString(100, 100, "GameScene", GetColor(255, 255, 255), 0);
}