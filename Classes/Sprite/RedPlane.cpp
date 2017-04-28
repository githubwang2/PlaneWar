#include "Sprite/RedPlane.h"

bool RedPlane::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	SpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("player.plist");

	visibleSize = Director::getInstance()->getVisibleSize();

	createPlayerRed();
	movePlayer();

	return true;
}

void RedPlane::createPlayer()
{
	player = Sprite::create();
	Vector<SpriteFrame*> playerSF;
	playerSF.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("player10.png"));
	playerSF.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("player11.png"));
	player->runAction(RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(playerSF, 0.1f))));
	addChild(player, 1);
}

void RedPlane::movePlayer()
{

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [=](Touch*pTouch, Event*pEvent)
	{
		return true;
	};
	listener->onTouchMoved = [=](Touch*pTouch, Event*pEvent)
	{
		//ÔÝÍ£Ê±²»ÒÆ¶¯
		if (Director::getInstance()->isPaused())
		{
			return;
		}
		auto newPos = player->getPosition() + pTouch->getDelta();
		Size planeSize = player->boundingBox().size;
		if (newPos.x > visibleSize.width - planeSize.width / 2)
		{
			newPos.x = visibleSize.width - planeSize.width / 2;
		}
		else if (newPos.x < planeSize.width / 2)
		{
			newPos.x = planeSize.width / 2;
		}

		if (newPos.y > visibleSize.height - planeSize.height / 2) {
			newPos.y = visibleSize.height - planeSize.height / 2;
		}
		else if (newPos.y < planeSize.height / 2)
		{
			newPos.y = planeSize.height / 2;
		}
		player->setPosition(newPos);
		//auto target = static_cast<Sprite*>(pEvent->getCurrentTarget());
		//target->setPosition(target->getPosition() + pTouch->getDelta());
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}
