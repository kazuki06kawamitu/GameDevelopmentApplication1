#pragma once

#include "../Utility/Vector2D.h"

class GameObject
{
protected:
	unsigned int color;//�F���
	Vector2D location;//�ʒu���
	Vector2D box_size;//�T�C�Y���

public:
	GameObject();//�R���g���X�g
	virtual ~GameObject();//�f�X�g���N�^

	virtual void Initialize();//����������
	virtual void Update();//�X�V����
	virtual void Draw()const;//�`�揈��
	virtual void Finalize();//�I��������

public:
	virtual void SetLocation(Vector2D location);//�ʒu���擾
	virtual Vector2D GetLocation() const;//�ʒu��񏈗�
	virtual Vector2D GetBoxSize() const;//�T�C�Y��񏈗�
};