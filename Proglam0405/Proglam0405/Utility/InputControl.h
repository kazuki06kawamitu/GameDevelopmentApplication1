#pragma once

//�}�N����`
#define D_KEYCODE_MAX (256)  //�L�[�R�[�h�ő吔

//���͐���N���X
class InputControl
{
private:
	//���N���X�̃|�C���^(�A�h���X�̐�ɃC���X�^���X�𐶐�����)
	static InputControl* instance;

	//�L�[�{�[�h���͒l
	char now_key[D_KEYCODE_MAX];  //���݂̓��͒l
	char old_key[D_KEYCODE_MAX];  //�O��̓��͒l

private:
	//�R���X�g���N�^��private�ɂ��邱�ƂŁA
	//���N���X�̃����o�֐��ł����C���X�^���X�𐶐��ł��Ȃ��悤�ɂ���
	InputControl();

	//�R�s�[�K�[�h
	//�N���X�O�ŃC���X�^���X�𐶐����ēn�����Ƃ��ł��Ȃ��悤�ɂ���
	InputControl(InputControl& v) = default;
	InputControl& operator=(const InputControl& v) = default;
	//~�R�s�[�K�[�h

public:
	~InputControl();

public:
	//�C���X�^���X�擾���鏈��
	static InputControl* GetInstance();
	//�C���X�^���X�폜���鏈��
	static void DeleteInstance();

public:
	//�L�[���͏�Ԃ��擾����
	void Update();

	//���[���͏�Ԃ��擾����
	bool GetKey(int key_code)const; //�����Ă����
	bool GetKeyDown(int key_code)const; //�������u��
	bool GetKeyUp(int key_code) const;  //�������u��

private:
	//�L�[���͂̎��͂��m�F
	bool CheckKeyCodeRange(int key_code) const;
};