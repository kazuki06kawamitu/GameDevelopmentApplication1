#include "Blast.h"
#include "DxLib.h"

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
	//�摜�̓ǂݍ���
	animation[0] = LoadGraph("Resource/Images/Blast/1.png");
	animation[1] = LoadGraph("Resource/Images/Blast/2.png");
	animation[2] = LoadGraph("Resource/Images/Blast/3.png");

	//�G���[�`�F�b�N
	if (animation[0] == -1 || animation[1] == -1||animation[2]==-1)
	{
		throw("�����̉摜������܂���\n");
	}

	//�����̐ݒ�
	radian = 0.0f;

	//�����蔻��̑傫����ݒ�
	box_size = 64.0f;

	//�����摜�̐ݒ�
	image = animation[0];

	//�����i�s�����̐ݒ�
	direction = Vector2D(1.0f, 1.0f);
}

//�X�V����
void Blast::Update()
{
	//�ړ�����
	Movement();

	//�A�j���[�V��������
	AnimationControl();
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

	//������Ƀn�R�e�L�摜��`�悷��
	DrawRotaGraphF(location.x, location.y, 0.5, radian, image, TRUE, FALSE);

	//�e�N���X�̕`�揈�����Ăяo��
	__super::Draw();
}

//�I������
void Blast::Finalize()
{
	//�g�p�����摜�����
	DeleteGraph(animation[0]);

}

//�����蔻��ʒm����
void Blast::OnHitCollision(GameObject* hit_object)
{
	//�����������̏���
	direction = 0.0f;
}

//�ړ�����
void Blast::Movement()
{
	//��ʒ[�ɓ��B������A�i�s�����𔽓]����
	if (((location.x + direction.x) < box_size.x) ||
		(640.0f - box_size.x) < (location.x + direction.x))
	{
		direction.x *= 0.0f;
	}

	if (((location.y + direction.y) < box_size.y) ||
		(480.0f - box_size.y) < (location.y + direction.y))
	{
		direction.y *= 0.0f;
	}

	//�i�s�����Ɍ������āA�ʒu���W��ύX����
	location += direction;
}

//�A�j���[�V��������
void Blast::AnimationControl()
{
	//�A�j���[�V�����J�E���g�����Z����
	animation_count++;

	//30�t���[���ڂɓ��B������
	if (animation_count >= 30)
	{
		//�J�E���g���Z�b�g
		animation_count = 0;

		//�摜�̐ؑ�
		if (image == animation[0])
		{
			image = animation[1];
		}
		else if (image == animation[1])
		{
			image = animation[2];
		}
		else
		{
			image = animation[0];
		}
	}
}