#include "SceneManager.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

#include "TitleScene.h"

SceneManager::SceneManager() : current_scene(nullptr)
{
}

SceneManager::~SceneManager()
{
	//忘れ防止
	Finalize();
}

///<summary>
///初期化処理
/// </summary>
void SceneManager::Initialize()
{
		//ウィンドウモードで起動
		ChangeWindowMode(TRUE);

		//画面サイズの設定
		SetGraphMode(640, 480, 32);

		//Dxライブラリの初期化処理
		if (DxLib_Init() == -1)
		{
			throw("DXライブラリが初期化できませんでした\n");
		}

		//裏画面から描画を始める
		SetDrawScreen(DX_SCREEN_BACK);

		//タイトル画面からシーンを開始する
		ChangeScene(eSceneType::eTitle);
}

/// <summary>
/// 実行処理
/// </summary>
void SceneManager::Run()
{
	//入力機能のインスタンスを取得する
	InputControl* input = InputControl::GetInstance();

	//メインループ(ウィンドウが閉じられるorESCキーが入力された でループを終了する)
	while (ProcessMessage() != -1 && input->GetKeyUp(KEY_INPUT_ESCAPE) != true)
	{
		//シーンの更新処理
		eSceneType next_scene_type = current_scene->Update();

		//シーンの描画処理
		Draw();

		//シーンの切り替え
		if (next_scene_type = current_scene->GetNowSceneType())
		{
			ChangeScene(next_scene_type);
		}
	}
}

/// <summary>
/// 終了時処理
/// </summary>
void SceneManager::Finalize()
{
	//シーン情報が生成されていれば、削除する
	if (current_scene != nullptr)
	{
		current_scene->Finalize();
		delete current_scene;
		current_scene = nullptr;
	}
	//入力機能のインスタンスを削除
	InputControl::DeleteInstance();

	//DXライブラリの終了処理
	DxLib_End();
}

/// <summary>
/// 描画処理
/// </summary>
void SceneManager::Draw() const
{
	//画面の初期化
	ClearDrawScreen();

	//シーンの描画処理
	current_scene->Draw();

	//裏画面の内容を表画面に反映する
	ScreenFlip();
}

/// <summary>
/// シーンの切り替え処理
/// </summary>
/// <param name="typr">シーンの情報</param>
void SceneManager::ChangeScene(eSceneType type)
{
	//引数で渡された情報から新しいシーンを作成する
	SceneBase* new_scene = CreateScene(type);

	//エラーチェック
	if (new_scene == nullptr)
	{
		throw("シーンが生成できませんでした\n");
	}

	//現在シーンの終了処理
	if (current_scene != nullptr)
	{
		current_scene->Finalize();
		delete current_scene;
	}

	//新しいシーンの初期化
	new_scene->Initialize();
	current_scene = new_scene;
}

/// <summary>
/// シーン生成処理
/// </summary>
/// <param name="type">シーン情報</param>
/// <returns>シーンクラスポインタ</returns>
SceneBase* SceneManager::CreateScene(eSceneType type)
{
	//シーン情報によって、生成するシーンを切り替える
	switch (type)
	{
	case eSceneType::eTitle:
		return dynamic_cast<SceneBase*>(new TitleScene());
	defalt:
		return nullptr;
	}
}