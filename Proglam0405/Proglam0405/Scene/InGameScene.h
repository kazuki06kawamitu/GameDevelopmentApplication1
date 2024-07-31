#pragma once
#include "SceneBase.h"

class InGameScene :public SceneBase
{
private:
	class Player* player;

public:
	InGameScene();
	virtual ~InGameScene();
	
	//����������
	virtual void Initialize() override;

	//�X�V����
	//����:1�t���[��������̎���
	//�߂�l:���̃V�[���^�C�v
	virtual eSceneType Update(float delta_second) override;

	//�`�揈��
	virtual void Draw() const override;

	//�I��������
	virtual void Finalize() override;

	//���݂̃V�[���^�C�v(�I�[�o�[���C�h�K�{)
	virtual eSceneType GetNowSceneType() const override;

};