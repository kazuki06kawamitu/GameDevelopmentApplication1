#include "ResourceManager.h"
#include "DxLib.h"

ResourceManager resource_manager;

ResourceManager* GetResourceManager()
{
	return &resource_manager;
}

ResourceManager::ResourceManager() :image_container()
{
}

ResourceManager::~ResourceManager()
{

}

const std::vector<int>& ResourceManager::GetImages(std::string file_path)
{
	if (image_container.count(file_path) == NULL)
	{
		int handle = loadGraph(file_path.c_str());

		if (handle == -1)
		{
			throw(file_path + "‚Ì‰æ‘œ‚ª“Ç‚İ‚ß‚Ü‚¹‚ñ‚Å‚µ‚½");
		}
		image_container[file_path].push_back(handle);
	}
}

const std::vector<int>& ResourceManager::GetImages(std::string file_path, int all_num,
	int x_num, int  y_num, int x_size, int y_size)
{
	if (image_container.count(file_path) == NULL)
	{
		int* handle = new int[all_num];

		int result = LoadDivGraph(file_path.c_str(), all_num, x_num, y_num,
			x_num, y_num, handle);
		if (result == -1)
		{
			throw(file_path + "‚Ì‰æ‘œ‚ª“Ç‚İ‚İ‚Ü‚¹‚ñ‚Å‚µ‚½");
		}
		delete[] handle;
	}
	return image_container[file_path];
}

void ResourceManager::DeleteImage
{
	if (image_container.size() == NULL)
	{
		return;
	}

    for (std::pair < std::string, std::vector<int>value : image_container)
   {
	DeleteSharingGraph(value.secound[0]);
	value.second.clear();
   }
image_container.clear();
}