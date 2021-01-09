#include "GameSceneh.h"
#include "Scene.h"
#include "GameSceneExecution.h"

extern SceneID g_SceneID;
extern SceneStep g_SceneStep;

GameScene g_GameScene;

GameSceneExecution::GameSceneExecution()
{

}

GameSceneExecution::~GameSceneExecution()
{

}

void GameSceneExecution::InitGameScene()
{
	g_GameScene.Update();
}

void GameSceneExecution::RunGameScene()
{
	g_SceneStep = SceneStep::Finish;
}

void GameSceneExecution::FinishGameScene()
{
	g_SceneID = SceneID::SceneID_Result;
	g_SceneStep = SceneStep::Init;
}

void GameSceneExecution::GameSceneUpdate()
{
	switch (g_SceneStep)
	{
	case SceneStep::Init: InitGameScene(); break;
	case SceneStep::Run: RunGameScene();  break;
	case SceneStep::Finish: FinishGameScene(); break;
	}
}