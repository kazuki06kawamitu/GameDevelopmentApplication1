#include"DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/Player.h"
//プログラムの開始
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	//Dxライブラリの初期化処理
	if (DxLib_Init() == -1)
	{
		return-1;
	}
	//プレイヤーのオブジェクト生成
	Player* player = new Player();
	//描画先画面を裏にする
	SetDrawScreen(DX_SCREEN_BACK);
	//メインループ
	while (ProcessMessage() != -1)
	{
		//入力情報の更新処理
		InputControl::Update();
		//プレイヤー情報の更新処理
		player->Update();
		//壁に当たったら反対側の壁に移動する
		Vector2D tmp = player->GetLocation();
		if (tmp.x < 0.0f || 640.0f < tmp.x)
		{
			if (tmp.x < 0)
			{
				tmp.x = 640.0f;//左の壁から右の壁に移動
			}
			else
			{
				tmp.x = 0.0f; //右の壁から左の壁に移動
			}
			player->SetLocation(tmp);
		}
		if (tmp.y < 0.0f || 480.0f < tmp.y)
		{
			if (tmp.y < 0)
			{
				tmp.y = 480.0f;//上の壁から下の壁に移動
			}
			else
			{
				tmp.y = 0.0f;//下の壁から上の壁に移動
			}
		}
		player->SetLocation(tmp);//座標の更新
		ClearDrawScreen();//画面の削除
		player->Draw();//描画処理
		ScreenFlip();//画面の更新
		//ESCAPEキーが押されたら、終了させる
		if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}
	delete player;

	//Dxライブラリ使用の終了処理
	DxLib_End();

	return 0;
}