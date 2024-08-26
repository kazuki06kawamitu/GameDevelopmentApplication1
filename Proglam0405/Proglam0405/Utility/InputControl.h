#pragma once

//マクロ定義
#define D_KEYCODE_MAX (256)  //キーコード最大数

//入力制御クラス
class InputControl
{
private:
	//自クラスのポインタ(アドレスの先にインスタンスを生成する)
	static InputControl* instance;

	//キーボード入力値
	char now_key[D_KEYCODE_MAX];  //現在の入力値
	char old_key[D_KEYCODE_MAX];  //前回の入力値

private:
	//コンストラクタをprivateにすることで、
	//自クラスのメンバ関数でしかインスタンスを生成できないようにする
	InputControl();

	//コピーガード
	//クラス外でインスタンスを生成して渡すことができないようにする
	InputControl(InputControl& v) = default;
	InputControl& operator=(const InputControl& v) = default;
	//~コピーガード

public:
	~InputControl();

public:
	//インスタンス取得する処理
	static InputControl* GetInstance();
	//インスタンス削除する処理
	static void DeleteInstance();

public:
	//キー入力状態を取得する
	void Update();

	//きー入力状態を取得しる
	bool GetKey(int key_code)const; //押している間
	bool GetKeyDown(int key_code)const; //押した瞬間
	bool GetKeyUp(int key_code) const;  //離した瞬間

private:
	//キー入力の周囲を確認
	bool CheckKeyCodeRange(int key_code) const;
};