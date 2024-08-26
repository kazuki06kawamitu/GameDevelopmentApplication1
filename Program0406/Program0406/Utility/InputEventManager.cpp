#include "InputEventManager.h"

//静的メンバ変数定義
InputEventManager* InputEventManager::instance = nullptr;

//インスタンスを取得関数
InputEventManager* InputEventManager::GetInstance()
{
	if (!instance)
	{
		instance = new InputEventManager();
	}
	return instance;
}

//インスタンス削除関数
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
	//入力管理クラスのインスタンスを取得する
	InputManager* input = InputManager::Get();

	//リスト内に登録されているイベントがあれば、
	//キーボード入力イベントの実行
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
	//登録されているイベント内容を削除する
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