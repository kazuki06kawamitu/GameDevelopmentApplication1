#include "InputEventManager.h"

//�ÓI�����o�ϐ���`
InputEventManager* InputEventManager::instance = nullptr;

//�C���X�^���X���擾�֐�
InputEventManager* InputEventManager::GetInstance()
{
	if (!instance)
	{
		instance = new InputEventManager();
	}
	return instance;
}

//�C���X�^���X�폜�֐�
void InputEventManager::DeleteInstance()
{
	if (instance)
	{
		instance->AllUnbind();
		delete instance;
		instance = NULL;
	}
}
void InputEventManager::InputActionEvent()
{
	//���͊Ǘ��N���X�̃C���X�^���X���擾����
	InputManager* input = InputManager::Get();

	//���X�g���ɓo�^����Ă���C�x���g������΁A
	//�L�[�{�[�h���̓C�x���g�̎��s
	if (!keycode_event.empty())
	{
		for (EventSender sender : keycode_event)
		{
			if (input->GetKeyState(sender.input_id) == sender.event_state &&
				sender.event_state != eInputState::None)
			{
				sender.call_back_func->Invoke();
			}
			else if (input->GetKeyState(sender.input_id) ==
				eInputState::Held)
			{
				sender.call_back_func->Invoke(sender.value);
			}
		}
	}
}
void InputEventManager::AllUnbind()
{
	//�o�^����Ă���C�x���g���e���폜����
	if (!keycode_event.empty())
	{
		for (EventSender sender : keycode_event)
		{
			delete sender.call_back_func;
			sender.call_back_func = nullptr;
		}
		keycode_event.clear();
	}
}