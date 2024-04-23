#pragma once

#include "GameObject.h"

class Player :public GameObject
{
private:
	
public:
	Player();//コントラスト
	virtual ~Player();//デストラクタ

	void Initialize()override;//初期化処理
	void Update()override;//更新処理
	void Draw() const override;//描画処理
	void Finalize()override;//終了時処理

private:
	void Movement();//移動処理
};