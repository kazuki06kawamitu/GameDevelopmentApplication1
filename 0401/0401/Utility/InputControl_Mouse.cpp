#include"InputControl_Mouse.h"
#include "DxLib.h"

//�N���X�̃C���X�^���X���擾����
InputControll_Mouse* InputControll_Mouse::instance = nullptr;

//���͐���N���X�̃C���X�^���X���擾����
InputControll_Mouse* InputControll_Mouse::Getinsatance()
{
	//�C���X�^���X��������ΐ�������
	if (instance == nullptr)
	{
		instance == new InputControll_Mouse();
	}

	//�|�C���^��ԋp����
	return instance;
}

//���͐���N���X�̃C���X�^���X���폜
void InputControll_Mouse::DeleteInstance()
{
	//�C���X�^���X��������΍폜����
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

//�X�V����
void InputControll_Mouse::Update()
{
	//�}�E�X�J�[�\���\��
	SetMouseDispFlag(TRUE);

	//�}�E�X�J�[�\�����W�K��
	int x, y = 0;
	GetMousePoint(&x, &y);
	this->location.x = x;
	this->location.y = y;

	//���͏��X�V
	for (int i = 0; i < 3; i++)
	{
		old_click[i] = now_click[i];
		now_click[i] = FALSE;
	}
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		now_click[0] = TRUE;
	}
	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0)
	{
		now_click[1] = TRUE;
	}
	if ((GetMouseInput() & MOUSE_INPUT_MIDDLE) != 0)
	{
		now_click[2] = TRUE;
	}
	//�z�C�[�����͏�ԍX�V
	hol += GetMouseWheelRotVol();
}

//�J�[�\�����W
Vector2D InputControll_Mouse::GetLocation() const
{
	return this->location;
}

bool InputControll_Mouse::GetClick(int click) const
{
	return CheckClikRange(click) && (now_click[click] && old_click[click]);
}

int InputControll_Mouse::GetWheel()const
{
	return this->hol;
}

bool InputControll_Mouse::CheckClikRange(int click)
{
	return (0 <= click && click < 3);
}

void InputControll_Mouse::Draw()
{
	//�t�H���g�T�C�Y
	SetFontSize(50);

	//�N���b�N����
	DrawFormatString(1, 1, GetColor(255,255,255), "%d",GetClick(0));
	DrawFormatString(1, 20, GetColor(255,255,255), "%d",GetClick(1));
	DrawFormatString(1, 40, GetColor(255, 255, 255), "%d", GetClick(2));

	//�z�C�[������
	DrawFormatString(1, 60, GetColor(255, 255, 255), "%d", GetWheel());

	//�J�[�\�����W�擾
	DrawFormatString(1, 100, GetColor(255, 255, 255), "%.f", GetLocation().x);
	DrawFormatString(1, 120, GetColor(255, 255, 255), "%.f", GetLocation().y);
}