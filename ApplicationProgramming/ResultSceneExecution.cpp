#include "ResultScene.h"
#include "Scene.h"
#include "ResultSceneExecution.h"
#include "DxLib.h"

extern SceneID g_SceneID;
extern SceneStep g_SceneStep;

static ResultScene g_ResultScene;

ResultSceneExecution::ResultSceneExecution()
{

}

ResultSceneExecution::~ResultSceneExecution()
{

}

void ResultSceneExecution::InitResultScene()
{
	//g_ResultScene.Update();
	g_SceneStep = SceneStep::Run;
}

void ResultSceneExecution::RunResultScene()
{
	DrawString(100, 100, "Game Over", GetColor(255, 255, 255), 0);
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		g_SceneID = SceneID::SceneID_Title;
		g_SceneStep = SceneStep::Init;
	}
}

void ResultSceneExecution::FinishResultScene()
{
	DrawString(100, 100, "Game Clear", GetColor(255, 255, 255), 0);
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		g_SceneID = SceneID::SceneID_Title;
		g_SceneStep = SceneStep::Init;
	}


	
}

void ResultSceneExecution::ResultSceneUpdate()
{
	switch (g_SceneStep)
	{
	case SceneStep::Init: InitResultScene(); break;
	case SceneStep::Run: RunResultScene();  break;
	case SceneStep::Finish: FinishResultScene(); break;
	}
}