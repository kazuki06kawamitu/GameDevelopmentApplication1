#include"DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/Player.h"
//�v���O�����̊J�n
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//Dx���C�u�����̏���������
	if (DxLib_Init() == -1)
	{
		return-1;
	}
	//�v���C���[�̃I�u�W�F�N�g����
	Player* player = new Player();
	//�`����ʂ𗠂ɂ���
	SetDrawScreen(DX_SCREEN_BACK);
	//���C�����[�v
	while (ProcessMessage() != -1)
	{
		//���͏��̍X�V����
		InputControl::Update();
		//�v���C���[���̍X�V����
		player->Update();
		//�ǂɓ��������甽�Α��̕ǂɈړ�����
		Vector2D tmp = player->GetLocation();
		if (tmp.x < 0.0f || 640.0f < tmp.x)
		{
			if (tmp.x < 0)
			{
				tmp.x = 640.0f;//���̕ǂ���E�̕ǂɈړ�
			}
			else
			{
				tmp.x = 0.0f; //�E�̕ǂ��獶�̕ǂɈړ�
			}
			player->SetLocation(tmp);
		}
		if (tmp.y < 0.0f || 480.0f < tmp.y)
		{
			if (tmp.y < 0)
			{
				tmp.y = 480.0f;//��̕ǂ��牺�̕ǂɈړ�
			}
			else
			{
				tmp.y = 0.0f;//���̕ǂ����̕ǂɈړ�
			}
		}
		player->SetLocation(tmp);//���W�̍X�V
		ClearDrawScreen();//��ʂ̍폜
		player->Draw();//�`�揈��
		ScreenFlip();//��ʂ̍X�V
		//ESCAPE�L�[�������ꂽ��A�I��������
		if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}
	delete player;

	//Dx���C�u�����g�p�̏I������
	DxLib_End();

	return 0;
}