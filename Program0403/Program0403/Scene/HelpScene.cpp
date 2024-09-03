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
	//���͋@�\�̎擾
	InputControl* input = InputControl::GetInstance();

	//SPACE�L�[�ŃC���Q�[����ʂɑJ�ڂ���
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
	DrawFormatString(10, 30, GetColor(255, 255, 255), "�w���v��ʂł�");
	DrawFormatString(10, 50, GetColor(255, 255, 255), "�X�y�[�X�L�[��InGameScene�Ɉړ��ł�");
	DrawFormatString(10, 70, GetColor(255, 255, 255), "Z��TitleScene�Ɉړ��ł�");
	DrawFormatString(10, 90, GetColor(255, 255, 255), "Q��ResultScene�Ɉړ��ł�");
	DrawFormatString(10, 110, GetColor(255, 255, 255), "ESC�L�[�ŏI�����܂�");
}

void HelpScene::Finalize()
{

}
eSceneType HelpScene::GetNowSceneType() const
{
	return eSceneType::eHelp;
}