#pragma once

#include "../GameObject.h"
#include "../../Utility/StageData.h"

#define D_ENEMY (1)

enum eEnemyState  //状態モード
{
	RESPWAN,	// 復活状態
	SEARCH,		// 探索状態
	CHASE,		//追いかけ状態
	DIE,		// 死亡状態
};


class EnemyBase : public GameObject
{
protected:
	// 進行方向状態
	enum eDirectionState : unsigned char
	{
		UP,
		RIGHT,
		DOWN,
		LEFT,
		NONE,
	};

private:
	std::vector<int> move_animation;		// 移動のアニメーション画像
	std::vector<int> dying_animation;		// 死亡のアニメーション画像
	Vector2D old_location;					// 前回のlocation
	Vector2D velocity;						// 移動量
	eEnemyState enemy_state;				// 敵の状態
	eDirectionState now_direction_state;	// 現在進行方向状態
	eDirectionState next_direction_state;	// 次回進行方向状態
	float animation_time;					// アニメーション時間
	int animation_count;					// アニメーション添字

public:
	EnemyBase();
	virtual ~EnemyBase();

	virtual void Initialize() override;
	virtual void Update(float delta_second) override;
	virtual void Draw(const Vector2D& screen_offset) const override;
	virtual void Finalize() override;

	/// <summary>
	/// 当たり判定通知処理
	/// </summary>
	/// <param name="hit_object">当たったゲームオブジェクトのポインタ</param>
	virtual void OnHitCollision(GameObjectBase* hit_object) override;

public:
	/// <summary>
	/// 敵の状態を取得する
	/// </summary>
	/// <returns>敵の状態</returns>
	eEnemyState GetEnemyState() const;

	/// <summary>
	/// パワーダウンさせる
	/// </summary>
	void SetPowerDown();

private:
	/// <summary>
	/// 移動処理
	/// </summary>
	/// <param name="delta_second">1フレームあたりの時間</param>
	void Movement(float delta_second);

	/// <summary>
	/// アニメーション制御
	/// </summary>
	/// <param name="delta_second">1フレームあたりの時間</param>
	void AnimationControl(float delta_second);
};