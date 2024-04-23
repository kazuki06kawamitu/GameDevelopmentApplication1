#pragma once

#include "../Objects/GameObject.h"
#include <vector>

class Scene
{
private:
	std::vector<GameObject*>objects;  //�I�u�W�F�N�g���X�g

public:
	Scene();
	~Scene();

	void Initialize();
	void Update();
	void Draw()const;
	void Finalize();

private:
	//�I�u�W�F�N�g��������
	template<class T>
	T* CeateObject(const Vector2D& location)
	{
		//�w�肵���N���X�𐶐�����
		T* new_instance = new T();
		//GameObject�N���X���p�����Ă��邩�m�F
		GameObject* new_object = dynamic_cast<GameObject*>(new_instance);

		//�G���[�`�F�b�N
		if (new_object == nullptr)
		{
			delete new_instance;
			throw std::string("�Q�[���I�u�W�F�N�g�������ł��܂���ł���");
		}

	}
	//����������
	new_object->initialize();

	//�ʒu���̐ݒ�
	new_object->SetLocation(location);

	//�V�[�����ɑ��݂���I�u�W�F�N�g���X�g�ɒǉ�
	object.push_back(new_object);
};