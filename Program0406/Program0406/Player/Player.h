#pragma once

#include "../Utility/Vector2D.h"

class Player
{
private:
	Vector2D location;  //�ʒu���
	Vector2D velocity;  //�ړ���
	Vector2D box_size;  //�Z�`�̑傫��
	float g_velocity = 0.0f;                 //�d�͑��x

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