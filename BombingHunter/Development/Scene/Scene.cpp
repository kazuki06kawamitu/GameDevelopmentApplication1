#include "Scene.h"


#include "../Objects/Player/Player.h"
#include "../Objects/Weapon/Bomb.h"
#include "../Objects/Weapon/Blast.h"
#include "../Objects/Enemy/Enemy.h"
#include "../Objects/Enemy/WingEnemy.h"
#include "../Objects/Enemy/Harpy.h"
#include "../Objects/Enemy/GoldEnemy.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

#define D_PIVOT_CENTER

//�R���X�g���N�^
Scene::Scene() : objects(), back_ground_image(NULL),time(60), tc(0),ui_image(), score()
{
	
}

//�f�X�g���N�^
Scene::~Scene()
{
	//�Y��h�~
	Finalize();
}

//����������
void Scene::Initialize()
{
	
	//�v���C���[�𐶐�����
	CreateObject<Player>(Vector2D(320.0f, 65.0f));
	ui_image[0] = LoadGraph("Resource/Images/Score/0.png");
	ui_image[1] = LoadGraph("Resource/Images/Score/1.png");
	ui_image[2] = LoadGraph("Resource/Images/Score/2.png");
	ui_image[3] = LoadGraph("Resource/Images/Score/3.png");
	ui_image[4] = LoadGraph("Resource/Images/Score/4.png");
	ui_image[5] = LoadGraph("Resource/Images/Score/5.png");
	ui_image[6] = LoadGraph("Resource/Images/Score/6.png");
	ui_image[7] = LoadGraph("Resource/Images/Score/7.png");
	ui_image[8] = LoadGraph("Resource/Images/Score/8.png");
	ui_image[9] = LoadGraph("Resource/Images/Score/9.png");

	back_ground_image = LoadGraph("Resource/Images/BackGround.png");
	
}

//�X�V����
void Scene::Update()
{
	//�V�[���ɑ��݂���I�u�W�F�N�g�̍X�V����
	for (GameObject* obj : objects)
	{
		obj->Update();

	}

	Spown();
	CountTimer();
	//�I�u�W�F�N�g���s�̓����蔻��`�F�b�N
	for (int i = 0; i < objects.size(); i++)
	{
		for (int j = i + 1; j < objects.size(); j++)
		{
			//�����蔻��`�F�b�N����
			HitCheckObject(objects[i], objects[j]);
		}
		if (objects[i]->DeleteObject() == TRUE)
		{
			this->objects.erase(objects.begin() + i);
		}
	}

	//Z�L�[����������A�G�̍U��������
	if (InputControl::GetKeyDown(KEY_INPUT_Z))
	{

		Vector2D enemy = objects[1]->GetLocation();
		Blast* blast = CreateObject<Blast>(Vector2D(enemy.x, enemy.y));

		blast->SetDirection(objects[0]->GetLocation());

	}

	//
	if (InputControl::GetKeyDown(KEY_INPUT_SPACE))
	{
		Vector2D player = objects[0]->GetLocation();
		CreateObject<Bomb>(Vector2D(player.x, 130.0));
	}

	
}

//�`�揈��
void Scene::Draw()const
{

	

	//�w�i�̊p�x
	DrawRotaGraph(320, 240, 0.67,0.0f, back_ground_image, TRUE,FALSE);
	//
	
	//�V�[���ɑ��݂���I�u�W�F�N�g�̕`�揈��
	for (GameObject* obj : objects)
	{
		obj->Draw();
	

	}
}

//�����_���ɓG���o��������
void Scene::Spown()
{
	int spownenemy = GetRand(6);
	int loc_y = GetRand(1);
	int flip = FALSE;

	
	int spowncount = rand() % 100 + 1;
	if (spowncount <= 1)
	{
		switch (spownenemy)
		{
		case 0:
			CreateObject<Enemy>(Vector2D(100.0f, 400.0f));
			break;
		case 1:
			CreateObject<Enemy>(Vector2D(500.0f, 400.0f));
			break;

		case 2:
			CreateObject<WingEnemy>(Vector2D(100.f, 250.0f + (loc_y * 100)));
			break;

		case 3:
			CreateObject<WingEnemy>(Vector2D(500.f, -250.0f + (loc_y * 100)));
			break;

		case 4:
			CreateObject<Harpy>(Vector2D(100.0f, 150.0f + (loc_y * 100)));
			break;
		case 5:
			CreateObject<Harpy>(Vector2D(500.0f, -150.0f + (loc_y * 100)));
			break;
		default:
			//CreateObject<GoldEnemy>(Vector2D(100.0f, 400.0f));
			break;
		}
	}
		

}

//�������Ԃ�ǉ�
void Scene::CountTimer()
{
	tc++;
	if (tc >= D_FREAME)
	{
		time--;
		tc = 0;
	}
}

void Scene::Score()
{
	for (int i = 0; i < objects.size(); i++)
	{

	}
}

//�I��������
void Scene::Finalize()
{
	//���I�z�񂪋�Ȃ珈�����I������
	if (objects.empty())
	{
		return;
	}

	//�e�I�u�W�F�N�g���폜����
	for (GameObject* obj : objects)
	{
		obj->Finalize();
		delete obj;
	}
	//���I�z��̉��
	objects.clear();
}

#ifdef D_PIVOT_CENTER

//�����蔻��`�F�b�N�����i�Z�`�̒��S�œ����蔻������j
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//2�̃I�u�W�F�N�g�̋������擾
	Vector2D diff = a->GetLocation() - b->GetLocation();

	//2�̃I�u�W�F�N�g�̓����蔻��̑傫�����擾
	Vector2D box_size = (a->GetBoxSize() + b->GetBoxSize()) / 2.0f;

	if (a->GetObjectFlag() != b->GetObjectFlag())
	{
		//�������傫�����傫���ꍇ�AHit����Ƃ���
	if ((fabsf(diff.x) < box_size.x) && (fabsf(diff.y) < box_size.y))
		{
			//�����������Ƃ��I�u�W�F�N�g�ɒʒm����
			a->OnHitCollision(b);
  			b->OnHitCollision(a);

		}
		
	}
	
}
#else

//�����蔻��`�F�b�N����(���㒸�_�̍��W���瓖���蔻��v�Z���s��)
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//�E�����_���W���擾����
	Vector2D a_lower_right = a->GetLocation() + a->GetBoxSize();
	Vector2D b_lower_right = b->GetLocation() + b->GetBoxSize();

	//�Z�`A�ƒZ�`B�̈ʒu�֌W�𒲂ׂ�
	if ((a->GetLocation().x < b_lower_right.x) &&
		(a->GetLocation().y < b_lower_right.y) &&
		(a_lower_right.x > b->GetLocation().x) &&
		(a_lower_right.y > b->GetLocation().y))
	{
		//�I�u�W�F�N�g�ɑ΂���Hit�����ʒm����
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}
#endif // D_PIVOT_CENTER
