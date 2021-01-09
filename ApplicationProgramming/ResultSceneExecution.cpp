#include "ResultScene.h"
#include "Scene.h"
#include "ResultSceneExecution.h"

extern SceneID g_SceneID;
extern SceneStep g_SceneStep;

ResultScene g_ResultScene;

ResultSceneExecution::ResultSceneExecution()
{

}

ResultSceneExecution::~ResultSceneExecution()
{

}

void ResultSceneExecution::InitResultScene()
{
	g_ResultScene.Update();
}

void ResultSceneExecution::RunResultScene()
{
	g_SceneStep = SceneStep::Finish;
}

void ResultSceneExecution::FinishResultScene()
{
	g_SceneID = SceneID::SceneID_Title;
	g_SceneStep = SceneStep::Init;
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