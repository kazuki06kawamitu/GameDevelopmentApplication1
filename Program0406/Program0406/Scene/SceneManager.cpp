#include "SceneManager.h"

#include "DxLib.h"
#include "../Utility/InputManager.h"
#include "../Utility/InputEventManager.h"
#include "../Utility/SceneFactory.h"

SceneManager::SceneManager() :current_scene(nullptr), is_finalize(false)
{
}

SceneManager::~SceneManager()
{
	Finalize();
}

void SceneManager::Initialize() 
{
	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//��ʃT�C�Y�̐ݒ�
	SetGraphMode(640, 480, 32);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		throw("DX���C�u�������������ł��܂���ł����B\n");
	}

	//����ʂ̂���`����n�߂�
	SetDrawScreen(DX_SCREEN_BACK);

	//�^�C�g����ʂ���V�[�����J�n����
	ChangeScene(eSceneType::eInGame);
}

void SceneManager::Update()
{
	//�J�n���Ԃ��擾
	LONGLONG start_time = GetNowHiPerformanceCount();

	//���͋@�\�̃C���X�^���X���擾����
	InputManager* input = InputManager::Get();

	//���C�����[�v
	while (ProcessMessage() != -1 && input->GetKeyState(KEY_INPUT_ESCAPE) ==
		eInputState::None)
	{
		//�P�t���[��������̎��Ԃ��v�Z����
		float delta_second = static_cast<float>(GetNowHiPerformanceCount() -
			start_time) * 0.000001f;

		//�J�n���Ԃ̍X�V
		start_time = GetNowHiPerformanceCount();

		input->Update();

		//�V�[���̍X�V����
		eSceneType next_scene_type = current_scene->Update(delta_second);

		//�`��
		Draw();

		//�V�[���؂�ւ�
		if (next_scene_type != current_scene->GetNowSceneType())
		{
			ChangeScene(next_scene_type);
		}
	}
}

void SceneManager::Finalize()
{
	if (is_finalize)
	{
		return;
	}

	//���̓C�x���g�̍폜
	InputEventManager::DeleteInstance();

	//DX���C�u�����̏I������
	DxLib_End();

	//�I����������
	is_finalize = true;
}

void SceneManager:: Draw() const
{
	//��ʂ̏�����
	ClearDrawScreen();

	//�V�[���̕`�揈��
	current_scene->Draw();

	//����ʂ̓��e��\��ʂɔ��f����
	ScreenFlip();
}

void SceneManager::ChangeScene(eSceneType type)
{
	//�����œn���ꂽ��񂩂�V�����V�[�����쐬����
	SceneBase* new_scene = SceneFactory::CreateScene(type);

	//�G���[�`�F�b�N
	if (new_scene == nullptr)
	{
		throw("�V�[���������ł��܂���ł����B\n");
	}

	//���݂̃V�[���̏C������
	if (current_scene != nullptr)
	{
		current_scene->Finalize();
		delete current_scene;
	}
	//�V�����V�[���̏�����
	new_scene->Initialize();
	current_scene = new_scene;
}