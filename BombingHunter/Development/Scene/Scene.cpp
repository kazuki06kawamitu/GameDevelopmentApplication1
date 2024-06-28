#include "Scene.h"


#include "../Objects/Player/Player.h"
#include "../Objects/Weapon/Bomb.h"
#include "../Objects/Weapon/Blast.h"
#include "../Objects/Enemy/Enemy.h"
#include "../Objects/Enemy/WingEnemy.h"
#include "../Objects/Enemy/Harpy.h"
#include "../Objects/Enemy/GoldEnemy.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

#define D_PIVOT_CENTER

//コンストラクタ
Scene::Scene() : objects(), back_ground_image(NULL),time(60), tc(0),ui_image(), score()
{
	
}

//デストラクタ
Scene::~Scene()
{
	//忘れ防止
	Finalize();
}

//初期化処理
void Scene::Initialize()
{
	
	//プレイヤーを生成する
	CreateObject<Player>(Vector2D(320.0f, 65.0f));
	ui_image[0] = LoadGraph("Resource/Images/Score/0.png");
	ui_image[1] = LoadGraph("Resource/Images/Score/1.png");
	ui_image[2] = LoadGraph("Resource/Images/Score/2.png");
	ui_image[3] = LoadGraph("Resource/Images/Score/3.png");
	ui_image[4] = LoadGraph("Resource/Images/Score/4.png");
	ui_image[5] = LoadGraph("Resource/Images/Score/5.png");
	ui_image[6] = LoadGraph("Resource/Images/Score/6.png");
	ui_image[7] = LoadGraph("Resource/Images/Score/7.png");
	ui_image[8] = LoadGraph("Resource/Images/Score/8.png");
	ui_image[9] = LoadGraph("Resource/Images/Score/9.png");

	back_ground_image = LoadGraph("Resource/Images/BackGround.png");
	
}

//更新処理
void Scene::Update()
{
	//シーンに存在するオブジェクトの更新処理
	for (GameObject* obj : objects)
	{
		obj->Update();

	}

	Spown();
	CountTimer();
	//オブジェクト同市の当たり判定チェック
	for (int i = 0; i < objects.size(); i++)
	{
		for (int j = i + 1; j < objects.size(); j++)
		{
			//当たり判定チェック処理
			HitCheckObject(objects[i], objects[j]);
		}
		if (objects[i]->DeleteObject() == TRUE)
		{
			this->objects.erase(objects.begin() + i);
		}
	}

	//Zキーを押したら、敵の攻撃をだす
	if (InputControl::GetKeyDown(KEY_INPUT_Z))
	{

		Vector2D enemy = objects[1]->GetLocation();
		Blast* blast = CreateObject<Blast>(Vector2D(enemy.x, enemy.y));

		blast->SetDirection(objects[0]->GetLocation());

	}

	//
	if (InputControl::GetKeyDown(KEY_INPUT_SPACE))
	{
		Vector2D player = objects[0]->GetLocation();
		CreateObject<Bomb>(Vector2D(player.x, 130.0));
	}

	
}

//描画処理
void Scene::Draw()const
{

	

	//背景の角度
	DrawRotaGraph(320, 240, 0.67,0.0f, back_ground_image, TRUE,FALSE);
	//
	
	//シーンに存在するオブジェクトの描画処理
	for (GameObject* obj : objects)
	{
		obj->Draw();
	

	}
}

//ランダムに敵を出現させる
void Scene::Spown()
{
	int spownenemy = GetRand(6);
	int loc_y = GetRand(1);
	int flip = FALSE;

	
	int spowncount = rand() % 100 + 1;
	if (spowncount <= 1)
	{
		switch (spownenemy)
		{
		case 0:
			CreateObject<Enemy>(Vector2D(100.0f, 400.0f));
			break;
		case 1:
			CreateObject<Enemy>(Vector2D(500.0f, 400.0f));
			break;

		case 2:
			CreateObject<WingEnemy>(Vector2D(100.f, 250.0f + (loc_y * 100)));
			break;

		case 3:
			CreateObject<WingEnemy>(Vector2D(500.f, -250.0f + (loc_y * 100)));
			break;

		case 4:
			CreateObject<Harpy>(Vector2D(100.0f, 150.0f + (loc_y * 100)));
			break;
		case 5:
			CreateObject<Harpy>(Vector2D(500.0f, -150.0f + (loc_y * 100)));
			break;
		default:
			//CreateObject<GoldEnemy>(Vector2D(100.0f, 400.0f));
			break;
		}
	}
		

}

//制限時間を追加
void Scene::CountTimer()
{
	tc++;
	if (tc >= D_FREAME)
	{
		time--;
		tc = 0;
	}
}

void Scene::Score()
{
	for (int i = 0; i < objects.size(); i++)
	{

	}
}

//終了時処理
void Scene::Finalize()
{
	//動的配列が空なら処理を終了する
	if (objects.empty())
	{
		return;
	}

	//各オブジェクトを削除する
	for (GameObject* obj : objects)
	{
		obj->Finalize();
		delete obj;
	}
	//動的配列の解放
	objects.clear();
}

#ifdef D_PIVOT_CENTER

//当たり判定チェック処理（短形の中心で当たり判定を取る）
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//2つのオブジェクトの距離を取得
	Vector2D diff = a->GetLocation() - b->GetLocation();

	//2つのオブジェクトの当たり判定の大きさを取得
	Vector2D box_size = (a->GetBoxSize() + b->GetBoxSize()) / 2.0f;

	if (a->GetObjectFlag() != b->GetObjectFlag())
	{
		//距離より大きさが大きい場合、Hit判定とする
	if ((fabsf(diff.x) < box_size.x) && (fabsf(diff.y) < box_size.y))
		{
			//当たったことをオブジェクトに通知する
			a->OnHitCollision(b);
  			b->OnHitCollision(a);

		}
		
	}
	
}
#else

//当たり判定チェック処理(左上頂点の座標から当たり判定計算を行う)
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//右下頂点座標を取得する
	Vector2D a_lower_right = a->GetLocation() + a->GetBoxSize();
	Vector2D b_lower_right = b->GetLocation() + b->GetBoxSize();

	//短形Aと短形Bの位置関係を調べる
	if ((a->GetLocation().x < b_lower_right.x) &&
		(a->GetLocation().y < b_lower_right.y) &&
		(a_lower_right.x > b->GetLocation().x) &&
		(a_lower_right.y > b->GetLocation().y))
	{
		//オブジェクトに対してHit判定を通知する
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}
#endif // D_PIVOT_CENTER
