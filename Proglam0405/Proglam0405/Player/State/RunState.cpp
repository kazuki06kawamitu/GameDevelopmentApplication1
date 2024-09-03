#include "RunState.h"

#include "DxLib.h"
#include "../../Utility/InputControl.h"
#include "../Player.h"

///<summary>
///�R���X�g���N�^
/// </summry>
/// <param name="p">�v���C���[���</param>
RunState::RunState(class Player* p)
	: PlayerStateBase(p)
	,input(nullptr)
	, speed(0.0f)
{

}

///<summary>
///�f�X�g���N�^
/// </summry>
RunState::~RunState()
{

}

///<summary>
///����������
/// </summry>
void RunState::Initialize()
{
	//Boxsize�̐ݒ�
	player->box_size = Vector2D(32.0f);

	//���x��0�ɏ�����
	player->velocity = 0.0f;

	//���͏����K��
	input = InputControl::GetInstance();

	//�����x���Z���l
	speed = 70.0f;
}

///<summary>
///�I������
/// </summry>
void RunState::Finalize()
{

}

///<summary>
///�X�V����
/// </summry>
void RunState::Update()
{
	//�����x�v�Z����
	if (input->GetKey(KEY_INPUT_A))
	{
		player->velocity.x -= speed;
	}
	if (input->GetKey(KEY_INPUT_D))
	{
		player->velocity.x += speed;
	}

	//���W�擾
	Vector2D location_end = (player->GetLocation() + player->velocity.x);

	//��ʒ[�ɐG�ꂽ��
	if (location_end.x <(0.0f))
	{
		//��~��ԂɑJ��
		player->velocity.x=0.0f;
	}
	else if (location_end.x > (640.0f - player->box_size.x))
	{
		//��~��ԂɑJ��
		player->velocity.x = 0.0f;
	}
	//�W�����v��ԂɑJ��
	if (input->GetKeyDown(KEY_INPUT_SPACE))
	{
		//��~��ԂɑJ��
		player->SetNextState(ePlayerState::JUMP);
	}

	//��~���
	if (!(input->GetKey(KEY_INPUT_A)) || !(input->GetKey(KEY_INPUT_D)))
	{
		player->SetNextState(ePlayerState::IDLE);
	}
}

///<summary>
///�`�揈��
/// </summry>
void RunState::Draw() const
{
	//���W���𐮐��l�ɕϊ�
	int x = 0, y = 0;
	player->GetLocation().ToInt(&x, &y);

	//�`��
	DrawBox(x, y, x + (int)(player->box_size.x), y + (int)(player->box_size.y),
		GetColor(0, 0, 255), FALSE);
}

///<summary>
///���݂̃X�e�[�g�����擾����
/// </summry>
/// <return>���݂̃X�e�[�g���</return>
ePlayerState RunState::GetState() const
{
	return ePlayerState::RUN;
}