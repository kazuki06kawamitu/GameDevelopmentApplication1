#pragma once

#define D_KEYCODE_MAX (256)  //キーの入力範囲

//キーの入力状態
enum class eInputState : unsigned char
{
	None,
	Pressed,
	Released,
	Held,
};

//入力管理クラス
class InputManager
{
private:
	//キーボード入力値
	char old_key[D_KEYCODE_MAX] = {};  //前回入力値
	char now_key[D_KEYCODE_MAX] = {};  //現在入力値

private:
	InputManager() = default;
	InputManager(const InputManager&) = delete;
	InputManager& operator=(const InputManager&) = delete;
	~InputManager() = default;

public:
	//インスタンス取得
	static InputManager* Get();

public:
	//更新処理
	void Update();

public:
	//入力状態を取得する
	eInputState GetKeyState(int keycode) const;

private:
	//キーコード範囲内チェック
	bool CheckKeycodeRange(int keycode)const;
};