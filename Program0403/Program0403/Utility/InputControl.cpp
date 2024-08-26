#include "InputControl.h"
#include "DxLib.h"

//�ÓI�����o�ϐ�
InputControl* InputControl::instance = nullptr;

InputControl::InputControl()
{
	memset(now_key, false, (sizeof(char) * D_KEYCODE_MAX));
	memset(old_key, false, (sizeof(char) * D_KEYCODE_MAX));
}

InputControl::~InputControl()
{
	instance = nullptr;
}

//�C���X�^���X�擾����
InputControl* InputControl::GetInstance()
{
	//�C���X�^���X����������ĂȂ��ꍇ�A��������
	if (instance == nullptr)
	{
		instance = new InputControl();
	}
	return instance;
}

void InputControl::DeleteInstance()
{
	if (instance != nullptr)
	{
		delete instance;
	}
}

//���͒l�̍X�V����
void InputControl::Update()
{
	//�O����͒l�̍X�V
	memcpy(old_key, now_key, (sizeof(char) * D_KEYCODE_MAX));
	//���ݓ��͒l�̍X�V
	GetHitKeyStateAll(now_key);
}

//�L�[�擾(�����Ă���)
bool InputControl::GetKey(int key_code) const
{
	return CheckKeyCodeRange(key_code) && (now_key[key_code] == TRUE) &&
		(old_key[key_code] == TRUE);
}

//�L�[�擾(�������u��)
bool InputControl::GetKeyDown(int key_code) const
{
	return CheckKeyCodeRange(key_code) && (now_key[key_code] == TRUE) &&
		(old_key[key_code] == FALSE);
}

//�L�[�擾(�������u��)
bool InputControl::GetKeyUp(int key_code)const
{
	return CheckKeyCodeRange(key_code) && (now_key[key_code] == FALSE) &&
		(old_key[key_code] == TRUE);
}

//�L�[�͈̓`�F�b�N
bool InputControl::CheckKeyCodeRange(int key_code)const
{
	return (0 <= key_code && key_code < D_KEYCODE_MAX);
}