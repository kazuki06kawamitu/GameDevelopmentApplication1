#include "Player.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"
//�R���X�g���N�^�i�������q���g���������������j
Player::Player() :location(), direction(0.0f), radius(15.0f)
{
}

Player::Player(float x, float y) : location(x, y), direction(0.0f), radius(15.0f)
{
}

Player::Player(Vector2D location) : direction(0.0f), radius(15.0f)
{
	this->location = location;
}
//�f�X�g���N�^
Player::~Player()
{

}
//�X�V����
void Player::Update()
{
	Movement();
}
//�`�揈��
void Player::Draw() const
{
	DrawCircleAA(location.x, location.y, radius, 50, GetColor(255, 255, 255), TRUE);
}

void Player::SetLocation(float x, float y)
{
	SetLocation(Vector2D(x, y));
}

void Player::SetLocation(Vector2D location)
{
	this->location = location;
}

Vector2D Player::GetLocation() const
{
	return location;
}

float Player::GetRadius()
{
	return radius;
}
//�ړ�����
void Player::Movement()
{
	if (InputControl::GetKeyDown(KEY_INPUT_UP))
	{
		direction.y = -1.0f;//���
	}
	if (InputControl::GetKeyDown(KEY_INPUT_DOWN))
	{
		direction = 1.0f;//����
	}
	if (InputControl::GetKeyDown(KEY_INPUT_RIGHT))
	{
		direction.x = 1.0f;//����
	}
	if (InputControl::GetKeyDown(KEY_INPUT_LEFT))
	{
		direction.x = -1.0f;//�E��
	}
	//���W�ړ�
	location += direction;
}