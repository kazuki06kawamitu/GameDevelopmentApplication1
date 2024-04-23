#include"DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/GameObject.h"
#include "Objects/Player.h"
//プログラム開始
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	//Dxライブラリの初期化処理
	if (DxLib_Init() == -1)
	{
		return-1;
	}

	SetDrawScreen(DX_SCREEN_BACK);//描画先画面を裏にする

	GameObject* object1 = new GameObject();//オブジェクト生成
	Player* object2 = new Player();//オブジェクト生成

	//初期化処理
	object1->Initialize();
	object2->Initialize();
	//メインループ
	while (ProcessMessage() != -1 && InputControl::GetKeyUp(KEY_INPUT_ESCAPE) == false)
	{
		InputControl::Update();//更新処理
		//オブジェクトの更新
		object1->Update();
		object2->Update();

		//画面の初期化
		ClearDrawScreen();
		//描画処理
		object1->Draw();
		object2->Draw();
		//画面の更新
		ScreenFlip();
	}

	//オブジェクトの削除
	delete object1;
	delete object2;

	//Dxライブラリ使用の終了処理
	DxLib_End();


	return 0;
}