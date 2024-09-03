#include "TitleScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

TitleScene::TitleScene()
{

}

TitleScene::~TitleScene()
{

}

void TitleScene::Initialize()
{

}

eSceneType TitleScene::Update()
{
	//入力機能の取得
	InputControl* input = InputControl::GetInstance();

	//SPACEキーでインゲーム画面に遷移する
	if (input->GetKeyDown(KEY_INPUT_SPACE))
	{
 		return eSceneType::eInGame;
	}
	if (input->GetKeyDown(KEY_INPUT_S))
	{
		return eSceneType::eHelp;
	}
	if (input->GetKeyDown(KEY_INPUT_Q))
	{
		return eSceneType::eResult;
	}

	return GetNowSceneType();
}

void TitleScene::Draw() const
{
	DrawFormatString(10, 10, GetColor(255, 255, 255), "タイトル画面です");
	DrawFormatString(10, 30, GetColor(255, 255, 255), "スペースキーでInGameSceneに移動です");
	DrawFormatString(10, 50, GetColor(255, 255, 255), "SでHelpSceneに移動です");
	DrawFormatString(10, 70, GetColor(255, 255, 255), "QでResultSceneに移動です");
	DrawFormatString(10, 100, GetColor(255, 255, 255), "ESCキーで終了します");
}

void TitleScene::Finalize()
{

}
eSceneType TitleScene::GetNowSceneType() const
{
	return eSceneType::eTitle;
}