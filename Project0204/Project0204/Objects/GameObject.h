#pragma once

#include "../Utility/Vector2D.h"

class GameObject
{
protected:
	int image;//�摜
	Vector2D location;//�ʒu
	Vector2D box_size;//�T�C�Y

public:
	GameObject();//�R���g���N�^
	virtual ~GameObject();//�f�X�g���N�^

	virtual void Initialize();//����������
	virtual void Update();//�X�V����
	virtual void Draw() const;//�`�揈��
	virtual void Finalize();//�I��������

public:
	void SetLocation(Vector2D location);//�ʒu���擾
	Vector2D GetLocation() const;//�ʒu��񏈗�
	Vector2D GetBoxSize() const;//�T�C�Y��񏈗�
};