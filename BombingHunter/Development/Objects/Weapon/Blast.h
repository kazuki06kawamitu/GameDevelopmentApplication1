#pragma once

#include "../GameObject.h"

class Blast :public GameObject
{
private:
	int animation[3];  //�A�j���V�����摜
	int animation_count;  //�A�j���V��������
	Vector2D direction;  //�i�s����

public:
	Blast();
	~Blast();

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

	//
	virtual Vector2D GetLocation();

	//
	void SetDirection(Vector2D p_loc);

private:
	//�ړ�����
	void Movement();
	//�A�j���[�V��������
	void AnimationControl();
};