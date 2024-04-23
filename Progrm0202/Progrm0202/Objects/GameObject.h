#pragma once

#include "../Utility/Vector2D.h"

class GameObject
{
protected:
	unsigned int color;//色情報
	Vector2D location;//位置情報
	Vector2D box_size;//サイズ情報

public:
	GameObject();//コントラスト
	virtual ~GameObject();//デストラクタ

	virtual void Initialize();//初期化処理
	virtual void Update();//更新処理
	virtual void Draw()const;//描画処理
	virtual void Finalize();//終了時処理

public:
	virtual void SetLocation(Vector2D location);//位置情報取得
	virtual Vector2D GetLocation() const;//位置情報処理
	virtual Vector2D GetBoxSize() const;//サイズ情報処理
};