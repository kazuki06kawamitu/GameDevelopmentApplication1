#pragma once

#include "SceneBase.h"

class ResultScene :public SceneBase
{
private:

public:
	ResultScene();
	virtual~ResultScene();

	//初期化処理
	virtual void Initialize() override;
	//更新処理
	//引数:１フレーム当たりの時間
	//戻り値:次のシーンタイプ
	virtual eSceneType Update() override;

	//描画処理
	virtual void Draw()const override;

	//終了処理
	virtual void Finalize() override;

	//現在シーンタイプ(オーバーライド必須)
	virtual eSceneType GetNowSceneType() const override;
};