#pragma once

#include "../Utility/Vector2D.h"
//�Q�����x�N�g���N���X
class Player
{
private:
	Vector2D location;  //�ʒu���W
	Vector2D direction; //�������W
	float radius;       //���a�i�����_���܂ށj

public:
	Player();                 //�R���X�g���N�^
	Player(float x, float y); //�����̒l�ŏ�����
	Player(Vector2D location);//
	~Player();                //�f�X�g���N�^

	void Update();     //�X�V����
	void Draw() const; //�`�揈��

	void SetLocation(float x, float y); //�Z�b�^�[
	void SetLocation(Vector2D location); //
	Vector2D GetLocation() const; //�Q�b�^�[
	float GetRadius();    //

private:
	void Movement();//�ړ������i�L�[�̓��͂�
};