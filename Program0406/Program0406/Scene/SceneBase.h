#pragma once

#include "../Utility/InputEventManager.h"

enum eSceneType
{
	eTitle,
	eInGame,
	eResult,
	eEnd,
};

class SceneBase
{
protected:
	//全シーンで所有するメンバ変数を宣言
	InputEventManager* input_event;
public:
	SceneBase() : input_event(nullptr)
	{

	}
	virtual~SceneBase()
	{

	}

	//初期化処理
	virtual void Initialize()
	{
		//入力イベントのインスタンスを取得
		input_event = InputEventManager::GetInstance();
	}

	//更新処理
	//引数:１フレーム当たりの時間
	//戻り値:次のシーンタイプ
	virtual eSceneType Update(float delta_second)
	{
		//登録されている入力イベントの呼出
		input_event->InputActionEvent();

		return GetNowSceneType();
	}

	//描画処理
	virtual void Draw() const
	{
	}

	//終了時処理
	virtual void Finalize()
	{
		input_event->AllUnbind();
	}
	//現在のシーンタイプ(オーバーライド必須)
	virtual eSceneType GetNowSceneType() const = 0;
};