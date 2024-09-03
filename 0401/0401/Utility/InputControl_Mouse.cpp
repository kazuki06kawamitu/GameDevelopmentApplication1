#include"InputControl_Mouse.h"
#include "DxLib.h"

//クラスのインスタンスを取得する
InputControll_Mouse* InputControll_Mouse::instance = nullptr;

//入力制御クラスのインスタンスを取得する
InputControll_Mouse* InputControll_Mouse::Getinsatance()
{
	//インスタンスが無ければ生成する
	if (instance == nullptr)
	{
		instance == new InputControll_Mouse();
	}

	//ポインタを返却する
	return instance;
}

//入力制御クラスのインスタンスを削除
void InputControll_Mouse::DeleteInstance()
{
	//インスタンスが無ければ削除する
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

//更新処理
void InputControll_Mouse::Update()
{
	//マウスカーソル表示
	SetMouseDispFlag(TRUE);

	//マウスカーソル座標習得
	int x, y = 0;
	GetMousePoint(&x, &y);
	this->location.x = x;
	this->location.y = y;

	//入力情報更新
	for (int i = 0; i < 3; i++)
	{
		old_click[i] = now_click[i];
		now_click[i] = FALSE;
	}
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		now_click[0] = TRUE;
	}
	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0)
	{
		now_click[1] = TRUE;
	}
	if ((GetMouseInput() & MOUSE_INPUT_MIDDLE) != 0)
	{
		now_click[2] = TRUE;
	}
	//ホイール入力状態更新
	hol += GetMouseWheelRotVol();
}

//カーソル座標
Vector2D InputControll_Mouse::GetLocation() const
{
	return this->location;
}

bool InputControll_Mouse::GetClick(int click) const
{
	return CheckClikRange(click) && (now_click[click] && old_click[click]);
}

int InputControll_Mouse::GetWheel()const
{
	return this->hol;
}

bool InputControll_Mouse::CheckClikRange(int click)
{
	return (0 <= click && click < 3);
}

void InputControll_Mouse::Draw()
{
	//フォントサイズ
	SetFontSize(50);

	//クリック入力
	DrawFormatString(1, 1, GetColor(255,255,255), "%d",GetClick(0));
	DrawFormatString(1, 20, GetColor(255,255,255), "%d",GetClick(1));
	DrawFormatString(1, 40, GetColor(255, 255, 255), "%d", GetClick(2));

	//ホイール入力
	DrawFormatString(1, 60, GetColor(255, 255, 255), "%d", GetWheel());

	//カーソル座標取得
	DrawFormatString(1, 100, GetColor(255, 255, 255), "%.f", GetLocation().x);
	DrawFormatString(1, 120, GetColor(255, 255, 255), "%.f", GetLocation().y);
}