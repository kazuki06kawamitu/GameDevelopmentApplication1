#pragma once

#include "../Utility/Vector2D.h"

class GameObject
{
protected:
	int image;//画像
	Vector2D location;//位置
	Vector2D box_size;//サイズ

public:
	GameObject();//コントラクタ
	virtual ~GameObject();//デストラクタ

	virtual void Initialize();//初期化処理
	virtual void Update();//更新処理
	virtual void Draw() const;//描画処理
	virtual void Finalize();//終了時処理

public:
	void SetLocation(Vector2D location);//位置情報取得
	Vector2D GetLocation() const;//位置情報処理
	Vector2D GetBoxSize() const;//サイズ情報処理
};