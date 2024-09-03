#pragma once

#define D_KEYCODE_MAX (256)  //�L�[�̓��͔͈�

//�L�[�̓��͏��
enum class eInputState : unsigned char
{
	None,
	Pressed,
	Released,
	Held,
};

//���͊Ǘ��N���X
class InputManager
{
private:
	//�L�[�{�[�h���͒l
	char old_key[D_KEYCODE_MAX] = {};  //�O����͒l
	char now_key[D_KEYCODE_MAX] = {};  //���ݓ��͒l

private:
	InputManager() = default;
	InputManager(const InputManager&) = delete;
	InputManager& operator=(const InputManager&) = delete;
	~InputManager() = default;

public:
	//�C���X�^���X�擾
	static InputManager* Get();

public:
	//�X�V����
	void Update();

public:
	//���͏�Ԃ��擾����
	eInputState GetKeyState(int keycode) const;

private:
	//�L�[�R�[�h�͈͓��`�F�b�N
	bool CheckKeycodeRange(int keycode)const;
};