#include "EnemyBase.h"
#include "DxLib.h"
#include "../../Utility/InputManager.h"
#include "../../Utility/ResourceManager.h"
#include "../Food/Food.h"

#define D_ENEMY_SPEED (80.0f)
#define D_ENEMY (1)

EnemyBase::EnemyBase() :
	move_animation(),
	dying_animation(),
	velocity(),
	enemy_state(eEnemyState::E_MOVE),
	now_direction_state(eDirectionState::RIGHT),
	animation_time(),
	animation_count(),
	food_count(),
	old_panel(ePanelID::NONE),
	is_power_down(false),
	is_destroy(false)
{

}

EnemyBase::~EnemyBase()
{

}


void EnemyBase::Initialize()
{
	//�A�j���[�V�����摜�̓ǂݍ���
	ResourceManager* rm = ResourceManager::GetInstance();
	move_animation = rm->GetImages("Resource/Images/monster.png", 12, 12, 1, 32, 32);
	dying_animation = rm->GetImages("Resource/Images/eyes.png", 11, 11, 1, 32, 32);

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
}

void EnemyBase::Update(float delta_second)
{
	// �e�L�̏�Ԃɂ���āA�����ς���
	switch (enemy_state)
	{
	case eEnemyState::E_IDLE:
		// �摜�̐ݒ�
		image = move_animation[9];
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
}

void EnemyBase::Finalize()
{
	// ���I�z��̉��
	move_animation.clear();
	dying_animation.clear();
}

/// <summary>
/// �����蔻��ʒm����
/// </summary>
/// <param name="hit_object">���������Q�[���I�u�W�F�N�g�̃|�C���^</param>
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
	}

	// ���������I�u�W�F�N�g���v���C���[��������
	if (hit_object->GetCollision().object_type == eObjectType::player)
	{
		enemy_state = eEnemyState::E_DIE;
	}
}

/// <summary>
	/// �G�̏�Ԃ��擾����
	/// </summary>
	/// <returns>�G�̏��</returns>
eEnemyState EnemyBase::GetEnemyState() const
{
	return enemy_state;
}


/// <summary>
/// �p���[�_�E��������
/// </summary>
bool EnemyBase::GetPowerDown()
{
	return is_power_down;
}

/// <summary>
	/// �p���[�_�E��������
	/// </summary>
void EnemyBase::SetPowerDown()
{
	//is_power_down = false;
}

/// <summary>
	/// �p���[�_�E��������
	/// </summary>
bool EnemyBase::GetDestroyDown() const
{
	return is_destroy;
}

/// <summary>
	/// �ړ�����
	/// </summary>
	/// <param name="delta_second">1�t���[��������̎���</param>
void EnemyBase::Movement(float delta_second)
{
	location += velocity * D_ENEMY_SPEED * delta_second;
}

/// <summary>
	/// �A�j���[�V��������
	/// </summary>
	/// <param name="delta_second">1�t���[��������̎���</param>
void EnemyBase::AnimationControl(float delta_second)
{
	// �ړ����̃A�j���[�V����
	animation_time += delta_second;
	if (animation_time >= (1.0f / 16.0f))
	{
		animation_time = 0.0f;
		animation_count++;
		if (animation_count >= 4)
		{
			animation_count = 0;
		}
		// �摜�̐ݒ�
		int dir_num = (int)now_direction_state;
		if (0 <= dir_num && dir_num < 4)
		{
			image = move_animation[(dir_num * 3) + animation_num[animation_count]];
		}

	}
}
