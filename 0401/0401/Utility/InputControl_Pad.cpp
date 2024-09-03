#include "InputControl_Pad.h"
#include "DxLib.h"

//�{�^���擾
XINPUT_STATE input_button;
bool InputControll_pad::now_button[XINPUT_BUTTON_MAX] = {};
bool InputControll_pad::old_button[XINPUT_BUTTON_MAX] = {};
//�g���K�[���
float InputControll_pad::trigger[2] = {};
//�X�e�B�b�N���
Vector2D InputControll_pad::stick[2] = {};
int i;
int Color;

//�`�揈��
void InputControll_pad::Update()
{
	GetJoypadXInputState(DX_INPUT_PAD1, &input_button);
	GetInputButton();
	for (i = 0; i < XINPUT_BUTTON_MAX; i++)
	{
		now_button[i] = input_button.Buttons[i];
	}

}

//���g���K�[�̒l
float InputControll_pad::GetLeftTrigger()
{
	trigger[0] = input_button.LeftTrigger;
	return trigger[0];
}

//�E�g���K�[�̒l
float InputControll_pad::GetRightTriggre()
{
	trigger[1] = input_button.RightTrigger;
	return trigger[1];
}

//�E�X�e�B�b�N�̒l
Vector2D InputControll_pad::GetRightStick()
{
	stick[0].x = input_button.ThumbRX;
	stick[0].y = input_button.ThumbRY;
	return stick[0];
}

//���X�e�B�b�N�̒l
Vector2D InputControll_pad::GetLeftStick()
{
	stick[1].x = input_button.ThumbLX;
	stick[1].y = input_button.ThumbLY;
	return stick[1];
}

void InputControll_pad::GetInputButton()
{
	//�F�̎w��
	Color = GetColor(255, 255, 255);

	//�X�e�B�b�N�̒l�擾
	stick[0] = GetRightStick();
	stick[1] = GetLeftStick();

	//�\���L�[�̒l�擾
	DrawFormatString(1, 1, Color, "�\���L�[�̏�%2d", input_button.Buttons[0]);
	DrawFormatString(1, 20, Color, "�\���L�[�̉�%2d", input_button.Buttons[1]);
	DrawFormatString(1, 40, Color, "�\���L�[�̍�%2d", input_button.Buttons[2]);
	DrawFormatString(1, 60, Color, "�\���L�[�̉E%2d", input_button.Buttons[3]);
	////STATE,BACK�{�^���̒l�̎擾
	DrawFormatString(1, 80, Color, "STATE�{�^��%2d", input_button.Buttons[4]);
	DrawFormatString(1, 100, Color, "BACK�{�^��%2d", input_button.Buttons[5]);

	//�X�e�B�b�N�̉������݂̒l�擾
	DrawFormatString(1, 120, Color, "���X�e�B�b�N��������%2d", input_button.Buttons[6]);
	DrawFormatString(1, 140, Color, "�E�X�e�B�b�N��������%2d", input_button.Buttons[7]);

	//�e�{�^���̒l�擾
	DrawFormatString(200, 1, Color, "LB�{�^��%2d", input_button.Buttons[8]);
	DrawFormatString(200, 20, Color, "RB�{�^��%2d", input_button.Buttons[9]);
	DrawFormatString(200, 80, Color, "A�{�^��%2d", input_button.Buttons[12]);
	DrawFormatString(200, 100, Color, "B�{�^��%2d", input_button.Buttons[13]);
	DrawFormatString(200, 120, Color, "X�{�^��%2d", input_button.Buttons[14]);
	DrawFormatString(200, 140, Color, "Y�{�^��%2d", input_button.Buttons[15]);

	//�e�g���K�[�̒l�̎擾
	DrawFormatString(1, 160, Color, "���g���K�[%.1f", input_button.LeftTrigger / 255.000);
	DrawFormatString(1, 180, Color, "�E�g���K�[%.1f", input_button.RightTrigger / 255.000);

	//�e�X�e�B�b�N�̒l�̎擾
	DrawFormatString(1, 200, Color, "���X�e�B�b�Nx%.1f", float(stick[1].x / 32767.000));
	DrawFormatString(220, 200, Color, "���X�e�B�b�Ny%.1f", float(stick[1].y / 32767.000));
	DrawFormatString(1, 220, Color, "�E�X�e�B�b�Nx%.1f", float(stick[0].x / 32767.000));
	DrawFormatString(220, 220, Color, "�E�X�e�B�b�Ny%.1f", float(stick[0].y / 32767.000));
}
