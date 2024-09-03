#include "HelpScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

HelpScene::HelpScene()
{

}

HelpScene::~HelpScene()
{

}

void HelpScene::Initialize()
{

}

eSceneType HelpScene::Update()
{
	//入力機能の取得
	InputControl* input = InputControl::GetInstance();

	//SPACEキーでインゲーム画面に遷移する
	if (input->GetKeyDown(KEY_INPUT_SPACE))
	{
		return eSceneType::eInGame;
	}
	if (input->GetKeyDown(KEY_INPUT_Z))
	{
		return eSceneType::eTitle;
	}
	if (input->GetKeyDown(KEY_INPUT_Q))
	{
		return eSceneType::eResult;
	}

	return GetNowSceneType();
}

void HelpScene::Draw() const
{
	DrawFormatString(10, 30, GetColor(255, 255, 255), "ヘルプ画面です");
	DrawFormatString(10, 50, GetColor(255, 255, 255), "スペースキーでInGameSceneに移動です");
	DrawFormatString(10, 70, GetColor(255, 255, 255), "ZでTitleSceneに移動です");
	DrawFormatString(10, 90, GetColor(255, 255, 255), "QでResultSceneに移動です");
	DrawFormatString(10, 110, GetColor(255, 255, 255), "ESCキーで終了します");
}

void HelpScene::Finalize()
{

}
eSceneType HelpScene::GetNowSceneType() const
{
	return eSceneType::eHelp;
}