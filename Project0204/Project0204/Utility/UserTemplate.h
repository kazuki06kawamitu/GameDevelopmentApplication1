#pragma once
//��Βl�ɕϊ�
template <typename T>
T Abs(T value)//�����̐������Βl�ɕϊ�����
{
	T result;
	if (value > 0)
	{
		result = value;//���̐��̎�
	}
	else
	{
		result = -value;//���̐��̎�
	}
	return result;
}
//�ő�l��Ԃ��e���v���[�g�֐�
template<typename T>
T Max(T a, T b)//�����Ŏw�肳�ꂽ��̒l�̍ő�l�����Ԃ�
{
	T result;
	//�l���傫������result��
	if (a < b)
	{
		result = b;
	}
	else
	{
		result = a;
	}

	return result;
}
//�ŏ��l��Ԃ��e���v���[�g�֐�
template<typename T>
T Min(T a, T b)//�����Ŏw�肳�ꂽ��̒l�̍ŏ��l�����Ԃ�
{
	T result;
	//�l���������@��result��
	if (a > b)
	{
		result = b;
	}
	else
	{
		result = a;
	}
	return result;
}