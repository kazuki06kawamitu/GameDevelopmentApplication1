#include "InGameScene.h"
#include "../Player/Player.h"
#include "../Utility/InputControl.h"
#include "Dxlib.h"

InGameScene::InGameScene() : player(nullptr)
{

}

InGameScene::~InGameScene()
{

}

void InGameScene::Initialize()
{
	player = new Player();
	player->Initialize(Vector2D(320.0f, 400.0f));
}

void InGameScene::Finalize()
{
	player->Finalize();
	delete player;
}

eSceneType InGameScene::Update(float delta_second)
{
	player->Update();
	return GetNowSceneType();
}

void InGameScene::Draw() const
{
	player->Draw();
}

eSceneType InGameScene::GetNowSceneType() const
{
	return eSceneType::eInGame;
}