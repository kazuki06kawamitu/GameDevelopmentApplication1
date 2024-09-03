#pragma once

#include"Vector2D.h"

#define XINPUT_BUTTON_MAX (16)  //ボタンの数


//クラス設定
class InputControll_pad
{
	//クラスポインタ
	static InputControll_pad* instance;
private:
	static bool now_button[XINPUT_BUTTON_MAX];
	static bool old_button[XINPUT_BUTTON_MAX];
	static float trigger[2];
	static Vector2D stick[2];

private:
	InputControll_pad() = default;

	//コピーガード
	InputControll_pad(InputControll_pad& v) = delete;
	InputControll_pad& operator=(InputControll_pad& v) = delete;

public:
	~InputControll_pad() = default;

public:
	static InputControll_pad* Getinsatance();

	static  void DeleteInstance();


public:
	static void Update();

	static float GetLeftTrigger();
	static float GetRightTriggre();

	static void GetInputButton();

	static Vector2D GetRightStick();
	static Vector2D GetLeftStick();

private:
	static bool CheckButtonRange(int button);
};