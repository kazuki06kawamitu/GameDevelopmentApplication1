#include"DxLib.h"
#include "Utility/InputControl.h"
#include "Oblects/player.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	//Dxライブラリの初期化処理
	if (DxLib_Init() == -1)
	{
		return-1;
	}

	Player* player = new Player();

	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() != -1)
	{
		InputControl::Update();
		player->Update();
		Vector2D tmp = player->GetLoction();
		if (tmp.x < 0.0f || 640.0f < tmp.x)
		{
			if (tmp.x < 0)
			{
				tmp.x = 640.0f;
			}
			else
			{
				tmp.x = 0.0f;
			}
			player->SetLoction(tmp);
		}
		if (tmp.y < 0.0f || 480.0f < tmp.y)
		{
			if (tmp.y < 0)
			{
				tmp.y = 480.0f;
			}
			else
			{
				tmp.y = 0.0f;
			}
		}
		player->SetLoction(tmp);
		ClearDrawScreen();
		player->Draw();
		ScreenFlip();

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