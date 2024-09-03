#pragma once

#include "../GameObject.h"
#include "EnemyBase.h"
#include"../Food/Food.h"
#include "../Food/PowerFood.h"
#include"../../Utility/StageData.h"


class Akabe :public GameObject
{
private:
	std::vector<int> move_animation;		// 移動のアニメーション画像
	std::vector<int> dying_animation;		// 死亡のアニメーション画像
	Vector2D old_location;					// 前回のlocation
	Vector2D velocity;						// 移動量
	eEnemyState enemy_state;				// 敵の状態
	ePanelID old_panel;						// 前回パネル情報
	float animation_time;					// アニメーション時間
	int animation_count;					// アニメーション添字
	int food_count;							// 餌を食べられた数
	bool is_destroy;						// 死んだ状態になったか？
	bool is_power_down;						//いじけ状態になっているか？


	// 移動アニメーションの順番
	const int animation_num[4] = { 0, 1, 2, 1, };

public:
	Akabe();
	virtual ~Akabe();

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
	bool GetPowerDown() const;

	/// <summary>
	/// 敵がパワーアップしてるか確認する
	/// </summary>
	/// <returns>プレイヤーの状態</returns>
	void GetPowerUp() const;

	// <summary>
	/// プレイヤーがパワーアップしてるか確認する
	/// </summary>
	/// <returns>プレイヤーの状態</returns>
	bool GetDestroy() const;

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