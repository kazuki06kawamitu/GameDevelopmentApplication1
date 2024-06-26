#pragma once

#include "SceneBase.h"

class SceneManager
{
private:
	SceneBase* current_scene;  //���݃V�[�����̃|�C���^

public:
	SceneManager();
	~SceneManager();

	//����������
	void Initialize();

	//�X�V����
	void Run();

	//�I��������
	void Finalize();

private:
	//�`�揈��
	void Draw() const;
	//�V�[���̐؂�ւ�����
	void ChangeSene(eSceneType type);
	//�V�[����������
	SceneBase* CreateScene(eSceneType type);
};