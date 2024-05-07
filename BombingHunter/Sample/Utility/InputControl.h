#pragma once

#define D_KEYCODE_MAX (256)//キー入力最大値

class InputControl  //入力制御クラス（メンバは静的で所有する)
{
	//基本的にメンバ変数はプライベート
private:
	static char now_Key[D_KEYCODE_MAX];//現在の入力値
	static char old_Key[D_KEYCODE_MAX];//前回の入力値

public://関数はパブリック
	static void Update();

	static bool GetKey(int Key_code);
	static bool GetKeyDown(int Key_code);
	static bool GetKeyUp(int Key_code);

private:
	static bool CheckKeyCodeRange(int Key_code);

};