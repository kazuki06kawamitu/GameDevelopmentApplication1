#pragma once

#include "GameObject.h"

class Player :public GameObject
{
private:
	
public:
	Player();//�R���g���X�g
	virtual ~Player();//�f�X�g���N�^

	void Initialize()override;//����������
	void Update()override;//�X�V����
	void Draw() const override;//�`�揈��
	void Finalize()override;//�I��������

private:
	void Movement();//�ړ�����
};