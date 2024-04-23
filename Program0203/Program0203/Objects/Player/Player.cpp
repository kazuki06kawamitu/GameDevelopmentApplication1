#include "Player.h"
#include "../../Utility/InputControl.h"
#include "../../Utility/UserTemplate.h"
#include "DxLib.h"
//コンストラクタ
Player::Player():velocity(0.0f)
{

}

//デストラクタ
Player::~Player()
{

}
//初期化処理
void Player::Initialize()
{
	color = GetColor(255, 255, 255);

	box_size = Vector2D(32.0f);

	location = Vector2D(320.0f, 240.0f);
	
	
}
//更新処理
void Player::Update()
{
	Movement();
}
//描画処理
void Player::Draw() const
{
	Vector2D upper_left = location - (box_size / 2.0f);
	Vector2D lower_right =location + (box_size / 2.0f);

	DrawBoxAA(upper_left.x, upper_left.y, lower_right.x, lower_right.y, color, TRUE);
}
//終了時処理
void Player::Finalize()
{

}

//移動処理
void Player::Movement()
{
	Vector2D direction = Vector2D(0.0f);
	
	if (InputControl::GetKey(KEY_INPUT_LEFT))
	{
		direction.x = -0.5f;//左に移動
		//最高速度
		float max_speed = Abs<float>((5.0f * direction.x));
		//速度に加算する
		velocity.x += direction.x;
		//速度の最大を超えないようにする
		velocity.x = Min<float>(Max<float>(velocity.x, -max_speed), max_speed);
	}
	else if(InputControl::GetKey(KEY_INPUT_RIGHT))
	{
		direction.x = 0.5f;//右に移動
		//最高速度
		float max_speed = Abs<float>((5.0f * direction.x));
		//速度に加算する
		velocity.x += direction.x;
		//速度の最大を超えないようにする
		velocity.x = Min<float>(Max<float>(velocity.x, -max_speed), max_speed);
	}
	else
	{
		//入力してないとき
		if (velocity.x > 1e-6f)//減速処理
		{
			//右移動時の減速
			float calc_speed = velocity.x - 0.1f;
			velocity.x = Min<float>(Max<float>(calc_speed, 0.0f), velocity.x);
		}
		else if (velocity.x < 1e-6f)
		{
			//左移動時の減速
			float calc_speed = velocity.x - 0.1f;
			velocity.x = Min<float>(Max<float>(calc_speed, velocity.x), 0.0f);
		}
	}
	//壁に当たった時のチェック
	if (location.x<(box_size.x/2.0f))
	{
		//左壁
		velocity.x = 0.0f;
		location.x = box_size.x / 2.0f;
	}
	else if (location.x > (640.0f - box_size.x / 2.0f))
	{
		//右端
		velocity.x = 0.0f;
		location.x = 640.0f - box_size.x / 2.0f;
	}
	
	//座標移動
	location += direction;
}