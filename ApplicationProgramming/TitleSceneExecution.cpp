#include "../TitleSceneExecution.h"
#include "Scene.h"
#include "TitleScene.h"
#include "DxLib.h"

extern SceneID g_SceneID;
extern SceneStep g_SceneStep;

static TitleScene g_TitleScene;

TiteleSceneExecution::TiteleSceneExecution()
{

}

TiteleSceneExecution::~TiteleSceneExecution()
{

}

void TiteleSceneExecution::InitTitleScene()
{
	DrawString(100, 100, "ActionGame", GetColor(255, 255, 255), 0);
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		g_SceneStep = SceneStep::Run;
	}
	
}

void TiteleSceneExecution::RunTitleScene()
{
	//g_TitleScene.Draw();
	g_SceneStep = SceneStep::Finish;
}

void TiteleSceneExecution::FinishTitleScene()
{
	g_SceneID = SceneID::SceneID_Game;
	g_SceneStep = SceneStep::Init;
}

void TiteleSceneExecution::TitleSceneUpdate()
{
	switch (g_SceneStep)
	{
	case SceneStep::Init: InitTitleScene(); break;
	case SceneStep:: Run: RunTitleScene();  break;
	case SceneStep::Finish: FinishTitleScene(); break;
	}
}