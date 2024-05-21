#pragma once

#define D_KEYCODE_MAX (256)//�L�[���͍ő�l

class InputControl  //���͐���N���X�i�����o�͐ÓI�ŏ��L����)
{
	//��{�I�Ƀ����o�ϐ��̓v���C�x�[�g
private:
	static char now_Key[D_KEYCODE_MAX];//���݂̓��͒l
	static char old_Key[D_KEYCODE_MAX];//�O��̓��͒l

public://�֐��̓p�u���b�N
	static void Update();

	static bool GetKey(int Key_code);
	static bool GetKeyDown(int Key_code);
	static bool GetKeyUp(int Key_code);

private:
	static bool CheckKeyCodeRange(int Key_code);

};