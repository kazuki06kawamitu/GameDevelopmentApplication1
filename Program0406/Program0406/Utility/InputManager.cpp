#include "InputManager.h"
#include "DxLib.h"

InputManager* InputManager::Get()
{
	static InputManager instance;
	return &instance;
}

void InputManager::Update()
{
	//�O����͒l�̍X�V����
	memcpy(old_key, now_key, (sizeof(char) * D_KEYCODE_MAX));

	//���ݓ��͒l�̍X�V
	GetHitKeyStateAll(now_key);
}

eInputState InputManager::GetKeyState(int keycode)const
{
	if (CheckKeycodeRange(keycode))
	{
		if (now_key[keycode] == TRUE)
		{
			if (now_key[keycode] == TRUE)
			{
				return eInputState::Held;
			}
			else
			{
				return eInputState::Released;
			}
		}
		else
		{
			if (now_key[keycode] == TRUE)
			{
				return eInputState::Pressed;
			}
			else
			{
				return eInputState::None;
			}
		}
	}
	return eInputState::None;
}
bool InputManager::CheckKeycodeRange(int keycode)const
{
	return (0 <= keycode && keycode < D_KEYCODE_MAX);
}