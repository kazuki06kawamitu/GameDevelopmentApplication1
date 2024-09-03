#include "InGameScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

InGameScene::InGameScene()
{

}

InGameScene::~InGameScene()
{

}

void InGameScene::Initialize()
{

}

eSceneType InGameScene::Update()
{
	//���͋@�\�̎擾
	InputControl* input = InputControl::GetInstance();

	//SPACE�L�[�ŃC���Q�[����ʂɑJ�ڂ���
	if (input->GetKeyDown(KEY_INPUT_S))
	{
		return eSceneType::eHelp;
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

void InGameScene::Draw() const
{
	DrawFormatString(10, 10, GetColor(255, 255, 255), "�C���Q�[����ʂł�");
	DrawFormatString(10, 30, GetColor(255, 255, 255), "S��HelpScene�Ɉړ��ł�");
	DrawFormatString(10, 50, GetColor(255, 255, 255), "Z��TitleScene�Ɉړ��ł�");
	DrawFormatString(10, 70, GetColor(255, 255, 255), "Q��ResultScene�Ɉړ��ł�");
	DrawFormatString(10, 90, GetColor(255, 255, 255), "ESC�L�[�ŏI�����܂�");
}

void InGameScene::Finalize()
{

}
eSceneType InGameScene::GetNowSceneType() const
{
	return eSceneType::eInGame;
}