#include "InputControl.h"
#include "DxLib.h"

char InputControl::now_Key[D_KEYCODE_MAX] = {};//���݂̓��͏��
char InputControl::old_Key[D_KEYCODE_MAX] = {};//�O�t���[���̓��͏��

//�L�[�̏��X�V����
void InputControl::Update()
{
	//�O�t���[���̓��͏��ɁA���݂̓��͏����R�s�[���鏈��
	memcpy(old_Key, now_Key, (sizeof(char) * D_KEYCODE_MAX));
	//���݂̓��͏����X�V����
	GetHitKeyStateAll(now_Key);
}
//�����Ă��鎞�̏�񏈗�
bool InputControl::GetKey(int Key_code)
{
	return CheckKeyCodeRange(Key_code) && ((now_Key[Key_code] == TRUE) &&
		(old_Key[Key_code] == TRUE));
}
//�������u�Ԃ̏�񏈗�
bool  InputControl::GetKeyDown(int Key_code)
{
	return CheckKeyCodeRange(Key_code) && ((now_Key[Key_code] == TRUE) &&
		(old_Key[Key_code] == FALSE));
}
//���������̏�񏈗�
bool InputControl::GetKeyUp(int Key_code)
{
	return CheckKeyCodeRange(Key_code) && ((now_Key[Key_code] == FALSE) &&
		(old_Key[Key_code] == TRUE));
}
//�L�[�R�[�h�̗L���͈͓��`�F�b�N
bool InputControl::CheckKeyCodeRange(int Key_code)
{
	return (0 <= Key_code && Key_code < D_KEYCODE_MAX);
}