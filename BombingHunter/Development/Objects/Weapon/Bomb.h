#pragma once

#include "../GameObject.h"

class Bomb :public GameObject
{
private:
	Vector2D direction;  //�i�s����

public:
	Bomb();
	~Bomb();

	//����������
	virtual void Initialize() override;

	//�X�V����
	virtual void Update() override;

	//�`�揈��
	virtual void Draw() const override;

	//�I������
	virtual void Finalize() override;

	//�����蔻��ʒm����
	virtual void OnHitCollision(GameObject* hit_object) override;

private:
	//�ړ�����
	void Movement();
	//�A�j���[�V��������
	//void AnimationControl();
};