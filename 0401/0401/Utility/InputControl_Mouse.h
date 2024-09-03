#pragma once

#include"Vector2D.h"

//マウス入力クラス
class InputControll_Mouse
{
	//クラスポインタ
	static InputControll_Mouse* instance;
private:
	bool now_click[3] = {};
	bool old_click[3] = {};
	int hol=0;
	Vector2D location = {};

private:
	InputControll_Mouse() = default;

	//コピーガード
	InputControll_Mouse(InputControll_Mouse& v) = delete;
	InputControll_Mouse& operator=(InputControll_Mouse& v) = delete;

public:
	~InputControll_Mouse() = default;

public:
	static InputControll_Mouse* Getinsatance();

	static  void DeleteInstance();


public:
	void Update();

	Vector2D GetLocation()const;

	bool GetClick(int click)const;

	int GetWheel()const;

	void Draw();

private:
	static bool CheckClikRange(int click);
};