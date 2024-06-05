#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Scene/Scene.h"

//�v���O�����͂�������n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{
	//Window���[�h�ŋN������
	ChangeWindowMode(TRUE);

	//Window�T�C�Y�̐ݒ�(640�~480�̃T�C�Y)
	SetGraphMode(640, 480, 32);

	//Dx���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		//�ُ��ʒm
		return -1;
	}
	//����ʂ���`����n�߂�
	SetDrawScreen(DX_SCREEN_BACK);
	

	//���[�J���ϐ���`
	Scene* scene = new Scene();//�V�[���𐶐�����
	int result = 0;            //�I����ԏ��

	try
	{
		//�V�[���̏�����
		scene->Initialize();

		//���C�����[�v(�X�V�ƕ`����s��)
		//ESC�L�[�������ꂽ��A���[�v���I������
		while (ProcessMessage() != -1 &&
	InputControl::GetKeyUp(KEY_INPUT_ESCAPE) == false)
		{
			//���͋@�\�̍X�V����
			InputControl::Update();

			//�V�[���̍X�V����
			scene->Update();

			//��ʂ̏�����
			ClearDrawScreen();
			
			//�V�[���̕`�揈��
			scene->Draw();

			//����ʂ̓��e��\��ʂɔ��f����
			ScreenFlip();
		}
	}
	catch(const char* error_log)
	{
		//��O�X���[���ꂽ�������O�t�@�C���ɏo�͂���
		OutputDebugString(error_log);
		//�ُ�I����ʒm����
		result = -1;
	}

	//�V�[����񂪑��݂��Ă���΁A�폜����
	if (scene != nullptr)
	{
		scene->Finalize();
		delete scene;
		scene = nullptr;
	}

	DxLib_End();

	//�I����Ԃ̒l��ʒm����
	return result;
}