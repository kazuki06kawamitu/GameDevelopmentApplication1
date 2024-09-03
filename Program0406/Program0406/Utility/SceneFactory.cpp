#include "SceneFactory.h"
#include "../Scene/SceneBase.h"
#include "../Scene/InGameScene.h"

SceneBase* SceneFactory::CreateScene(eSceneType scene)
{
	switch (scene)
	{
	case eInGame:
		return dynamic_cast<SceneBase*>(new InGameScene());
	case eTitle:
	case eResult:
	case eEnd:
	default:
		return nullptr;
	}
}