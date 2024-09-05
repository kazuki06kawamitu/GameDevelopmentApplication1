#pragma once

#include "../GameObject.h"
#include "../../Utility/StageData.h"

#define D_ENEMY (1)

enum eEnemyState  //状態モード
{

	E_MOVE,
	E_IDLE,
	E_DIE,
};


class EnemyBase : public GameObject
{
public:
	EnemyBase();
	virtual ~EnemyBase();
private:
	// 進行方向状態
	enum eDirectionState : unsigned char
	{
		UP,
		RIGHT,
		DOWN,
		LEFT,
	};

private:
	std::vector<int> move_animation;		// 移動のアニメーション画像
	std::vector<int> dying_animation;		// 死亡のアニメーション画像
	Vector2D old_location;					// 前回のlocation
	Vector2D velocity;						// 移動量
	eEnemyState enemy_state;				// 敵の状態
	eDirectionState now_direction_state;	// 現在進行方向状態
	eDirectionState next_direction_state;	// 次回進行方向状態
	ePanelID old_panel;						// 前回パネル情報
	float animation_time;					// アニメーション時間
	int animation_count;					// アニメーション添字
	int food_count;							// 餌を食べられた数
	bool is_destroy;						// 死んだ状態になったか？
	bool is_power_down;						//いじけ状態になっているか？

	// 移動アニメーションの順番
	const int animation_num[4] = { 0, 1, 2, 1, };

public:
	

	/// <summary>
	/// 初期化処理
	/// </summary>
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
	bool GetPowerDown();

	/// <summary>
	/// パワーダウンさせる
	/// </summary>
	void SetPowerDown();

	/// <summary>
	/// パワーダウンさせる
	/// </summary>
	bool GetDestroyDown() const;

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