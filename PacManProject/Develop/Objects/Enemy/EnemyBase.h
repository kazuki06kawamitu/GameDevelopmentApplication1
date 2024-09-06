#pragma once

#include "../GameObject.h"
#include "../../Utility/StageData.h"



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
	enum EnemyeDirectionState : unsigned char
	{
		UP,
		RIGHT,
		DOWN,
		LEFT,
	};

private:
	std::vector<int> body_animation;		// 移動のアニメーション画像
	std::vector<int> eye_animation;		// 死亡のアニメーション画像
	Vector2D old_location;					// 前回のlocation
	Vector2D velocity;						// 移動量
	eEnemyState enemy_state;				// 敵の状態
	EnemyeDirectionState now_direction_state;	// 現在進行方向状態
	float animation_time;					// アニメーション時間
	int animation_count;					// アニメーション添字
	bool is_destroy;						// 死んだ状態になったか？
	bool is_power_down;						//いじけ状態になっているか？
	int body_image;							//体のイメージ
	int eye_image;							//目のイメージ

	// 移動アニメーションの順番
	const int animation_num[2] = { 0, 1,};

public:
	//初期化処理
	virtual void Initialize() override;
	//更新処理
	virtual void Update(float delta_second) override;
	//描画処理
	virtual void Draw(const Vector2D& screen_offset) const override;
	//終了時処理
	virtual void Finalize() override;

	//ヒット時処理
	virtual void OnHitCollision(GameObjectBase* hit_object) override;

public:
	//敵の状態
	eEnemyState GetEnemyState() const;


	//パワーダウン状態
	bool GetPowerDown();

	//パワーダウン確認処理
	void SetPowerDown();

	//削除処理
	bool GetDestroyDown() const;

private:
	//移動処理
	void Movement(float delta_second);

	//アニメーション処理
	void AnimationControl(float delta_second);
};