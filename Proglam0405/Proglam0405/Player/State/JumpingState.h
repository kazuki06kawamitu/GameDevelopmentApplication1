#pragma once
#include "PlayerStateBase.h"
#include"../../Utility/Vector2D.h"

///<summary>
///ジャンプ状態
/// </summry>
class Jumping : public PlayerStateBase
{
private:
	//目フレームの座標情報
	Vector2D old_location;

public:
///<summary>
///コンストラクタ
/// </summry>
/// <param name="p">プレイヤー情報</param>
	JumpingState(class Player* p);

	//デストラクタ
	virtual ~JumpingState();

public:
	//初期化処理関数
	virtual void Initialize() override;

	//終了処理関数
	virtual void Finalize() const override;

	//更新処理
	virtual void Update()override;

	//描画処理
	virtual void Draw() const override;

	//状態の取得
	virtual ePlayerState GetState() const override;
};