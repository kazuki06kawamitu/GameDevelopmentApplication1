#pragma once

#include "../GameObject.h"
#include "../../Utility/StageData.h"

#define D_ENEMY (1)

enum eEnemyState
{
	RESPWAN,	// 復活状態
	SEARCH,		// 探索状態
	CHASE,		//追いかけ状態
	DIE,		// 死亡状態
};


class EnemyBase : public GameObject
{
protected:
	// 進行方向状態
	enum eDirectionState : unsigned char
	{
		UP,
		RIGHT,
		DOWN,
		LEFT,
		NONE,
	};

private:
	std::vector<int> move_animation;		// 移動のアニメーション画像
	std::vector<int> dying_animation;		// 死亡のアニメーション画像
	Vector2D old_location;					// 前回のlocation
	Vector2D velocity;						// 移動量
	eEnemyState enemy_state;				// プレイヤー状態
	eDirectionState now_direction_state;	// 現在進行方向状態
	eDirectionState next_direction_state;	// 次回進行方向状態
	float animation_time;					// アニメーション時間
	int animation_count;					// アニメーション添字

public:
	EnemyBase();
	virtual ~EnemyBase();


};