#pragma once

#define D_KEYCODE_MAX (256) //�L�[�{�[�h�R�[�h�̑���

class InputControl
{
private:
	static char now_Key[D_KEYCODE_MAX];  //�V�������͂����Ƃ��̃L�[�{�[�h�L�[
	static char old_Key[D_KEYCODE_MAX];  //���͂��I�������̃L�[�{�[�h�L�[

public:
	static void Update();//�X�V����

	static bool GetKey(int Key_code);//�����Ă�����擾
	static bool GetKeyDown(int key_code);//�������t���[�����擾
	static bool GetKeyUp(int Key_code);//�������t���[�����擾

private:
	//�L�[�R�[�h�̗L���͈͓��`�F�b�N�i�����^�ŃL�[�R�[�h�͈͓̔��𒲂ׂ�j
	static bool CheckKeyCodeRange(int Key_code);

};