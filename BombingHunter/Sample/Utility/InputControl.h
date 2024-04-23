#pragma once

#define D_KEYCODE_MAX (256)

class InputControl
{
private:
	static char now_Key[D_KEYCODE_MAX];
	static char old_Key[D_KEYCODE_MAX];

public:
	static void Update();

	static bool GetKey(int Key_code);
	static bool GetKeyDown(int Key_code);
	static bool GetKeyUp(int Key_code);

private:
	static bool CheckKeyCodeRange(int Key_code);

};