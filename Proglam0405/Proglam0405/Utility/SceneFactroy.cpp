#include "SceneFactroy.h"
#include "../Scene/SceneBase.h"
#include "../Scene/InGameScene.h"

SceneBase* SceneFactory::CreateScene(eSceneType scene)
{
	switch (scene)
	{
	case eTitle:
		break;

	case eInGame:
		return new InGameScene();

	case eResult:
		break;

	case eEnd:
		break;

	default:
		break;
	}
	return nullptr;
}