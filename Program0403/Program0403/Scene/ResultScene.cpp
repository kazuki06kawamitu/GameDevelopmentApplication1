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
	if (input->GetKeyDown(KEY_INPUT_SPACE))
	{
		return eSceneType::eInGame;
	}

	return GetNowSceneType();
}

void ResultScene::Draw() const
{
	DrawFormatString(10, 10, GetColor(255, 255, 255), "���U���g��ʂł�");
	DrawFormatString(10, 30, GetColor(255, 255, 255), "S��HelpScene�Ɉړ��ł�");
	DrawFormatString(10, 50, GetColor(255, 255, 255), "Z��TitleScene�Ɉړ��ł�");
	DrawFormatString(10, 70, GetColor(255, 255, 255), "�X�y�[�X��InGameScene�Ɉړ��ł�");
	DrawFormatString(10, 90, GetColor(255, 255, 255), "ESC�L�[�ŏI�����܂�");
}

void ResultScene::Finalize()
{

}
eSceneType ResultScene::GetNowSceneType() const
{
	return eSceneType::eResult;
}