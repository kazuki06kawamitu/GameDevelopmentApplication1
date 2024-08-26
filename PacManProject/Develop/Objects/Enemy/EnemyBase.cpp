#include "EnemyBase.h"
#include "../GameObject.h"
#include "../../Scenes/SceneBase.h"
#include "DxLib.h"

#define D_ENEMY (1)

EnemyBase::EnemyBase() :
move_animation(),
dying_animation(),
velocity(),
enemy_state(eEnemyState ::SEARCH),
now_direction_state(eDirectionState::RIGHT),
next_direction_state(eDirectionState::UP),
animation_time(),
animation_count(),
food_count(),
old_panel(ePanelID::NONE)
{
	//
}

EnemyBase::~EnemyBase()
{
}


void EnemyBase::Initialize()
{

}

void EnemyBase::Update(float delta_second)
{

}

void EnemyBase::Draw(const Vector2D& screen_offset) const
{

}

void EnemyBase::Finalize()
{

}

void EnemyBase::OnHitCollision(GameObjectBase* hit_object)
{

}

eEnemyState EnemyBase::GetEnemyState() const
{

}

void EnemyBase::SetPowerDown()
{

}

void EnemyBase::Movement(float delta_second)
{

}

void EnemyBase::AnimationControl(float delta_second)
{

}