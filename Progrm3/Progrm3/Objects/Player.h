#pragma once

#include "../Utility/Vector2D.h"
//２次元ベクトルクラス
class Player
{
private:
	Vector2D location;  //位置座標
	Vector2D direction; //方向座標
	float radius;       //半径（小数点を含む）

public:
	Player();                 //コンストラクタ
	Player(float x, float y); //引数の値で初期化
	Player(Vector2D location);//
	~Player();                //デストラクタ

	void Update();     //更新処理
	void Draw() const; //描画処理

	void SetLocation(float x, float y); //セッター
	void SetLocation(Vector2D location); //
	Vector2D GetLocation() const; //ゲッター
	float GetRadius();    //

private:
	void Movement();//移動処理（キーの入力で
};