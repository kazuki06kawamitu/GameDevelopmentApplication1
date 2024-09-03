#include "RunState.h"

#include "DxLib.h"
#include "../../Utility/InputControl.h"
#include "../Player.h"

///<summary>
///コンストラクタ
/// </summry>
/// <param name="p">プレイヤー情報</param>
RunState::RunState(class Player* p)
	: PlayerStateBase(p)
	,input(nullptr)
	, speed(0.0f)
{

}

///<summary>
///デストラクタ
/// </summry>
RunState::~RunState()
{

}

///<summary>
///初期化処理
/// </summry>
void RunState::Initialize()
{
	//Boxsizeの設定
	player->box_size = Vector2D(32.0f);

	//速度を0に初期化
	player->velocity = 0.0f;

	//入力情報を習得
	input = InputControl::GetInstance();

	//加速度加算数値
	speed = 70.0f;
}

///<summary>
///終了処理
/// </summry>
void RunState::Finalize()
{

}

///<summary>
///更新処理
/// </summry>
void RunState::Update()
{
	//加速度計算処理
	if (input->GetKey(KEY_INPUT_A))
	{
		player->velocity.x -= speed;
	}
	if (input->GetKey(KEY_INPUT_D))
	{
		player->velocity.x += speed;
	}

	//座標取得
	Vector2D location_end = (player->GetLocation() + player->velocity.x);

	//画面端に触れたら
	if (location_end.x <(0.0f))
	{
		//停止状態に遷移
		player->velocity.x=0.0f;
	}
	else if (location_end.x > (640.0f - player->box_size.x))
	{
		//停止状態に遷移
		player->velocity.x = 0.0f;
	}
	//ジャンプ状態に遷移
	if (input->GetKeyDown(KEY_INPUT_SPACE))
	{
		//停止状態に遷移
		player->SetNextState(ePlayerState::JUMP);
	}

	//停止状態
	if (!(input->GetKey(KEY_INPUT_A)) || !(input->GetKey(KEY_INPUT_D)))
	{
		player->SetNextState(ePlayerState::IDLE);
	}
}

///<summary>
///描画処理
/// </summry>
void RunState::Draw() const
{
	//座標情報を整数値に変換
	int x = 0, y = 0;
	player->GetLocation().ToInt(&x, &y);

	//描画
	DrawBox(x, y, x + (int)(player->box_size.x), y + (int)(player->box_size.y),
		GetColor(0, 0, 255), FALSE);
}

///<summary>
///現在のステート情報を取得する
/// </summry>
/// <return>現在のステート情報</return>
ePlayerState RunState::GetState() const
{
	return ePlayerState::RUN;
}