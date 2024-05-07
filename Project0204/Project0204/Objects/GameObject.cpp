#include "GameObject.h"
#include "../Utility/ResourceManager.h"
#include "DxLib.h"
//�R���g���X�g
GameObject::GameObject() : image(NULL), location(0.0f), box_size(0.0f)
{

}
//�f�X�g���N�g
GameObject::~GameObject()
{
}

//����������
void GameObject::Initialize()
{
	image = NULL;

	box_size = Vector2D(32.0f);

	location = box_size;
}

//�X�V����
void GameObject::Update()
{
	location.x += 1.0f;
	if (location.x >= 640.0f)
	{
		location.x = 0.0f;
	}
}

//�`�揈��
void GameObject::Draw() const
{
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE);

	Vector2D upper_left = location - (box_size / 2.0f);
	Vector2D lower_right = location + (box_size / 2.0f);

	DrawBoxAA(upper_left.x, upper_left.y, lower_right.x, lower_right.y, GetColor(255, 0, 0), TRUE);
}

//�I��������
void GameObject::Finalize()
{

}

//�ʒu���擾
void GameObject::SetLocation(Vector2D location)
{
	this->location = location;
}

//�ʒu���擾����
Vector2D GameObject::GetLocation() const
{
	return this->location;
}

//���T�C�Y����
Vector2D GameObject::GetBoxSize() const
{
	return this->box_size;
}