#include "Bomb.h"
#include "DxLib.h"

Bomb::Bomb() : direction(0.0f)
{

}

Bomb::~Bomb()
{
}

//����������
void Bomb::Initialize()
{
	//�摜�̓ǂݍ���
	image = LoadGraph("Resource/Images/Bomb/Bomb.png");

	//�G���[�`�F�b�N
	if (image== -1)
	{
		throw("���e�̉摜������܂���\n");
	}

	//�����̐ݒ�
	radian = DX_PI_F/2;

	//�����蔻��̑傫����ݒ�
	box_size = 64.0f;

	//�����i�s�����̐ݒ�
	direction = Vector2D(0.0f, 1.0f);
}

//�X�V����
void Bomb::Update()
{
	//�ړ�����
	Movement();

	//�A�j���[�V��������
	//AnimationControl();
}

//�`�揈��
void Bomb::Draw() const
{
	//�摜���]�t���O
	int flip_flag = FALSE;

	//�i�s�����ɂ���āA�����Ԃ����肷��
	if (direction.x > 0.0f)
	{
		flip_flag = FALSE;
	}
	else
	{
		flip_flag = TRUE;
	}

	//������ɔ��e�摜��`�悷��
	DrawRotaGraphF(location.x, location.y, 0.5, radian, image, TRUE, FALSE);

	//�e�N���X�̕`�揈�����Ăяo��
	__super::Draw();
}

//�I������
void Bomb::Finalize()
{
	//�g�p�����摜�����
	DeleteGraph(image);

}

//�����蔻��ʒm����
void Bomb::OnHitCollision(GameObject* hit_object)
{
	//�����������̏���
	//direction = 0.0f;
}

//�ړ�����
void Bomb::Movement()
{
	//��ʒ[�ɓ��B������A�i�s�����𔽓]����

	if (((location.x + direction.x) < box_size.x) ||
		(640.0f - box_size.x) < (location.x + direction.x))
	{
		direction.x == 0.0f;
	}

	if (((location.y + direction.y) < box_size.y) ||
		(480.0f - box_size.y) < (location.y + direction.y))
	{
		direction.y == 0.0f;
	}

	//�i�s�����Ɍ������āA�ʒu���W��ύX����
	location += direction;
}

//�A�j���[�V��������
//void Bomb::AnimationControl()
//{
//	//�A�j���[�V�����J�E���g�����Z����
//	animation_count++;
//
//	//30�t���[���ڂɓ��B������
//	if (animation_count >= 30)
//	{
//		//�J�E���g���Z�b�g
//		animation_count = 0;
//
//		//�摜�̐ؑ�
//		if (image == animation[0])
//		{
//			image = animation[1];
//		}
//		else
//		{
//			image = animation[0];
//		}
//	}
//}