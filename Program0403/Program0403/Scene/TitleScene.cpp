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
	//���͋@�\�̎擾
	InputControl* input = InputControl::GetInstance();

	//SPACE�L�[�ŃC���Q�[����ʂɑJ�ڂ���
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
	DrawFormatString(10, 10, GetColor(255, 255, 255), "�^�C�g����ʂł�");
	DrawFormatString(10, 30, GetColor(255, 255, 255), "�X�y�[�X�L�[��InGameScene�Ɉړ��ł�");
	DrawFormatString(10, 50, GetColor(255, 255, 255), "S��HelpScene�Ɉړ��ł�");
	DrawFormatString(10, 70, GetColor(255, 255, 255), "Q��ResultScene�Ɉړ��ł�");
	DrawFormatString(10, 100, GetColor(255, 255, 255), "ESC�L�[�ŏI�����܂�");
}

void TitleScene::Finalize()
{

}
eSceneType TitleScene::GetNowSceneType() const
{
	return eSceneType::eTitle;
}