#include "Blast.h"
#include "DxLib.h"
#include "../Player/Player.h"
#include "../Enemy/Enemy.h"
#include "math.h"
#include <vector>


Blast::Blast() :animation_count(0), direction(0.0f)
{
	animation[0] = NULL;
	animation[1] = NULL;
	animation[2] = NULL;

}

Blast::~Blast()
{
}

//����������
void Blast::Initialize()
{
	//�摜�̓ǂݍ���.�����摜�̐ݒ�
	image = LoadGraph("Resource/Images/EnemyBullet/1.png");
	//�摜�̓ǂݍ���
	animation[0] = LoadGraph("Resource/Images/EnemyBullet/eff1.png");
	animation[1] = LoadGraph("Resource/Images/EnemyBullet/eff2.png");
	animation[2] = LoadGraph("Resource/Images/EnemyBullet/eff3.png");

	//�G���[�`�F�b�N
	if (animation[0] == -1 || animation[1] == -1||animation[2]==-1)
	{
		throw("�G�̒e�̉摜������܂���\n");
	}

	//�����̐ݒ�
	radian = 0.0f;

	//�����蔻��̑傫����ݒ�
	box_size = 30.0f;

	//
	#define D_ENEMYBULLET (1)

	//�����i�s�����̐ݒ�
	direction = Vector2D(0.0f, 0.0f);

}

//�X�V����
void Blast::Update()
{
	//�ړ�����
	Movement();

	//�A�j���[�V��������
	AnimationControl();

	//�ʒu���X�V
	//direction=Vector2D();
}

//�`�揈��
void Blast::Draw() const
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

	//������ɒe�摜��`�悷��
	DrawRotaGraphF(location.x, location.y, 0.5, radian, image, TRUE, FALSE);

	//�e�N���X�̕`�揈�����Ăяo��
	__super::Draw();
}

//�I������
void Blast::Finalize()
{
	//�g�p�����摜�����
	DeleteGraph(image);

}

//�����蔻��ʒm����
void Blast::OnHitCollision(GameObject* hit_object)
{
	//�����������̏���
	if (dynamic_cast<Player*>(hit_object) != nullptr)
	{
		DeleteGraph(image);
		image = animation[0];
		radian = 0.0;
		direction = 0.0f;
		box_size = 0.0f;

	}
}

//�ړ�����
void Blast::Movement()
{
	



	//��ʒ[�ɓ��B������A�摜���폜����
	if (((location.y + direction.y) < box_size.y) ||
		(600.0f - box_size.y) < (location.y + direction.y))
	{
		delete_flag = TRUE;
	}

	//�i�s�����Ɍ������āA�ʒu���W��ύX����
	location += direction;
}

//
Vector2D Blast::GetLocation()
{
	return location;
 }

//�A�j���[�V��������
void Blast::AnimationControl()
{
	//�A�j���[�V�����J�E���g�����Z����
	animation_count++;

	//30�t���[���ڂɓ��B������
	if (animation_count >= 60)
	{


		//�摜�̐ؑ�
		if (image == animation[0])
		{
			image = animation[1];
		}
		else if (image == animation[1])
		{
			image = animation[2];
			delete_flag = TRUE;
		}
		else
		{


		}
		animation_count = 0;
	}
}

void Blast::SetDirection(Vector2D p_loc)
{
	//�i�s�����Ɍ������āA�ʒu���W��ύX����
	Vector2D vec;
	//�ړI�̈ʒu�܂ł̋������Ƃ�
	//x�̋���
	vec.x = ((p_loc.x - location.x) / 180);
	//y�̋���
	vec.y = ((p_loc.y - location.y) / 180);

	//�����̊m��
	direction.x = vec.x;
	direction.y = vec.y;
	
}