#pragma once
#include "PlayerStateBase.h"
#include"../../Utility/Vector2D.h"

///<summary>
///ジャンプ状態
/// </summry>
class RunState : public PlayerStateBase
{
private:
	//入力情報
	class InputControl* input;

	//加速度加算値
	float speed;

public:
	///<summary>
	///コンストラクタ
	/// </summry>
	/// <param name="p">プレイヤー情報</param>
	RunState(class Player* p);

	//デストラクタ
	virtual ~RunState();

public:
	//初期化処理関数
	virtual void Initialize() override;

	//終了処理関数
	virtual void Finalize() override;

	//更新処理
	virtual void Update()override;

	//描画処理
	virtual void Draw() const override;

	//状態の取得
	virtual ePlayerState GetState() const override;
};