#include"DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/GameObject.h"
#include "Objects/Player.h"
//�v���O�����J�n
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//Dx���C�u�����̏���������
	if (DxLib_Init() == -1)
	{
		return-1;
	}

	SetDrawScreen(DX_SCREEN_BACK);//�`����ʂ𗠂ɂ���

	GameObject* object1 = new GameObject();//�I�u�W�F�N�g����
	Player* object2 = new Player();//�I�u�W�F�N�g����

	//����������
	object1->Initialize();
	object2->Initialize();
	//���C�����[�v
	while (ProcessMessage() != -1 && InputControl::GetKeyUp(KEY_INPUT_ESCAPE) == false)
	{
		InputControl::Update();//�X�V����
		//�I�u�W�F�N�g�̍X�V
		object1->Update();
		object2->Update();

		//��ʂ̏�����
		ClearDrawScreen();
		//�`�揈��
		object1->Draw();
		object2->Draw();
		//��ʂ̍X�V
		ScreenFlip();
	}

	//�I�u�W�F�N�g�̍폜
	delete object1;
	delete object2;

	//Dx���C�u�����g�p�̏I������
	DxLib_End();


	return 0;
}