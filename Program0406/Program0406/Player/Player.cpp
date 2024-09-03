#include "Player.h"
#include "../Utility/InputEventManager.h"
#include "DxLib.h"

#define D_GRAVITY (9.807f)  //重力加速度(m/ss)

Player::Player()
	:location(0.0f)
	,velocity(0.0f)
	,box_size(0.0f)
{

}

Player::~Player()
{

}

void Player::Initialize()
{
	location = Vector2D(320.0f, 400.0f);
	velocity = 0.0f;
	box_size = 32.0f;
	g_velocity = 0.0f;

	//入力イベントの登録
	InputEventManager* input_event = InputEventManager::GetInstance();
	input_event->ActionKeyBind(KEY_INPUT_LEFT, -1.0f, this, &Player::Movement);
	input_event->ActionKeyBind(KEY_INPUT_RIGHT, 1.0f, this, &Player::Movement);
	input_event->ActionKeyBind(KEY_INPUT_SPACE, -10.0f, this, &Player::MovementJanp);
}

void Player::Update(float delta_second)
{
	//移動量分たけ位置をずらす
	location += velocity * delta_second;
	
	//重力速度の計算
	g_velocity += D_GRAVITY / 444.0f;
	velocity.y += g_velocity;

	//画面外に行かないようにする
	if (location.x >= 640.0f)
	{
		location.x = 640.0f;
		velocity.x = 0.0f;
	}
	if (location.x < 0.0f)
	{
		location.x = 0.0f;
		velocity.x = 0.0f;
	}
	if (location.y >= 400.0f)
	{
		location.y = 400.0f;
		velocity.y = 0.0f;
		g_velocity = 0.0f;
	}
	if (location.y < 0.0f)
	{
		location.y = 0.0f;
		velocity = 0.0f;
		g_velocity = 0.0f;
	}
}

void Player::Draw() const
{
	Vector2D tl = location - (box_size * 0.5f);
	Vector2D br = tl + box_size;

	DrawBoxAA(tl.x, tl.y, br.x, br.y, GetColor(255, 0, 0), TRUE);
}

void Player::Finalize()
{

}

void Player::Movement(float param)
{
	velocity.x += param;
}

void Player::MovementJanp(float param)
{
	velocity.y += param;
	g_velocity = 0.0f;
}