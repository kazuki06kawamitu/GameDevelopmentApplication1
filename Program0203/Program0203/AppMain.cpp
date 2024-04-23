#include"DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/Player/Player.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//Dx���C�u�����̏���������
	if (DxLib_Init() == -1)
	{
		return-1;
	}
	//�I�u�W�F�N�g����
	GameObject* object[2] = {nullptr,nullptr};
	object[0] = new GameObject();//�����œ�����
	object[1] = new Player();//�����œ�����
	
	for (int i = 0; i < 2; i++)
	{
		object[i]->Initialize();
	}
	//����ʂ̓��e��\��ʂɕ`�悷��
	SetDrawScreen(DX_SCREEN_BACK);
	//���C�����[�v
	while (ProcessMessage() != -1)
	{
		InputControl::Update();//�X�V����

		for (int i = 0; i < 2; i++)
		{
			object[i]->Update();
		}
		//��ʂ̍폜
		ClearDrawScreen();

		for (int i = 0; i < 2; i++)
		{
			object[i]->Draw();
		}
		//��ʂ̍X�V
		ScreenFlip();
		//�G�X�P�[�v�L�[�������ꂽ�Ƃ��I�����鏈��
		if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		object[i]->Finalize();
		delete object[i];
	}

	//Dx���C�u�����g�p�̏I������
	DxLib_End();


	return 0;
}