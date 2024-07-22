#pragma once
class Vector2D
{
public:
	float x = 0.0f;
	float y = 0.0f;

public:
	Vector2D() = default;
	Vector2D(float scalar);
	Vector2D(float mx, float my);

	~Vector2D();

public:
	//代入の 演算子オーバーロード
	Vector2D& operator=(const Vector2D& loction);
	//加算の 演算子オーバーロード
	const Vector2D operator+(const Vector2D& location) const;
	//加算代入 演算子オーバーロード
	Vector2D& operator+=(const Vector2D& location);
	//減算 演算子オーバーロード
	const Vector2D operator-(const Vector2D& location) const;
	//減算代入 演算子オーバーロード
	Vector2D& operator-=(const Vector2D& location);
	//乗算 演算子オーバーロード
	const Vector2D operator * (const float& scalar) const;
	const Vector2D operator * (const Vector2D& location) const;
	//乗算代入 演算子オーバーロード
	Vector2D& operator*=(const float& scalar);
	Vector2D& operator*=(const Vector2D& location);
	//除算 演算子オーバーロード
	const Vector2D operator/(const float& scalar)const;
	const Vector2D operator/(const Vector2D& location)const;
	//除算代入 演算子オーバーロード
	Vector2D& operator/=(const float& scalar);
	Vector2D& operator/=(const Vector2D& location);
	//整数型データに変換（xとy成分を整数型に変換して、対応する引数に代入する）
	void ToInt(int* x, int* y)const;
  };