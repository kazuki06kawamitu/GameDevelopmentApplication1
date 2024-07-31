#include "Player.h"

#include <cmath>

#include "DxLib.h"
#include "State/Factory/PlayerdStateFactory.h"

#define D_GRAVITY (9.807f)  //�d�͉����x(m/ss)

///<summary>
///����������
/// </summry>
/// <param name="init_Location">�������W<param>
void Player::Initialize(Vector2D init_location)
{
	state = PlayerStateFactory::Get((*this), ePlayerState::IDLE);
	next_state = ePlayerState::NONE;
	g_velocity = 0.0f;
	location = init_location;
	velocity = Vector2D(0.0f);
}

///<summary>
///�I������
/// </summry>
void Player::Finalize()
{
	PlayerStateFactory::Finalize();
}

///<summary>
///�X�V����
/// </summry>
void Player::Update()
{
	//state�̕ύX����
	if (next_state != ePlayerState::NONE)
	{
		state = PlayerStateFactory::Get((*this), next_state);
		next_state = ePlayerState::NONE;
	}

	//�d�͑��x�̌v�Z
	g_velocity += D_GRAVITY / 444.0f;
	velocity.y += g_velocity;

	//��ԕʂ̍X�V�������s��
	state->Update();
	//�ړ��̎��s
	location += velocity;

	//400.0f���_��n�ʂƉ���
	if (400.0f < location.y)
	{
		location.y = 400.0f;
		g_velocity = 0.0f;
		velocity.y = 0.0f;
	}
}

///<summary>
///�`�揈��
/// </summry>
void Player::Draw() const
{
	//��ԕʂ̕`�揈�����s��
	state->Draw();
}

///<summary>
///����State��ݒ�
/// </summry>
/// <Player name="next_state">����State</param>
void Player::SetNextState(ePlayerState next_state)
{
	this->next_state = next_state;
}

///<summary>
///���W�̎擾
/// </summry>
Vector2D& Player::GetLocation()
{
	return this->location;
}