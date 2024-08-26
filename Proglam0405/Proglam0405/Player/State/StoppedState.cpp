#include "StoppedState.h"

#include "DxLib.h"
#include "../../Utility/InputControl.h"
#include "../Player.h"

///<summary>
///�R���X�g���N�^
///</summary>
///<param name="p">�v���C���[���</param>
/// 

StoppedState::StoppedState(Player* p)
	: PlayerStateBase(p)
	, input(nullptr)
{

}

///<summary>
///�f�X�g���N�^
///</summary>
StoppedState::~StoppedState()
{

}

///<summary>
///����������
///</summary>
void StoppedState::Initialize()
{
	// Box�̃T�C�Y��ݒ�
	player->box_size = Vector2D(32.0f);

	//���x��0�ɂ���
	player->velocity = 0.0f;

	//���͏����擾
	input = InputControl::GetInstance();
}

///<summary>
///�I������
///</summary>
void StoppedState::Finalize()
{
}

///<summary>
///�X�V����
///</summary>
void StoppedState::Update()
{
	//�W�����v��ԑJ��
	if (input->GetKeyDown(KEY_INPUT_SPACE))
	{
		player->SetNextState(ePlayerState::JUMP);
	}
}

///<summary>
///�`�揈��
///</summary>
void StoppedState::Draw()const
{
	//���W���𐮐��l�ɕϊ�
	int x = 0, y = 0;
	player->GetLocation().ToInt(&x, &y);

	//�`��
	DrawBox(x, y, x + (int)(player->box_size.x), y + (int)(player->box_size.y),
		GetColor(255, 0, 0), TRUE);
}

///<summary>
///���݂̃X�e�[�g�����擾����
///</summary>
/// <returns>���݂̃X�e�[�g���</returns>
ePlayerState StoppedState::GetState()const
{
	return ePlayerState::IDLE;
}