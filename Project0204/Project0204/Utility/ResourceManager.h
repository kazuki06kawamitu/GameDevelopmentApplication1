#pragma once

#include <map>
#include <string>
#include <vector>

class ResourceManager
{
private:
	//読み込んだ画像を保存していつリスト
	std::map < std::string, std::vector<int>> image_container;

public:
	ResourceManager();//子コントラクタ
	~ResourceManager();//デストラクタ
	//パスの画像を読み込んで返す 単一画像
	const std::vector<int>& GetImages(std::string file_path);
	//パスの画像を読み込んで返す 分割画像
	const std::vector<int>& GetImages(std::string file_path, int all_num, int x_num,
		int y_num, int x_size, int y_size);
	
	//読み込んだ画像の全削除
	void DeleteImages();
};

ResourceManager* GetResourceManager();