#include "InGameScene.h"

#include"../Player/Player.h"
#include"DxLib.h"

InGameScene::InGameScene() : player(nullptr)
{

}
InGameScene::~InGameScene()
{

}

void InGameScene::Initialize()
{
	__super::Initialize();

	player = new Player();
	player -> Initialize();
}

eSceneType InGameScene::Update(float delete_second)
{
	//プレイヤーの更新
	player->Update(delete_second);

	//入力イベントの実行
	input_event->InputActionEvent();

	return GetNowSceneType();
}

void InGameScene::Draw() const
{
	player->Draw();
}

void InGameScene::Finalize()
{
	player->Finalize();
	delete player;

	__super::Finalize();
}

eSceneType InGameScene::GetNowSceneType() const
{
	return eSceneType::eInGame;
}