#include "Player.h"
#include "../../Utility/InputControl.h"
#include "../../Utility/UserTemplate.h"
#include "../../Utility/ResourceManager.h"
#include "DxLib.h"

//コンストラクタ
Player::Player() :
	velocity(0.0f),
	animation_data(),
	animation_count(0),
	sound_date(),
	sound_count(0)
{

}
//デストラクタ
Player::~Player()
{

}

//初期化処理
void Player::Initialize()
{
	//当たり判定の短形の大きさを設定
	box_size = Vector2D(23.0f);
	//初期位置を設定
	location = Vector2D(320.0f, 240.0f);

	//アニメーション画像を読み込む
	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int> tmp;
	tmp = rm->GetImages("Resource/Images/Tri-pilot/1.png");
	animation_data.push_back(tmp[0]);
	tmp = rm->GetImages("Resource/Images/Tri-pilot/2.png");
	animation_data.push_back(tmp[0]);
	
	//音源の読込み
	sound = rm->GetSound("Resource/Sounds/pokan.wav");

	//初期画像の設定
	image = animation_data[0];

	//アニメーションに関わる設定
	animation_count = 0;
	sound_count = 0;
}

//更新処理
void Player::Update()
{
	Movement();

	AnimationControl();
}

//描画処理
void Player::Draw() const
{
	__super::Draw();
}

//終了時処理
void Player::Finalize()
{
	animation_data.clear();
}

//移動処理
void Player::Movement()
{
	//入力情報の取得
	InputControl* input = InputControl::GetInstance();
	//入力状態によって、向きを変更する
	float direction = 0.0f;
	if (input->GetKey(KEY_INPUT_LEFT))
	{
		direction = -1.0f;
		flip_flag = TRUE;
	}
	else if (input->GetKey(KEY_INPUT_RIGHT))
	{
		direction = 1.0f;
		flip_flag = FALSE;
	}
	//向きによって、移動量の加減を行う
	if (direction != 0.0f)
	{
		float max_speed = Abs<float>((5.0f * 0.5f * direction));
		velocity.x += 0.5f * direction;
		velocity.x = Min<float>(Max<float>(velocity.x, -max_speed), max_speed);
	}
	else
	{
		if (velocity.x < -1e-6f)
		{
			float calc_speed = velocity.x + 0.1f;
			velocity.x = Min<float>(calc_speed, 0.0f);
		}
		else if (1e-6f < velocity.x)
		{
			float calc_speed = velocity.x - 0.1f;
			velocity.x = Max<float>(calc_speed, 0.0f);
		}
	}
	//画面外に行かないように制限する
	if (location.x < (box_size.x / 2.0f))
	{
		velocity.x = 0.0f;
		location.x = box_size.x / 2.0f;
	}
	else if ((640.0f - (box_size.x / 2.0f)) < location.x)
	{
		velocity.x = 0.0f;
		location.x = 640.0f - (box_size.x / 2.0f);
	}
	//位置座標を仮想区度分ずらしてあげる
	location += velocity;
}

//アニメーション制御
void Player::AnimationControl()
{
	animation_count++;
	if (animation_count >= 30)
	{
		animation_count = 0;

		if (image == animation_data[0])
		{
			image = animation_data[1];
		}
		else
		{
			image = animation_data[0];
		}
	}
}