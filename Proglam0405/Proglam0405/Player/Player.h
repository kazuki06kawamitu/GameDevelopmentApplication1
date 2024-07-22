#pragma once
#include <vector>
#include "State/Enum/PlayerState.h"
#include"../Utility/Vector2D.h"

///<summary>
///プレイヤークラス
/// </summry>
class Player
{
private:
	class PlayerStateBase* state = nullptr;  //現在の状態
	ePlayerState next_state = ePlayerState::NONE;  //次の状態
	float g_velocity = 0.0f;                 //重力速度
	Vector2D location = Vector2D(0.0f);      //座標

public:
	Vector2D velocity = Vector2D(0.0f);    //速度
	Vector2D box_size = Vector2D(0.0f);    //サイズ

public:
	Player() = default;                  //コンストラクタ
	~Player() = default;                 //デフォルトのデストラクタを使用

public:
///<summary>
///初期化処理
/// </summry>
///<param name="init_location">初期座標</param>
	void Initialize(Vector2D init_location = Vector2D(0.0f));

///<summary>
///終了処理
/// </summry>
	void Finalize();

///<summary>
///更新処理
/// </summry>
	void Update();

///<summary>
///描画処理
/// </summry>
	void Draw() const;

public:
///<summary>
///次のStateを設定
/// </summry>
/// <Player name="next_state">次のState</param>
	void SetNextState(ePlayerState next_state);

///<summary>
///座標の取得
/// </summry>
	Vector2D& GetLocation();
};