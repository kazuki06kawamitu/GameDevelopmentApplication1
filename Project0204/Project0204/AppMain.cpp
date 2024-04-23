#include"DxLib.h"
#include "Utility/ResourceManager.h"
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

	Gameobject* object = new Player();
	ResourceManager* resource_manager = GetResourceManager();

	SetDrawScreen(DX_SCREEN_BACK);

	try
	{
		object->Initialize();

		while (ProcessMessage() != -1)
		{
			inputControl::Update();
			object->Update();
			ClearDrawScreen();
			object->Draw();
			ScreenFlip();

			if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
			{
				break;
			}
		}
	}
	catch (std::string error_log)
	{
		OutputDebugString(error_log.c_str());
	}

	object->Finalize();
	delete object;

	resource_manager->DeleteImages();

	//Dxライブラリ使用の終了処理
	DxLib_End();


	return 0;
}