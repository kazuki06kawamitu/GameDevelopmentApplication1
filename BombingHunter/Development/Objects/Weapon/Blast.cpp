#include "Blast.h"
#include "DxLib.h"
#include "../Player/Player.h"
#include "../Enemy/Enemy.h"
#include "math.h"
#include <vector>


Blast::Blast() :animation_count(0), direction(0.0f)
{
	animation[0] = NULL;
	animation[1] = NULL;
	animation[2] = NULL;

}

Blast::~Blast()
{
}

//初期化処理
void Blast::Initialize()
{
	//画像の読み込み.初期画像の設定
	image = LoadGraph("Resource/Images/EnemyBullet/1.png");
	//画像の読み込み
	animation[0] = LoadGraph("Resource/Images/EnemyBullet/eff1.png");
	animation[1] = LoadGraph("Resource/Images/EnemyBullet/eff2.png");
	animation[2] = LoadGraph("Resource/Images/EnemyBullet/eff3.png");

	//エラーチェック
	if (animation[0] == -1 || animation[1] == -1||animation[2]==-1)
	{
		throw("敵の弾の画像がありません\n");
	}

	//向きの設定
	radian = 0.0f;

	//当たり判定の大きさを設定
	box_size = 30.0f;

	//
	#define D_ENEMYBULLET (1)

	//初期進行方向の設定
	direction = Vector2D(0.0f, 0.0f);

}

//更新処理
void Blast::Update()
{
	//移動処理
	Movement();

	//アニメーション制御
	AnimationControl();

	//位置情報更新
	//direction=Vector2D();
}

//描画処理
void Blast::Draw() const
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

	//情報を基に弾画像を描画する
	DrawRotaGraphF(location.x, location.y, 0.5, radian, image, TRUE, FALSE);

	//親クラスの描画処理を呼び出す
	__super::Draw();
}

//終了処理
void Blast::Finalize()
{
	//使用した画像を解放
	DeleteGraph(image);

}

//当たり判定通知処理
void Blast::OnHitCollision(GameObject* hit_object)
{
	//当たった時の処理
	if (dynamic_cast<Player*>(hit_object) != nullptr)
	{
		DeleteGraph(image);
		image = animation[0];
		radian = 0.0;
		direction = 0.0f;
		box_size = 0.0f;

	}
}

//移動処理
void Blast::Movement()
{
	



	//画面端に到達したら、画像を削除する
	if (((location.y + direction.y) < box_size.y) ||
		(600.0f - box_size.y) < (location.y + direction.y))
	{
		delete_flag = TRUE;
	}

	//進行方向に向かって、位置座標を変更する
	location += direction;
}

//
Vector2D Blast::GetLocation()
{
	return location;
 }

//アニメーション制御
void Blast::AnimationControl()
{
	//アニメーションカウントを加算する
	animation_count++;

	//30フレーム目に到達したら
	if (animation_count >= 60)
	{


		//画像の切替
		if (image == animation[0])
		{
			image = animation[1];
		}
		else if (image == animation[1])
		{
			image = animation[2];
			delete_flag = TRUE;
		}
		else
		{


		}
		animation_count = 0;
	}
}

void Blast::SetDirection(Vector2D p_loc)
{
	//進行方向に向かって、位置座標を変更する
	Vector2D vec;
	//目的の位置までの距離をとる
	//xの距離
	vec.x = ((p_loc.x - location.x) / 180);
	//yの距離
	vec.y = ((p_loc.y - location.y) / 180);

	//距離の確定
	direction.x = vec.x;
	direction.y = vec.y;
	
}