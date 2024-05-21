#pragma once

#include "../Utility/Vector2D.h"

//ゲームオブジェクトクラス(画面に出てくるオブジェクトの親クラス)
class GameObject
{
protected:
	Vector2D location;  //位置座標情報
	Vector2D box_size;  //短形の大きさ
	int image;  //描画する画像データ
	int flip_flag;  //描画反転フラグ

public:
	GameObject();
	virtual~GameObject();

	//初期化処理
	virtual void Initialize();
	//更新処理
	virtual void Update();
	//描画処理
	virtual void Draw() const;
	//終了処理
	virtual void Finalize();

public:
	Vector2D GetLocation() const;
	Vector2D GetBoxSize() const;

	void Setlocation(const Vector2D& location);
};