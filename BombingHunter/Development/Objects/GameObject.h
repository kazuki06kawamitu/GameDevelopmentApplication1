#pragma once

#include "../Utility/Vector2D.h"

#define D_PIVOT_CENTER  //���W�̌��_���摜�̒��S�ɂ���

#define D_PLAYER (0)
#define D_ENEMY (1)
#define D_BOMB (0)
#define D_WINGENEMY (1)
#define D_HARPY (1)
#define D_GOLDENEMY (1)
#define D_ENEMYBULLET (1)

//�Q�[���I�u�W�F�N�g���N���X
class GameObject
{
protected:
	Vector2D location;  //�ʒu���
	Vector2D box_size;  //�����蔻��̑傫��
	double scale;       //�傫��
	double radian;      //����
	int image;       //�`�悷��摜
	int sound;          //�Đ����鉹��
	

public:
	int object_flag;
	bool delete_flag;
	

	GameObject();
	virtual ~GameObject();

	virtual void Initialize();       //����������
	virtual void Update();          //�X�V����
	virtual void Draw() const;      //�`�揈��
	virtual void Finalize();        //�I������
	bool DeleteObject();

	//�����蔻��ʒm����
	virtual void OnHitCollision(GameObject* hit_object);

	//�ʒu���擾����
	Vector2D GetLocation() const;
	//�ʒu���ύX����
	void SetLocation(const Vector2D& location);
	//�����蔻��̑傫�����擾����
	Vector2D GetBoxSize() const;
	//�����蔻��̎���
	int GetObjectFlag() const;
};