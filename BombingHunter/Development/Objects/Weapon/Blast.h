#pragma once

#include "../GameObject.h"

class Blast :public GameObject
{
private:
	int animation[3];  //アニメション画像
	int animation_count;  //アニメション時間
	Vector2D direction;  //進行方向

public:
	Blast();
	~Blast();

	//初期化処理
	virtual void Initialize() override;

	//更新処理
	virtual void Update() override;

	//描画処理
	virtual void Draw() const override;

	//終了処理
	virtual void Finalize() override;

	//当たり判定通知処理
	virtual void OnHitCollision(GameObject* hit_object) override;

	//
	virtual Vector2D GetLocation();

	//
	void SetDirection(Vector2D p_loc);

private:
	//移動処理
	void Movement();
	//アニメーション制御
	void AnimationControl();
};