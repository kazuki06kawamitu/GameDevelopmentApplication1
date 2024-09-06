#include "EnemyBase.h"

#include "../../Utility/InputManager.h"
#include "../../Utility/ResourceManager.h"
#include "DxLib.h"

#define D_ENEMY_SPEED (50.0f)
#define D_ENEMY (1)

EnemyBase::EnemyBase() :
	body_animation(),
	eye_animation(),
	velocity(),
	enemy_state(eEnemyState::E_MOVE),
	now_direction_state(EnemyeDirectionState::RIGHT),
	animation_time(),
	animation_count(),
	is_power_down(false),
	is_destroy(false),
	body_image(),
	eye_image()
{

}

EnemyBase::~EnemyBase()
{

}


void EnemyBase::Initialize()
{
	//�A�j���[�V�����摜�̓ǂݍ���
	ResourceManager* rm = ResourceManager::GetInstance();
	body_animation = rm->GetImages("Resource/Images/monster.png", 20, 20, 1, 32, 32);
	eye_animation = rm->GetImages("Resource/Images/eyes.png", 4, 4, 1, 32, 32);

	//�����蔻��̐ݒ�
	collision.is_blocking = true;
	collision.object_type = eObjectType::enemy;
	collision.hit_object_type.push_back(eObjectType::player);
	collision.hit_object_type.push_back(eObjectType::wall);
	collision.hit_object_type.push_back(eObjectType::special);
	collision.radius = (D_OBJECT_SIZE - 1.0f) / 2.0f;

	// ���C���[�̐ݒ�
	z_layer = 5;

	// �����̐ݒ�
	mobility = eMobilityType::Movable;

	//
	velocity = Vector2D(1.0f, 0.0f);
}

void EnemyBase::Update(float delta_second)
{
	// �e�L�̏�Ԃɂ���āA�����ς���
	switch (enemy_state)
	{
	case eEnemyState::E_IDLE:
		// �摜�̐ݒ�
		body_image = body_animation[0];
		eye_image = eye_animation[1];
		break;
	case eEnemyState::E_MOVE:
		// �ړ�����
		Movement(delta_second);
		// �A�j���[�V��������
		AnimationControl(delta_second);
		break;
	default:
		break;
	}
}

void EnemyBase::Draw(const Vector2D& screen_offset) const
{
	// �e�N���X�̕`�揈�����Ăяo��
	__super::Draw(screen_offset);
	Vector2D graph_location = this->location + screen_offset;
	
	DrawRotaGraphF(graph_location.x, graph_location.y, 1.0, 0.0, body_image, TRUE);
	DrawRotaGraphF(graph_location.x, graph_location.y, 1.0, 0.0, eye_image, TRUE);
	
}

void EnemyBase::Finalize()
{
	// ���I�z��̉��
	body_animation.clear();
	eye_animation.clear();
}


void EnemyBase::OnHitCollision(GameObjectBase* hit_object)
{
	// ���������A�I�u�W�F�N�g���ǂ�������
	if (hit_object->GetCollision().object_type == eObjectType::wall)
	{
		// �����蔻������擾���āA�J�v�Z��������ʒu�����߂�
		CapsuleCollision hc = hit_object->GetCollision();
		hc.point[0] += hit_object->GetLocation();
		hc.point[1] += hit_object->GetLocation();

		// �ŋߖT�_�����߂�
		Vector2D near_point = NearPointCheck(hc, this->location);

		// Player����near_point�ւ̕����x�N�g�����擾
		Vector2D dv2 = near_point - this->location;
		Vector2D dv = this->location - near_point;

		// �߂荞�񂾍���
		float diff = (this->GetCollision().radius + hc.radius) - dv.Length();

		// diff�̕������߂�
		location += dv.Normalize() * diff;

		//
		velocity *= -1;
	}

	// ���������I�u�W�F�N�g���v���C���[��������
	if (hit_object->GetCollision().object_type == eObjectType::player)
	{
		enemy_state = eEnemyState::E_DIE;
	}
}


eEnemyState EnemyBase::GetEnemyState() const
{
	return enemy_state;
}



bool EnemyBase::GetPowerDown()
{
	return is_power_down;
}


void EnemyBase::SetPowerDown()
{
	//is_power_down = false;
}


bool EnemyBase::GetDestroyDown() const
{
	return is_destroy;
}


void EnemyBase::Movement(float delta_second)
{
	location += velocity * D_ENEMY_SPEED * delta_second;
}


void EnemyBase::AnimationControl(float delta_second)
{
	// �ړ����̃A�j���[�V����
	animation_time += delta_second;
	if (animation_time >= (1.0f / 16.0f))
	{
		animation_time = 0.0f;
		animation_count++;
		if (animation_count >= 2)
		{
			animation_count = 0;
		}
		// �摜�̐ݒ�
		body_image = body_animation[ animation_num[animation_count]];
		

	}

	if (velocity.x > 0)
	{
		eye_image = eye_animation[1];
	}
	else if (velocity.x < 0)
	{
			eye_image = eye_animation[3];
	}

	if (velocity.y > 0)
	{
		eye_image = eye_animation[4];
	}
	else if (velocity.y < 0)
	{
		eye_image = eye_animation[0];
	}
}
