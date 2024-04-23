#pragma once
//絶対値に変換
template <typename T>
T Abs(T value)//引数の数字を絶対値に変換する
{
	T result;
	if (value > 0)
	{
		result = value;//正の数の時
	}
	else
	{
		result = -value;//負の数の時
	}
	return result;
}
//最大値を返すテンプレート関数
template<typename T>
T Max(T a, T b)//引数で指定された二つの値の最大値えお返す
{
	T result;
	//値が大きい方をresultに
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
//最小値を返すテンプレート関数
template<typename T>
T Min(T a, T b)//引数で指定された二つの値の最小値えお返す
{
	T result;
	//値が小さい法をresultに
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