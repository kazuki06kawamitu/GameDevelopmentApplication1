#include "JumpingState.h"

#include "DxLib.h"
#include "../../Utility/InputControl.h"
#include "../Player.h"

///<summary>
///コンストラクタ
/// </summry>
/// <param name="p">プレイヤー情報</param>
JumpingState::JumpingState(class Player* p)
	: PlayerStateBase(p)
	, old_location(Vector2D(0.0f))
{

}

///<summary>
///デストラクタ
/// </summry>
JumpingState::~JumpingState()
{

}

///<summary>
///初期化処理
/// </summry>
void JumpingState::Initialize()
{
	this->player->velocity.y -= 15.0f;  //ジャンプ力
	old_location = 0.0f;
}

///<summary>
///終了処理
/// </summry>
void JumpingState::Finalize()
{

}

///<summary>
///更新処理
/// </summry>
void JumpingState::Update()
{
	//地面に触れたら
	if (old_location.y == player->GetLocation().y)
	{
		//左右入力があるなら
		//InputControl* input = InputControl::GetInstance();
		//if (input->GetKey(KEY_INPUT_A) || input->GetKey(KEY_INPUT_D))
		//{
		//	//移動状態に遷移
		//	player->SetNextState(ePlayerState::RUN);
		//}
		//else
		//{
		//	//停止状態に遷移
		//	player->SetNextState(ePlayerState::IDLE);
		//}
	}
	//前回座標の更新
	old_location = player->GetLocation();
}

///<summary>
///描画処理
/// </summry>
void JumpingState::Draw() const
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
ePlayerState JumpingState::GetState() const
{
	return ePlayerState::JUMP;
}