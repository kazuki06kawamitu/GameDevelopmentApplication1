#include "InputControl_Pad.h"
#include "DxLib.h"

//ボタン取得
XINPUT_STATE input_button;
bool InputControll_pad::now_button[XINPUT_BUTTON_MAX] = {};
bool InputControll_pad::old_button[XINPUT_BUTTON_MAX] = {};
//トリガー情報
float InputControll_pad::trigger[2] = {};
//スティック情報
Vector2D InputControll_pad::stick[2] = {};
int i;
int Color;

//描画処理
void InputControll_pad::Update()
{
	GetJoypadXInputState(DX_INPUT_PAD1, &input_button);
	GetInputButton();
	for (i = 0; i < XINPUT_BUTTON_MAX; i++)
	{
		now_button[i] = input_button.Buttons[i];
	}

}

//左トリガーの値
float InputControll_pad::GetLeftTrigger()
{
	trigger[0] = input_button.LeftTrigger;
	return trigger[0];
}

//右トリガーの値
float InputControll_pad::GetRightTriggre()
{
	trigger[1] = input_button.RightTrigger;
	return trigger[1];
}

//右スティックの値
Vector2D InputControll_pad::GetRightStick()
{
	stick[0].x = input_button.ThumbRX;
	stick[0].y = input_button.ThumbRY;
	return stick[0];
}

//左スティックの値
Vector2D InputControll_pad::GetLeftStick()
{
	stick[1].x = input_button.ThumbLX;
	stick[1].y = input_button.ThumbLY;
	return stick[1];
}

void InputControll_pad::GetInputButton()
{
	//色の指定
	Color = GetColor(255, 255, 255);

	//スティックの値取得
	stick[0] = GetRightStick();
	stick[1] = GetLeftStick();

	//十字キーの値取得
	DrawFormatString(1, 1, Color, "十字キーの上%2d", input_button.Buttons[0]);
	DrawFormatString(1, 20, Color, "十字キーの下%2d", input_button.Buttons[1]);
	DrawFormatString(1, 40, Color, "十字キーの左%2d", input_button.Buttons[2]);
	DrawFormatString(1, 60, Color, "十字キーの右%2d", input_button.Buttons[3]);
	////STATE,BACKボタンの値の取得
	DrawFormatString(1, 80, Color, "STATEボタン%2d", input_button.Buttons[4]);
	DrawFormatString(1, 100, Color, "BACKボタン%2d", input_button.Buttons[5]);

	//スティックの押し込みの値取得
	DrawFormatString(1, 120, Color, "左スティック押し込み%2d", input_button.Buttons[6]);
	DrawFormatString(1, 140, Color, "右スティック押し込み%2d", input_button.Buttons[7]);

	//各ボタンの値取得
	DrawFormatString(200, 1, Color, "LBボタン%2d", input_button.Buttons[8]);
	DrawFormatString(200, 20, Color, "RBボタン%2d", input_button.Buttons[9]);
	DrawFormatString(200, 80, Color, "Aボタン%2d", input_button.Buttons[12]);
	DrawFormatString(200, 100, Color, "Bボタン%2d", input_button.Buttons[13]);
	DrawFormatString(200, 120, Color, "Xボタン%2d", input_button.Buttons[14]);
	DrawFormatString(200, 140, Color, "Yボタン%2d", input_button.Buttons[15]);

	//各トリガーの値の取得
	DrawFormatString(1, 160, Color, "左トリガー%.1f", input_button.LeftTrigger / 255.000);
	DrawFormatString(1, 180, Color, "右トリガー%.1f", input_button.RightTrigger / 255.000);

	//各スティックの値の取得
	DrawFormatString(1, 200, Color, "左スティックx%.1f", float(stick[1].x / 32767.000));
	DrawFormatString(220, 200, Color, "左スティックy%.1f", float(stick[1].y / 32767.000));
	DrawFormatString(1, 220, Color, "右スティックx%.1f", float(stick[0].x / 32767.000));
	DrawFormatString(220, 220, Color, "右スティックy%.1f", float(stick[0].y / 32767.000));
}
