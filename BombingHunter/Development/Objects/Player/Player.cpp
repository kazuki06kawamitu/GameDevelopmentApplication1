#include "Player.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"

Player::Player() :animation_count(0), flip_flag(FALSE)
{
	animation[0] = NULL;
	animation[1] = NULL;
}

Player::~Player()
{
}

//初期化処理
void Player::Initialize()
{
	//画像の読み込み
	animation[0] = LoadGraph("Resource/Images/Tri-pilot/1.png");
	animation[1] = LoadGraph("Resource/Images/Tri-pilot/2.png");

	//エラーチェック
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("鳥パイロットの画像がありません\n");
	}

	//向きの設定
	radian = 0.0f;

	//当たり判定の大きさを設定
	box_size = Vector2D(64.0f);

	//初期画像の設定
	image = animation[0];

	//オブジェクトの数値設定
	object_flag = D_PLAYER;
}

//更新処理
void Player::Update()
{
	//移動処理
	Movement();

	//アニメーション制御
	AnimationControl();
}

//描画処理
void Player::Draw() const
{
	//プレイヤー画像の描画
	DrawRotaGraphF(location.x, location.y, 0.5, radian, image, TRUE, flip_flag);

	//デバック用
#if _DEBUG
	//当たり判定の可視化
	Vector2D ul = location - (box_size / 2.0f);
	Vector2D br = location + (box_size / 2.0f);

	DrawBoxAA(ul.x, ul.y, br.x, br.y, GetColor(255, 0, 0), FALSE);
#endif
}

//終了処理
void Player::Finalize()
{
	//使用した画像を解放
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}

//当たり判定通知処理
void Player::OnHitCollision(GameObject* hit_object)
{
	//当たった時の処理
}

//移動処理
void Player::Movement()
{
	//移動の速さ
	Vector2D velocity = 0.0f;

	//左右移動
	if (InputControl::GetKey(KEY_INPUT_LEFT))
	{
		velocity.x += -1.0f;
		flip_flag = TRUE;
	}
	else if (InputControl::GetKey(KEY_INPUT_RIGHT))
	{
		velocity.x += 1.0f;
		flip_flag = FALSE;
	}
	else
	{
		velocity.x = 0.0f;
	}

	//画面端に到達したら、止めるする
	if (((location.x + velocity.x) < (95-box_size.x) ||
		(680.0f - box_size.x) < (location.x + velocity.x)))
	{
		velocity.x = 0.0f;
	}

	//現在の位置座標に速さを加算する
	location += velocity;
}

//アニメーション制御
void Player::AnimationControl()
{
	//アニメーションカウントを加算する
	animation_count++;

	//60フレーム目に到達したら
	if (animation_count >= 60)
	{
		//カウントリセット
		animation_count = 0;

		//画像の切替
		if (image == animation[0])
		{
			image = animation[1];
		}
		else
		{
			image = animation[0];
		}
	}
}

Vector2D Player::SetLocation()
{
	return location;
}