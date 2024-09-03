#pragma once
#include "PlayerStateBase.h"
#include"../../Utility/Vector2D.h"

///<summary>
///�W�����v���
/// </summry>
class RunState : public PlayerStateBase
{
private:
	//���͏��
	class InputControl* input;

	//�����x���Z�l
	float speed;

public:
	///<summary>
	///�R���X�g���N�^
	/// </summry>
	/// <param name="p">�v���C���[���</param>
	RunState(class Player* p);

	//�f�X�g���N�^
	virtual ~RunState();

public:
	//�����������֐�
	virtual void Initialize() override;

	//�I�������֐�
	virtual void Finalize() override;

	//�X�V����
	virtual void Update()override;

	//�`�揈��
	virtual void Draw() const override;

	//��Ԃ̎擾
	virtual ePlayerState GetState() const override;
};