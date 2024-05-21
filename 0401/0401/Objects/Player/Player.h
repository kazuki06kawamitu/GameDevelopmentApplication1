#pragma once

#include "../GameObject.h"
#include <vector>

class Player : public GameObject
{
private:
	Vector2D velocity;  //加速度
	std::vector<int> animation_data;  //アニメーション
	int animation_count;  //アニメーション時間

public:
	Player();//コンストラクタ
	virtual ~Player();//デストラクタ

	virtual void Initialize() override;//初期化処理
	virtual void Update() override;//更新処理
	virtual void Draw() const override;//描画処理
	virtual void Finalize() override;//終了時処理

private:
	void Movement();//移動処理
	void AnimationControl();//アニメーション制御
};