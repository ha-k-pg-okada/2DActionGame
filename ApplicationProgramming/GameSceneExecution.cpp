#include "GameSceneh.h"
#include "Scene.h"
#include "GameSceneExecution.h"
#include "MapChip.h"
#include "Player.h"
#include "Camera.h"
#include "BackGround.h"
#include "Slider.h"

extern SceneID g_SceneID;
extern SceneStep g_SceneStep;

static GameScene g_GameScene;
static Player g_Player;
static Slider g_Slider;
 Camera g_Camera;
 
static BackGround g_BackGround;
//static MapChip g_MapChip;


GameSceneExecution::GameSceneExecution()
{

}

GameSceneExecution::~GameSceneExecution()
{

}

void GameSceneExecution::InitGameScene()
{
	g_Player.Init();
	g_Slider.Init();
	g_SceneStep = SceneStep::Run;
}

void GameSceneExecution::RunGameScene()
{

	MapChip g_MapChip;
	g_Camera.CameraUpdate(g_Player.GetPlayerPos());
	g_BackGround.Draw();
	g_MapChip.Update();
	g_Player.Update();
	g_MapChip.Draw();
	g_Player.Draw();
	g_Slider.Draw();
	
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