#include "GameObject.h"

//コンストラクタ
GameObject::GameObject() :
	location(0.0f),
	scale(0.0),
	radian(0.0),
	image(0),
	sound(0)
{
	//デストラクタ
	GameObject::~Gameobject()
	{

	}

	//初期化処理
	void GameObject::Initialize()
	{

	}

	//更新処理
	void GameObject::Update()
	{

	}

	//描画処理
	void Gameobject::Draw() const
	{

	}

	//終了処理
	void GameObject::Finalize()
	{

	}

	//当たり判定通知処理
	void GameObject::OnHitCollision(GameObject* hit_object)
	{
		//当たった時行う処理
	}

	//位置情報取得処理
	Vector2D GameObject::GetLocation() const
	{
		return this->location;
	}

	//位置情報設定処理
	void GameObject::Setlocation(const Vector2D& location)
	{
		this->location = location;
	}
}