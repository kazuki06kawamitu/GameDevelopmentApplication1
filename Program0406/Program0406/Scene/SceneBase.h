#pragma once

#include "../Utility/InputEventManager.h"

enum eSceneType
{
	eTitle,
	eInGame,
	eResult,
	eEnd,
};

class SceneBase
{
protected:
	//�S�V�[���ŏ��L���郁���o�ϐ���錾
	InputEventManager* input_event;
public:
	SceneBase() : input_event(nullptr)
	{

	}
	virtual~SceneBase()
	{

	}

	//����������
	virtual void Initialize()
	{
		//���̓C�x���g�̃C���X�^���X���擾
		input_event = InputEventManager::GetInstance();
	}

	//�X�V����
	//����:�P�t���[��������̎���
	//�߂�l:���̃V�[���^�C�v
	virtual eSceneType Update(float delta_second)
	{
		//�o�^����Ă�����̓C�x���g�̌ďo
		input_event->InputActionEvent();

		return GetNowSceneType();
	}

	//�`�揈��
	virtual void Draw() const
	{
	}

	//�I��������
	virtual void Finalize()
	{
		input_event->AllUnbind();
	}
	//���݂̃V�[���^�C�v(�I�[�o�[���C�h�K�{)
	virtual eSceneType GetNowSceneType() const = 0;
};