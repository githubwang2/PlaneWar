#include "Scene/PlaneWarScene.h"

void PlaneWarScene::run()
{
	auto layer = PlaneWarLayer::create();
	if (nullptr != layer)
	{
		this->addChild(layer);
		Director::getInstance()->runWithScene(this);
	}
}

bool PlaneWarScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	run();
	return true;
}

