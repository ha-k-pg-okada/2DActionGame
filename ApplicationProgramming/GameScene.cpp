#include "GameSceneh.h"
#include "Definition.h"
#include "DxLib.h"

GameScene::GameScene()
{

}

GameScene::~GameScene()
{

}

void GameScene::Update()
{
	//char buf[256];

	//�L�[��Ԃ�S���擾	
	//GetHitKeyStateAll(buf);

	//���L�[��������Ă����
	/*if (buf[KEY_INPUT_RETURN] == 1)
	{
		SceneID::SceneID_Result;
	}*/

	DrawString(100, 100, "GameScene", GetColor(255, 255, 255), 0);
}

void GameScene::Draw()
{
	DrawString(100, 100, "GameScene", GetColor(255, 255, 255), 0);
}