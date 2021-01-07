#include "DxLib.h"
#include "GameSceneh.h"
#include "../ResultScene.h"
#include "../TitleScene.h"
#include "Definition.h"

// プログラムは WinMain から始まります
// 警告C28251を回避するためにWinMainの引数に注釈を追記
// https://dxlib.xsrv.jp/cgi/patiobbs/patio.cgi?mode=view&no=4947
int WINAPI WinMain(_In_     HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_     LPSTR lpCmdLine,
	_In_     int nCmdShow)
{
	// ＤＸライブラリ初期化処理
	SetOutApplicationLogValidFlag(FALSE);	// ログ出力
	ChangeWindowMode(TRUE);					// ウィンドウモード
	SetGraphMode(640, 480, 32);				// 画面モード変更
	SetBackgroundColor(125, 125, 125);		// 背景色
	SetMainWindowText("My倉庫番");			// メニューバーのタイトル
	if (DxLib_Init() == -1) { return -1; }

	// 描画先を裏の画面に設定
	SetDrawScreen(DX_SCREEN_BACK);

	SceneID g_SceneID = SceneID::SceneID_Title;

	// ゲームループ
	while (true)
	{
		// Windowsのメッセージ処理に失敗したか、閉じられたら終了
		if (ProcessMessage() != 0) { break; }

		// DxLibのお約束：画面クリア
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

		// DxLibのお約束：画面更新
		ScreenFlip();
	}




	// ＤＸライブラリ使用の終了処理
	DxLib_End();

	// ソフトの終了
	return 0;
}


