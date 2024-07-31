#pragma once
#include "Enum/PlayerState.h"

///<summary>
///�v���C���[��ԊǗ��p�̃y�[�X�N���X
///</summary>
class PlayerStateBase
{
protected:
	//�v���C���[���
	class Player* player;

public:
///<summary>
///�R���X�g���N�^
///</summary>
///<param name="p">�v���C���[���</param>
	PlayerStateBase(class Player* p) : player(p)
	{
	}

	//�f�X�g���N�^
	virtual ~PlayerStateBase() = default;

public:
	//�����������֐�
	virtual void Initialize() = 0;

	//�I�������֐�
	virtual void Finalize() = 0;

	//�X�V����
	virtual void Update() = 0;

	//�`�揈��
	virtual void Draw() const = 0;
	//��Ԃ̎擾
	virtual ePlayerState GetState() const = 0;
};