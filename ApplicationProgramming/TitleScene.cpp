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
		
		//�L�[��Ԃ�S���擾	
		GetHitKeyStateAll(buf);

		//���L�[��������Ă����
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