#include "JumpingState.h"

#include "DxLib.h"
#include "../../Utility/InputControl.h"
#include "../Player.h"

///<summary>
///�R���X�g���N�^
/// </summry>
/// <param name="p">�v���C���[���</param>
JumpingState::JumpingState(class Player* p)
	: PlayerStateBase(p)
	, old_location(Vector2D(0.0f))
{

}

///<summary>
///�f�X�g���N�^
/// </summry>
JumpingState::~JumpingState()
{

}

///<summary>
///����������
/// </summry>
void JumpingState::Initialize()
{
	this->player->velocity.y -= 15.0f;  //�W�����v��
	old_location = 0.0f;
}

///<summary>
///�I������
/// </summry>
void JumpingState::Finalize()
{

}

///<summary>
///�X�V����
/// </summry>
void JumpingState::Update()
{
	//�n�ʂɐG�ꂽ��
	if (old_location.y == player->GetLocation().y)
	{
		//���E���͂�����Ȃ�
		//InputControl* input = InputControl::GetInstance();
		//if (input->GetKey(KEY_INPUT_A) || input->GetKey(KEY_INPUT_D))
		//{
		//	//�ړ���ԂɑJ��
		//	player->SetNextState(ePlayerState::RUN);
		//}
		//else
		//{
		//	//��~��ԂɑJ��
		//	player->SetNextState(ePlayerState::IDLE);
		//}
	}
	//�O����W�̍X�V
	old_location = player->GetLocation();
}

///<summary>
///�`�揈��
/// </summry>
void JumpingState::Draw() const
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
ePlayerState JumpingState::GetState() const
{
	return ePlayerState::JUMP;
}