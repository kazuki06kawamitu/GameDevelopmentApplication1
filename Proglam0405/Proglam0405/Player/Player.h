#pragma once
#include <vector>
#include "State/Enum/PlayerState.h"
#include"../Utility/Vector2D.h"

///<summary>
///�v���C���[�N���X
/// </summry>
class Player
{
private:
	class PlayerStateBase* state = nullptr;  //���݂̏��
	ePlayerState next_state = ePlayerState::NONE;  //���̏��
	float g_velocity = 0.0f;                 //�d�͑��x
	Vector2D location = Vector2D(0.0f);      //���W

public:
	Vector2D velocity = Vector2D(0.0f);    //���x
	Vector2D box_size = Vector2D(0.0f);    //�T�C�Y

public:
	Player() = default;                  //�R���X�g���N�^
	~Player() = default;                 //�f�t�H���g�̃f�X�g���N�^���g�p

public:
///<summary>
///����������
/// </summry>
///<param name="init_location">�������W</param>
	void Initialize(Vector2D init_location = Vector2D(0.0f));

///<summary>
///�I������
/// </summry>
	void Finalize();

///<summary>
///�X�V����
/// </summry>
	void Update();

///<summary>
///�`�揈��
/// </summry>
	void Draw() const;

public:
///<summary>
///����State��ݒ�
/// </summry>
/// <Player name="next_state">����State</param>
	void SetNextState(ePlayerState next_state);

///<summary>
///���W�̎擾
/// </summry>
	Vector2D& GetLocation();
};