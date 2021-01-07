#include "DxLib.h"
#include "GameSceneh.h"
#include "../ResultScene.h"
#include "../TitleScene.h"
#include "Definition.h"

// �v���O������ WinMain ����n�܂�܂�
// �x��C28251��������邽�߂�WinMain�̈����ɒ��߂�ǋL
// https://dxlib.xsrv.jp/cgi/patiobbs/patio.cgi?mode=view&no=4947
int WINAPI WinMain(_In_     HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_     LPSTR lpCmdLine,
	_In_     int nCmdShow)
{
	// �c�w���C�u��������������
	SetOutApplicationLogValidFlag(FALSE);	// ���O�o��
	ChangeWindowMode(TRUE);					// �E�B���h�E���[�h
	SetGraphMode(640, 480, 32);				// ��ʃ��[�h�ύX
	SetBackgroundColor(125, 125, 125);		// �w�i�F
	SetMainWindowText("My�q�ɔ�");			// ���j���[�o�[�̃^�C�g��
	if (DxLib_Init() == -1) { return -1; }

	// �`���𗠂̉�ʂɐݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	SceneID g_SceneID = SceneID::SceneID_Title;

	// �Q�[�����[�v
	while (true)
	{
		// Windows�̃��b�Z�[�W�����Ɏ��s�������A����ꂽ��I��
		if (ProcessMessage() != 0) { break; }

		// DxLib�̂��񑩁F��ʃN���A
		ClearDrawScreen();
		clsDx();

		TitleScene g_TitleScene;
		GameScene g_GameScene;

		switch (g_SceneID)
		{
		case SceneID_Title:		g_TitleScene.Update();	break;
		case SceneID_Game:	    g_GameScene.Update();	break;
		case SceneID_Result:	new ResultScene();	break;
		default:				break;
		}
		
		

		//g_TitleScene.Draw();
		//g_GameScene.Draw();

		// DxLib�̂��񑩁F��ʍX�V
		ScreenFlip();
	}




	// �c�w���C�u�����g�p�̏I������
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}


