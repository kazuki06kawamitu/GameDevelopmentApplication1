#pragma once

#include "SceneBase.h"

class TitleScene :public SceneBase
{
private:

public:
	TitleScene();
	virtual~TitleScene();

	//����������
	virtual void Initialize() override;
	//�X�V����
	//����:�P�t���[��������̎���
	//�߂�l:���̃V�[���^�C�v
	virtual eSceneType Update() override;

	//�`�揈��
	virtual void Draw()const override;

	//�I������
	virtual void Finalize() override;

	//���݃V�[���^�C�v(�I�[�o�[���C�h�K�{)
	virtual eSceneType GetNowSceneType() const override;
};