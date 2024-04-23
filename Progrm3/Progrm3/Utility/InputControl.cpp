#include "InputControl.h"
#include "DxLib.h"

char InputControl::now_Key[D_KEYCODE_MAX] = {};//現在の入力情報
char InputControl::old_Key[D_KEYCODE_MAX] = {};//前フレームの入力情報

//キーの情報更新処理
void InputControl::Update()
{
	//前フレームの入力情報に、現在の入力情報をコピーする処理
	memcpy(old_Key, now_Key, (sizeof(char) * D_KEYCODE_MAX));
	//現在の入力情報を更新する
	GetHitKeyStateAll(now_Key);
}
//キーの取得
bool InputControl::GetKey(int Key_code)
{
	return CheckKeyCodeRange(Key_code) && ((now_Key[Key_code] == TRUE) &&
		(old_Key[Key_code] == TRUE));
}
//
bool  InputControl::GetKeyDown(int Key_code)
{
	return CheckKeyCodeRange(Key_code) && ((now_Key[Key_code] == TRUE) &&
		(old_Key[Key_code] == FALSE));
}

bool InputControl::GetKeyUp(int Key_code)
{
	return CheckKeyCodeRange(Key_code) && ((now_Key[Key_code] == FALSE) &&
		(old_Key[Key_code] == TRUE));
}

bool InputControl::CheckKeyCodeRange(int Key_code)
{
	return (0 <= Key_code && Key_code < D_KEYCODE_MAX);
}