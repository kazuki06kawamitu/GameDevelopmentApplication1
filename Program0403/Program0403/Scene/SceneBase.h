#pragma once

enum eSceneType
{
	eTitle,
	eInGame,
	eResult,
	eEnd,
	eHelp,
};

class SceneBase
{
protected:
	//�S�V�[���ŏ��L���郁���o�ϐ���錾

public:
	SceneBase() {}
	virtual ~SceneBase() {}

	//����������
	virtual void Initialize() {}

	//�X�V����
	//����:�P�t���[��������̎���
	//�߂�l:���̃V�[���^�C�v
	virtual eSceneType Update()
	{
		return GetNowSceneType();
	}

	//�`�揈��
	virtual void Draw() const{}

	//�I��������
	virtual void Finalize() {}

	//���݂̃V�[���^�C�v(�I�[�o�[���C�h�K�{)
	virtual eSceneType GetNowSceneType() const = 0;
};