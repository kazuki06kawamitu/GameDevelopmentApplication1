#include "Vector2D.h"
#include <math.h>
//コンストラクタ処理
Vector2D::Vector2D() : x(0.0f), y(0.0f)
{
}
//コンストラクタ処理
Vector2D::Vector2D(float scalar) :x(scalar), y(scalar)
{
}
//コンストラクタ処理
Vector2D::Vector2D(float mx, float my) :x(mx), y(my)
{
}
//デストラクタ処理
Vector2D::~Vector2D()
{
}
//代入の 演算子オーバーロード
Vector2D& Vector2D::operator=(const Vector2D& loction)
{
	this->x = loction.x;
	this->y = loction.y;

	return *this;
}
//加算の 演算子オーバーロード
const Vector2D Vector2D::operator+(const Vector2D& loction)const
{
	Vector2D result = Vector2D(0.0f);

	result.x = this->x + loction.x;
	result.y = this->y + loction.y;

	return result;
}
//加算代入 演算子オーバーロード
Vector2D& Vector2D::operator+=(const Vector2D& loction)
{
	this->x += loction.x;
	this->y += loction.y;

	return *this;
}
//減算 演算子オーバーロード
const Vector2D Vector2D::operator-(const Vector2D& loction)const
{
	Vector2D result = Vector2D(0.0f);
	result.x = this->x - loction.x;
	result.y = this->y - loction.y;
	return result;
}
//減算代入 演算子オーバーロード
Vector2D& Vector2D::operator-=(const Vector2D& loction)
{
	this->x -= loction.x;
	this->y -= loction.y;

	return *this;
}
//乗算 演算子オーバーロード
const Vector2D Vector2D::operator*(const float& scalar) const
{
	Vector2D result = Vector2D(0.0f);

	result.x = this->x * scalar;
	result.y = this->y * scalar;

	return result;
}
//乗算 演算子オーバーロード
const Vector2D Vector2D::operator*(const Vector2D& location) const
{
	Vector2D result = Vector2D(0.0f);

	result.x = this->x * location.x;
	result.y = this->y * location.y;

	return result;
}
//乗算代入 演算子オーバーロード
Vector2D& Vector2D::operator*=(const float& scalar)
{
	this->x *= scalar;
	this->y *= scalar;

	return *this;
}
//乗算代入 演算子オーバーロード
Vector2D& Vector2D::operator*=(const Vector2D& location)
{
	this->x *= location.x;
	this->y *= location.y;

	return *this;
}
//除算 演算子オーバーロード
const Vector2D Vector2D::operator/(const float& scalar) const

{
	if (Abs(scalar) < 1e-6f)
	{
		return Vector2D(0.0f);
	}
	return Vector2D(this->x / scalar, this->y / scalar);
}
//除算 演算子オーバーロード
const Vector2D Vector2D::operator/(const Vector2D& location) const
{
	if ((Abs(location.x) < 1e-6f) || (Abs(location.y) < 1e-6f))
	{
		return Vector2D(0.0f);
	}
	return Vector2D(this->x / location.x, this->y / location.y);
}
//除算代入 演算子オーバーロード
Vector2D& Vector2D::operator/=(const float& scalar)
{
	if (Abs(scalar) < 1e-6f)
	{
		this->x = 0.0f;
		this->y = 0.0f;
	}
	else
	{
		this->x /= scalar;
		this->y /= scalar;
	}
	return *this;
}
//除算代入 演算子オーバーロード
Vector2D& Vector2D::operator/=(const Vector2D& location)
{
	if ((Abs(location.x) < 1e-6f) || (Abs(location.y) < 1e-6f))
	{
		this->x = 0.0f;
		this->y = 0.0f;
	}
	else
	{
		this->x /= location.x;
		this->y /= location.y;
	}
	return *this;
}
//整数型データに変換
void Vector2D::ToInt(int* x, int* y)const
{
	*x = static_cast<int>(this->x);
	*y = static_cast<int>(this->y);
}