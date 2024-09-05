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
	//アニメーション画像の読み込み
	ResourceManager* rm = ResourceManager::GetInstance();
	move_animation = rm->GetImages("Resource/Images/monster.png", 12, 12, 1, 32, 32);
	dying_animation = rm->GetImages("Resource/Images/eyes.png", 11, 11, 1, 32, 32);

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
}

void EnemyBase::Update(float delta_second)
{
	// テキの状態によって、動作を変える
	switch (enemy_state)
	{
	case eEnemyState::E_IDLE:
		// 画像の設定
		image = move_animation[9];
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
}

void EnemyBase::Finalize()
{
	// 動的配列の解放
	move_animation.clear();
	dying_animation.clear();
}

/// <summary>
/// 当たり判定通知処理
/// </summary>
/// <param name="hit_object">当たったゲームオブジェクトのポインタ</param>
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
	}

	// 当たったオブジェクトがプレイヤーだったら
	if (hit_object->GetCollision().object_type == eObjectType::player)
	{
		enemy_state = eEnemyState::E_DIE;
	}
}

/// <summary>
	/// 敵の状態を取得する
	/// </summary>
	/// <returns>敵の状態</returns>
eEnemyState EnemyBase::GetEnemyState() const
{
	return enemy_state;
}


/// <summary>
/// パワーダウンさせる
/// </summary>
bool EnemyBase::GetPowerDown()
{
	return is_power_down;
}

/// <summary>
	/// パワーダウンさせる
	/// </summary>
void EnemyBase::SetPowerDown()
{
	//is_power_down = false;
}

/// <summary>
	/// パワーダウンさせる
	/// </summary>
bool EnemyBase::GetDestroyDown() const
{
	return is_destroy;
}

/// <summary>
	/// 移動処理
	/// </summary>
	/// <param name="delta_second">1フレームあたりの時間</param>
void EnemyBase::Movement(float delta_second)
{
	location += velocity * D_ENEMY_SPEED * delta_second;
}

/// <summary>
	/// アニメーション制御
	/// </summary>
	/// <param name="delta_second">1フレームあたりの時間</param>
void EnemyBase::AnimationControl(float delta_second)
{
	// 移動中のアニメーション
	animation_time += delta_second;
	if (animation_time >= (1.0f / 16.0f))
	{
		animation_time = 0.0f;
		animation_count++;
		if (animation_count >= 4)
		{
			animation_count = 0;
		}
		// 画像の設定
		int dir_num = (int)now_direction_state;
		if (0 <= dir_num && dir_num < 4)
		{
			image = move_animation[(dir_num * 3) + animation_num[animation_count]];
		}

	}
}
