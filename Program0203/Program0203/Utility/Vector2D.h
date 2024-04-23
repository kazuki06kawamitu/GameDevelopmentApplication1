#pragma once
//�Q�����x�N�g���N���X
class Vector2D
{
public:
	float x;//x����
	float y;//y����

public:
	Vector2D();
	Vector2D(float scalar);
	Vector2D(float mx, float my);
	~Vector2D();

public:
	//����� ���Z�q�I�[�o�[���[�h
	Vector2D& operator=(const Vector2D& loction);
	//���Z�� ���Z�q�I�[�o�[���[�h
	const Vector2D operator+(const Vector2D& location) const;
	//���Z��� ���Z�q�I�[�o�[���[�h
	Vector2D& operator+=(const Vector2D& location);
	//���Z ���Z�q�I�[�o�[���[�h
	const Vector2D operator-(const Vector2D& location) const;
	//���Z��� ���Z�q�I�[�o�[���[�h
	Vector2D& operator-=(const Vector2D& location);
	//��Z ���Z�q�I�[�o�[���[�h
	const Vector2D operator * (const float& scalar) const;
	const Vector2D operator * (const Vector2D& location) const;
	//��Z��� ���Z�q�I�[�o�[���[�h
	Vector2D& operator*=(const float& scalar);
	Vector2D& operator*=(const Vector2D& location);
	//���Z ���Z�q�I�[�o�[���[�h
	const Vector2D operator/(const float& scalar)const;
	const Vector2D operator/(const Vector2D& location)const;
	//���Z��� ���Z�q�I�[�o�[���[�h
	Vector2D& operator/=(const float& scalar);
	Vector2D& operator/=(const Vector2D& location);
	//�����^�f�[�^�ɕϊ��ix��y�����𐮐��^�ɕϊ����āA�Ή���������ɑ������j
	void ToInt(int* x, int* y)const;
};