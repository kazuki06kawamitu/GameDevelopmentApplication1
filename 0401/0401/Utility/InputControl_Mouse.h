#pragma once

#include"Vector2D.h"

//�}�E�X���̓N���X
class InputControll_Mouse
{
	//�N���X�|�C���^
	static InputControll_Mouse* instance;
private:
	bool now_click[3] = {};
	bool old_click[3] = {};
	int hol=0;
	Vector2D location = {};

private:
	InputControll_Mouse() = default;

	//�R�s�[�K�[�h
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