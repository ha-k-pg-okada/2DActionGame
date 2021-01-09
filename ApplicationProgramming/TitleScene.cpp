#include "../TitleScene.h"
#include "Scene.h"
#include "DxLib.h"

extern SceneID g_Scene;
extern SceneStep g_SceneStep;

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
			//g_Scene = SceneID::SceneID_Title;
			
			g_SceneStep = SceneStep::Run;
			
		}

		DrawString(100, 100, "TitleScene", GetColor(255, 255, 255), 0);

}

void TitleScene::Draw()
{
	DrawString(100, 100, "TItleScene", GetColor(255, 255, 255), 0);
}

