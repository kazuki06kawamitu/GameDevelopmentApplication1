#pragma once

#include "../Utility/Vector2D.h"

class Player
{
private:
	Vector2D location;  //位置情報
	Vector2D velocity;  //移動量
	Vector2D box_size;  //短形の大きさ
	float g_velocity = 0.0f;                 //重力速度

public:
	Player();
	~Player();

public:
	void Initialize();
	void Update(float delta_second);
	void Draw() const;
	void Finalize();

public:
	void Movement(float param);
	void MovementJanp(float param);
};