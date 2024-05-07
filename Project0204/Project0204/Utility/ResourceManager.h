#pragma once

#include <map>
#include <string>
#include <vector>

class ResourceManager
{
private:
	//�ǂݍ��񂾉摜��ۑ����Ă����X�g
	std::map < std::string, std::vector<int>> image_container;

public:
	ResourceManager();//�q�R���g���N�^
	~ResourceManager();//�f�X�g���N�^
	//�p�X�̉摜��ǂݍ���ŕԂ� �P��摜
	const std::vector<int>& GetImages(std::string file_path);
	//�p�X�̉摜��ǂݍ���ŕԂ� �����摜
	const std::vector<int>& GetImages(std::string file_path, int all_num, int x_num,
		int y_num, int x_size, int y_size);
	
	//�ǂݍ��񂾉摜�̑S�폜
	void DeleteImages();
};

ResourceManager* GetResourceManager();