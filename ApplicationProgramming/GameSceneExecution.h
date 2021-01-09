#ifndef GAMESCENEEXECUTION_H
#define GAMESCENEEXECUTION_H

class GameSceneExecution
{
public:
	GameSceneExecution();
	~GameSceneExecution();

public:
	void InitGameScene();
	void RunGameScene();
	void FinishGameScene();

public:
	void GameSceneUpdate();
};





#endif // !GAMESCENEEXECUTION_H
