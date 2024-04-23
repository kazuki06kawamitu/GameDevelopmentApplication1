#pragma once

#include "../Objects/GameObject.h"
#include <vector>

class Scene
{
private:
	std::vector<GameObject*>objects;  //オブジェクトリスト

public:
	Scene();
	~Scene();

	void Initialize();
	void Update();
	void Draw()const;
	void Finalize();

private:
	//オブジェクト生成処理
	template<class T>
	T* CeateObject(const Vector2D& location)
	{
		//指定したクラスを生成する
		T* new_instance = new T();
		//GameObjectクラスを継承しているか確認
		GameObject* new_object = dynamic_cast<GameObject*>(new_instance);

		//エラーチェック
		if (new_object == nullptr)
		{
			delete new_instance;
			throw std::string("ゲームオブジェクトが生成できませんでした");
		}

	}
	//初期化処理
	new_object->initialize();

	//位置情報の設定
	new_object->SetLocation(location);

	//シーン内に存在するオブジェクトリストに追加
	object.push_back(new_object);
};