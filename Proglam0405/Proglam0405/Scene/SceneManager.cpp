#include "SceneManager.h"

#include "DxLib.h"
#include "../Utility/InputControl.h"
#include "../Utility/SceneFactroy.h"

SceneManager::SceneManager() :current_scene(nullptr), is_finalize(false)
{
}

SceneManager::~SceneManager()
{
	Finalize();
}

void SceneManager::Initialize()
{
	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	//画面サイズの設定
	SetGraphMode(640, 480, 32);

	//DXライブラリの初期化
	if (DxLib_Init() == -1)
	{
		throw("DXライブラリが初期化できませんでした。\n");
	}

	//裏画面から描画を始める
	SetDrawScreen(DX_SCREEN_BACK);

	//タイトル画面からシーンを開始する
	ChangeScene(eSceneType::eInGame);
}

void SceneManager::Update()
{
	//開始時間を取得
	LONGLONG start_time = GetNowHiPerformanceCount();

	//入力機能のインスタンスを取得する
	InputControl* input = InputControl::GetInstance();

	//メインループ
	while (ProcessMessage() != -1)
	{
		//1フレーム当たりの時間を計算する
		float delta_second = static_cast<float>(GetNowHiPerformanceCount() -
			start_time) * 0.000001f;

		//開始時間の更新
		start_time = GetNowHiPerformanceCount();

		input->Update();

		//シーンの更新処理
		eSceneType next_scene_type = current_scene->Update(delta_second)

		//描画処理
		Draw();

		//シーン切り替え
		if(next_scene_type != current_scene->GetNowSceneType())
		{
			ChangeScene(next_scene_type);
		}

		//強制終了ボタン
		if (input->GetKeyUp(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}
}

void SceneManager::Finalize()
{
	if (is_finalize)
	{
		return;

		//入力機能のインスタンスを削除
		InputControl::DeleteInstance();

		//DXライブラリの終了処理
		DxLib_End();

		//終了処理成功
		is_finalize = true;
	}
}
void SceneManager::Draw() const
{
		//画面の初期化
		ClearDrawScreen();

		//シーンの描画処理
		current_scene->Draw();

		//裏画面の内容を表画面に反映する
		ScreenFlip();
}

void SceneManager::ChangeScene(eSceneType type)
{
	//引数で渡された情報から新しいシーンを作成する
	SceneBase* new_scene = SceneFactory::CreateScene(type);

	//エラーチェック
	if (new_scene == nullptr)
	{
		throw("シーンが生成できませんでした。\n");
	}

	//現在シーンの終了処理
	if (current_scene != nullptr)
	{
		current_scene->Finalize();
		delete current_scene;
	}
}