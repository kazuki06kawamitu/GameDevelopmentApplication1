#include "GameObject.h"
#include "DxLib.h"
//�R���g���X�g
GameObject::GameObject() :color(0x0), location(0.0f), box_size(0.0f)
{

}
//�f�X�g���N�^
GameObject::~GameObject()
{

}
//����������
void GameObject::Initialize()
{
	color = GetColor(255, 0, 0);

	box_size = Vector2D(32.0f);

	location = box_size;
	

	
}
//�X�V����
void GameObject::Update()
{
	//�E�����֐i�ݑ����鏈��
	location.x += 1.0f;
	//�E�[�ɂ��ƁA���[�ֈړ�����
	if (location.x >= 640.0f)
	{
		location.x = 0.0f;
	}
}
//�`�揈��
void GameObject::Draw() const
{
	Vector2D upper_left = location - (box_size / 2.0f);
	Vector2D lower_right = location + (box_size / 2.0f);

	DrawBoxAA(upper_left.x, upper_left.y, lower_right.x,lower_right.y, color, TRUE);
}
//�I��������
void GameObject::Finalize()
{

}
//�ʒu���
void GameObject::SetLocation(Vector2D location)
{
	this->location = location;
}
//�ʒu��񏈗�
Vector2D GameObject::GetLocation() const
{
	return this->location;
}
//�T�C�Y��񏈗�
Vector2D GameObject::GetBoxSize() const
{
	return this->box_size;
}