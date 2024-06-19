#include "Blast.h"
#include "DxLib.h"

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
	//画像の読み込み
	animation[0] = LoadGraph("Resource/Images/Blast/1.png");
	animation[1] = LoadGraph("Resource/Images/Blast/2.png");
	animation[2] = LoadGraph("Resource/Images/Blast/3.png");

	//エラーチェック
	if (animation[0] == -1 || animation[1] == -1||animation[2]==-1)
	{
		throw("爆発の画像がありません\n");
	}

	//向きの設定
	radian = 0.0f;

	//当たり判定の大きさを設定
	box_size = 64.0f;

	//初期画像の設定
	image = animation[0];

	//初期進行方向の設定
	direction = Vector2D(1.0f, 1.0f);
}

//更新処理
void Blast::Update()
{
	//移動処理
	Movement();

	//アニメーション制御
	AnimationControl();
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

	//情報を基にハコテキ画像を描画する
	DrawRotaGraphF(location.x, location.y, 0.5, radian, image, TRUE, FALSE);

	//親クラスの描画処理を呼び出す
	__super::Draw();
}

//終了処理
void Blast::Finalize()
{
	//使用した画像を解放
	DeleteGraph(animation[0]);

}

//当たり判定通知処理
void Blast::OnHitCollision(GameObject* hit_object)
{
	//当たった時の処理
	direction = 0.0f;
}

//移動処理
void Blast::Movement()
{
	//画面端に到達したら、進行方向を反転する
	if (((location.x + direction.x) < box_size.x) ||
		(640.0f - box_size.x) < (location.x + direction.x))
	{
		direction.x *= 0.0f;
	}

	if (((location.y + direction.y) < box_size.y) ||
		(480.0f - box_size.y) < (location.y + direction.y))
	{
		direction.y *= 0.0f;
	}

	//進行方向に向かって、位置座標を変更する
	location += direction;
}

//アニメーション制御
void Blast::AnimationControl()
{
	//アニメーションカウントを加算する
	animation_count++;

	//30フレーム目に到達したら
	if (animation_count >= 30)
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
		}
		else
		{
			image = animation[0];
		}
	}
}