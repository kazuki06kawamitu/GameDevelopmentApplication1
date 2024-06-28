#pragma once

#include <vector>
//#include <string>
#include "../Objects/GameObject.h"

#define D_FREAME (144)
class Scene
{
private:
	int back_ground_image;
	std::vector<GameObject*>objects;
	int time;
	int tc;
	int ui_image[10];
	int score;

public:
	Scene();
	~Scene();

	void Initialize();
	void Update();
	void Draw()const;
	void Finalize();
	void Spown();
	void CountTimer();
	void Score();

private:
	//当たり判定チェック処理
	void HitCheckObject(GameObject* a, GameObject* b);
	//オブジェクト生成処理
	template<class T>
	T* CreateObject(const Vector2D& location)
	{
		//指定したクラスを生成する
		T* new_instance = new T();
		//GameObjectクラスを継承しているか確認
		GameObject* new_object = dynamic_cast<GameObject*>(new_instance);

		//エラーチェック
		if (new_object == nullptr)
		{
			delete new_instance;
			throw ("GameObjectが生成できませんでした\n");
		}

		//初期化処理
		new_object->Initialize();

		//位置情報の設定
		new_object->SetLocation(location);

		//シーン内に存在するオブジェクトに追加
		objects.push_back(new_object);

		//生成したオブジェクトのポインタを返却
		return new_instance;

	}
};