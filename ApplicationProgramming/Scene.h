#ifndef SCENE_H
#define SCENE_H

enum SceneID
{
	SceneID_Title,			// �^�C�g��
	SceneID_Game,			// �Q�[��
	SceneID_Result,			// ���U���g
};

enum SceneStep
{
	Init,
	Run,
	Finish
};

void SceneUpdate01();

#endif // !SCENE_H
