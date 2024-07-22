#pragma once
#include "PlayerStateBase.h"
#include"../../Utility/Vector2D.h"

///<summary>
///�W�����v���
/// </summry>
class Jumping : public PlayerStateBase
{
private:
	//�ڃt���[���̍��W���
	Vector2D old_location;

public:
///<summary>
///�R���X�g���N�^
/// </summry>
/// <param name="p">�v���C���[���</param>
	JumpingState(class Player* p);

	//�f�X�g���N�^
	virtual ~JumpingState();

public:
	//�����������֐�
	virtual void Initialize() override;

	//�I�������֐�
	virtual void Finalize() const override;

	//�X�V����
	virtual void Update()override;

	//�`�揈��
	virtual void Draw() const override;

	//��Ԃ̎擾
	virtual ePlayerState GetState() const override;
};