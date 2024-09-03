#include "ResultScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

ResultScene::ResultScene()
{

}

ResultScene::~ResultScene()
{

}

void ResultScene::Initialize()
{

}

eSceneType ResultScene::Update()
{
	//入力機能の取得
	InputControl* input = InputControl::GetInstance();

	//SPACEキーでインゲーム画面に遷移する
	if (input->GetKeyDown(KEY_INPUT_S))
	{
		return eSceneType::eHelp;
	}
	if (input->GetKeyDown(KEY_INPUT_Z))
	{
		return eSceneType::eTitle;
	}
	if (input->GetKeyDown(KEY_INPUT_SPACE))
	{
		return eSceneType::eInGame;
	}

	return GetNowSceneType();
}

void ResultScene::Draw() const
{
	DrawFormatString(10, 10, GetColor(255, 255, 255), "リザルト画面です");
	DrawFormatString(10, 30, GetColor(255, 255, 255), "SでHelpSceneに移動です");
	DrawFormatString(10, 50, GetColor(255, 255, 255), "ZでTitleSceneに移動です");
	DrawFormatString(10, 70, GetColor(255, 255, 255), "スペースでInGameSceneに移動です");
	DrawFormatString(10, 90, GetColor(255, 255, 255), "ESCキーで終了します");
}

void ResultScene::Finalize()
{

}
eSceneType ResultScene::GetNowSceneType() const
{
	return eSceneType::eResult;
}