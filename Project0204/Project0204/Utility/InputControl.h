#pragma once

#define D_KEYCODE_MAX (256) //キーボードコードの総数

class InputControl
{
private:
	static char now_Key[D_KEYCODE_MAX];  //新しく入力したときのキーボードキー
	static char old_Key[D_KEYCODE_MAX];  //入力し終わった後のキーボードキー

public:
	static void Update();//更新処理

	static bool GetKey(int Key_code);//押している情報取得
	static bool GetKeyDown(int key_code);//押したフレーム情報取得
	static bool GetKeyUp(int Key_code);//離したフレーム情報取得

private:
	//キーコードの有効範囲内チェック（整数型でキーコードの範囲内を調べる）
	static bool CheckKeyCodeRange(int Key_code);

};