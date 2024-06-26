#include "Bomb.h"
#include "DxLib.h"
#include "../Enemy/Enemy.h"
#include "../Enemy/GoldEnemy.h"
#include "../Enemy/Harpy.h"
#include "../Enemy/WingEnemy.h"
#include <vector>

Bomb::Bomb() : direction(0.0f)
{
	animation[0] = NULL;
	animation[1] = NULL;
	animation[2] = NULL;
	animation_count = 0;
}

Bomb::~Bomb()
{
}

//初期化処理
void Bomb::Initialize()
{
	//画像の読み込み
	image = LoadGraph("Resource/Images/Bomb/Bomb.png");
	//画像の読み込み
	animation[0] = LoadGraph("Resource/Images/Blast/1.png");
	animation[1] = LoadGraph("Resource/Images/Blast/2.png");
	animation[2] = LoadGraph("Resource/Images/Blast/3.png");

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
	AnimationControl();
	//animation_count++;
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
	if (dynamic_cast<Enemy*>(hit_object) != nullptr)
	{
		DeleteGraph(image);
		image = animation[0];
		radian = 0.0;
		direction = 0.0f;
		
	}
	if (dynamic_cast<GoldEnemy*>(hit_object) != nullptr)
	{
		DeleteGraph(image);
		image = animation[0];
		radian = 0.0;
		direction = 0.0f;
	}
	if (dynamic_cast<Harpy*>(hit_object) != nullptr)
	{
		DeleteGraph(image);
		image = animation[0];
		radian = 0.0;
		direction = 0.0f;
	}
	if (dynamic_cast<WingEnemy*>(hit_object) != nullptr)
	{
		DeleteGraph(image);
		image = animation[0];
		radian = 0.0;
		direction = 0.0f;
	}
	
	
}
//移動処理
void Bomb::Movement()
{
	//地面に到達したら、画像と判定をなくす
	if (((location.y + direction.y) < box_size.y) ||
		(380.0f + box_size.y) < (location.y + direction.y))
	{
		DeleteGraph(image);
		image = animation[0];
		radian = 0.0;
		direction = 0.0f;
	}

	//進行方向に向かって、位置座標を変更する
	location += direction;
}

//アニメーション制御
void Bomb::AnimationControl()
{
	//アニメーションカウントを加算する
	animation_count++;
	//30フレーム目に到達したら
	if (animation_count >= 60)
	{
		//カウントリセット
		animation_count = 0;

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