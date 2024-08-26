#pragma once
#include "PlayerStateBase.h"

//<summary>
///��~���
///</summary>
class StoppedState :public PlayerStateBase
{
private:
	//���͏��
	class InputControl* input;

public:
///<summary>
///�R���X�g���N�^
///</summary>
/// <param name="p">�v���C���[���</param>
	StoppedState(class Player* p);

	//�f�X�g���N�^
	virtual ~StoppedState();

public:
	//�����������֐�
	virtual void Initialize() override;

	//�I�������֐�
	virtual void Finalize() override;

	//�X�V����
	virtual void Update() override;

	//�`�揈��
	virtual void Draw() const override;

	//��Ԃ̎擾
	virtual ePlayerState GetState() const override;
};