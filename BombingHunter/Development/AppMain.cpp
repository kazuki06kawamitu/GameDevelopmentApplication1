#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Scene/Scene.h"

//プログラムはここから始まります
int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{
	//Windowモードで起動する
	ChangeWindowMode(TRUE);

	//Windowサイズの設定(640×480のサイズ)
	SetGraphMode(640, 480, 32);

	//Dxライブラリの初期化
	if (DxLib_Init() == -1)
	{
		//異常を通知
		return -1;
	}
	//裏画面から描画を始める
	SetDrawScreen(DX_SCREEN_BACK);
	

	//ローカル変数定義
	Scene* scene = new Scene();//シーンを生成する
	int result = 0;            //終了状態情報

	try
	{
		//シーンの初期化
		scene->Initialize();

		//メインループ(更新と描画を行う)
		//ESCキーが押されたら、ループを終了する
		while (ProcessMessage() != -1 &&
	InputControl::GetKeyUp(KEY_INPUT_ESCAPE) == false)
		{
			//入力機能の更新処理
			InputControl::Update();

			//シーンの更新処理
			scene->Update();

			//画面の初期化
			ClearDrawScreen();
			
			//シーンの描画処理
			scene->Draw();

			//裏画面の内容を表画面に反映する
			ScreenFlip();
		}
	}
	catch(const char* error_log)
	{
		//例外スローされた情報をログファイルに出力する
		OutputDebugString(error_log);
		//異常終了を通知する
		result = -1;
	}

	//シーン情報が存在していれば、削除する
	if (scene != nullptr)
	{
		scene->Finalize();
		delete scene;
		scene = nullptr;
	}

	DxLib_End();

	//終了状態の値を通知する
	return result;
}