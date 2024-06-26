#pragma once

#include "SceneBase.h"

class SceneManager
{
private:
	SceneBase* current_scene;  //現在シーン情報のポインタ

public:
	SceneManager();
	~SceneManager();

	//初期化処理
	void Initialize();

	//更新処理
	void Run();

	//終了時処理
	void Finalize();

private:
	//描画処理
	void Draw() const;
	//シーンの切り替え処理
	void ChangeSene(eSceneType type);
	//シーン生成処理
	SceneBase* CreateScene(eSceneType type);
};