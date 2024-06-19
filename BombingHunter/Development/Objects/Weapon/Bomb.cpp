#include "Bomb.h"
#include "DxLib.h"

Bomb::Bomb() : direction(0.0f)
{

}

Bomb::~Bomb()
{
}

//初期化処理
void Bomb::Initialize()
{
	//画像の読み込み
	image = LoadGraph("Resource/Images/Bomb/Bomb.png");

	//エラーチェック
	if (image== -1)
	{
		throw("爆弾の画像がありません\n");
	}

	//向きの設定
	radian = DX_PI_F/2;

	//当たり判定の大きさを設定
	box_size = 30.0f;

	//初期進行方向の設定
	direction = Vector2D(0.0f, 1.0f);

	//
	object_flag = D_BOMB;
}

//更新処理
void Bomb::Update()
{
	//移動処理
	Movement();

	//アニメーション制御
	//AnimationControl();
}

//描画処理
void Bomb::Draw() const
{
	//画像反転フラグ
	int flip_flag = FALSE;

	//進行方向によって、判定状態を決定する
	if (direction.x > 0.0f)
	{
		flip_flag = FALSE;
	}
	else
	{
		flip_flag = TRUE;
	}

	//情報を基に爆弾画像を描画する
	DrawRotaGraphF(location.x, location.y, 0.5, radian, image, TRUE, FALSE);

	//親クラスの描画処理を呼び出す
	__super::Draw();
}

//終了処理
void Bomb::Finalize()
{
	//使用した画像を解放
	DeleteGraph(image);

}

//当たり判定通知処理
void Bomb::OnHitCollision(GameObject* hit_object)
{
	//当たった時の処理
	direction = 0.0f;
	box_size = 0.0f;
}

//移動処理
void Bomb::Movement()
{
	//地面に到達したら、画像と判定をなくす
	if (((location.y + direction.y) < box_size.y) ||
		(100.0f - box_size.y) < (location.y + direction.y))
	{
		direction.y == 0.0f;
	}

	//進行方向に向かって、位置座標を変更する
	location += direction;
}

//アニメーション制御
//void Bomb::AnimationControl()
//{
//	//アニメーションカウントを加算する
//	animation_count++;
//
//	//30フレーム目に到達したら
//	if (animation_count >= 30)
//	{
//		//カウントリセット
//		animation_count = 0;
//
//		//画像の切替
//		if (image == animation[0])
//		{
//			image = animation[1];
//		}
//		else
//		{
//			image = animation[0];
//		}
//	}
//}