#include"DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/Player/Player.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	//Dxライブラリの初期化処理
	if (DxLib_Init() == -1)
	{
		return-1;
	}
	//オブジェクト生成
	GameObject* object[2] = {nullptr,nullptr};
	object[0] = new GameObject();//自動で動かす
	object[1] = new Player();//自分で動かす
	
	for (int i = 0; i < 2; i++)
	{
		object[i]->Initialize();
	}
	//裏画面の内容を表画面に描画する
	SetDrawScreen(DX_SCREEN_BACK);
	//メインループ
	while (ProcessMessage() != -1)
	{
		InputControl::Update();//更新処理

		for (int i = 0; i < 2; i++)
		{
			object[i]->Update();
		}
		//画面の削除
		ClearDrawScreen();

		for (int i = 0; i < 2; i++)
		{
			object[i]->Draw();
		}
		//画面の更新
		ScreenFlip();
		//エスケープキーが押されたとき終了する処理
		if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		object[i]->Finalize();
		delete object[i];
	}

	//Dxライブラリ使用の終了処理
	DxLib_End();


	return 0;
}