#pragma once
#include "SceneBase.h"

class InGameScene :public SceneBase
{
private:
	class Player* player;

public:
	InGameScene();
	virtual ~InGameScene();

	//初期化処理
	virtual void Initialize() override;

	//更新処理
	//引数:１フレーム当たりの時間
	//戻り値:次のシーンタイプ
	virtual eSceneType Update(float delete_second) override;

	//描画処理
	virtual void Draw() const override;

	//終了時処理
	virtual void Finalize()override;

	//現在のシーンタイプ(オーバーライド必須)
	virtual eSceneType GetNowSceneType()const override;
};