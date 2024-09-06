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
	//アニメーション画像の読み込み
	ResourceManager* rm = ResourceManager::GetInstance();
	body_animation = rm->GetImages("Resource/Images/monster.png", 20, 20, 1, 32, 32);
	eye_animation = rm->GetImages("Resource/Images/eyes.png", 4, 4, 1, 32, 32);

	//当たり判定の設定
	collision.is_blocking = true;
	collision.object_type = eObjectType::enemy;
	collision.hit_object_type.push_back(eObjectType::player);
	collision.hit_object_type.push_back(eObjectType::wall);
	collision.hit_object_type.push_back(eObjectType::special);
	collision.radius = (D_OBJECT_SIZE - 1.0f) / 2.0f;

	// レイヤーの設定
	z_layer = 5;

	// 可動性の設定
	mobility = eMobilityType::Movable;

	//
	velocity = Vector2D(1.0f, 0.0f);
}

void EnemyBase::Update(float delta_second)
{
	// テキの状態によって、動作を変える
	switch (enemy_state)
	{
	case eEnemyState::E_IDLE:
		// 画像の設定
		body_image = body_animation[0];
		eye_image = eye_animation[1];
		break;
	case eEnemyState::E_MOVE:
		// 移動処理
		Movement(delta_second);
		// アニメーション制御
		AnimationControl(delta_second);
		break;
	default:
		break;
	}
}

void EnemyBase::Draw(const Vector2D& screen_offset) const
{
	// 親クラスの描画処理を呼び出す
	__super::Draw(screen_offset);
	Vector2D graph_location = this->location + screen_offset;
	
	DrawRotaGraphF(graph_location.x, graph_location.y, 1.0, 0.0, body_image, TRUE);
	DrawRotaGraphF(graph_location.x, graph_location.y, 1.0, 0.0, eye_image, TRUE);
	
}

void EnemyBase::Finalize()
{
	// 動的配列の解放
	body_animation.clear();
	eye_animation.clear();
}


void EnemyBase::OnHitCollision(GameObjectBase* hit_object)
{
	// 当たった、オブジェクトが壁だったら
	if (hit_object->GetCollision().object_type == eObjectType::wall)
	{
		// 当たり判定情報を取得して、カプセルがある位置を求める
		CapsuleCollision hc = hit_object->GetCollision();
		hc.point[0] += hit_object->GetLocation();
		hc.point[1] += hit_object->GetLocation();

		// 最近傍点を求める
		Vector2D near_point = NearPointCheck(hc, this->location);

		// Playerからnear_pointへの方向ベクトルを取得
		Vector2D dv2 = near_point - this->location;
		Vector2D dv = this->location - near_point;

		// めり込んだ差分
		float diff = (this->GetCollision().radius + hc.radius) - dv.Length();

		// diffの分だけ戻る
		location += dv.Normalize() * diff;

		//
		velocity *= -1;
	}

	// 当たったオブジェクトがプレイヤーだったら
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
	// 移動中のアニメーション
	animation_time += delta_second;
	if (animation_time >= (1.0f / 16.0f))
	{
		animation_time = 0.0f;
		animation_count++;
		if (animation_count >= 2)
		{
			animation_count = 0;
		}
		// 画像の設定
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
