#include "Sprite/Player.h"

bool Player::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	SpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("player.plist");

	visibleSize = Director::getInstance()->getVisibleSize();

	initPlayer();
	movePlayer();

	return true;
}

void Player::initPlayer()
{
	player = Sprite::create();
	
	playerSF.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("player10.png"));
	playerSF.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("player11.png"));
	player->runAction(RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(playerSF, 0.1f))));
	
	playerLiftSF.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("player10_l.png"));
	playerLiftSF.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("player11_l.png"));
	//player->runAction(RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(playerLiftSF, 0.1f))));
	
	playerRightSF.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("player10_r.png"));
	playerRightSF.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("player11_r.png"));
	//player->runAction(RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(playerRightSF, 0.1f))));
	player->setAnchorPoint(Point::ZERO);
	addChild(player, 1);
}

void Player::movePlayer()
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
		player = static_cast<Sprite*>(pEvent->getCurrentTarget());

		if (pTouch->getDelta().x<0)
		{
			player->runAction(Repeat::create(Animate::create(Animation::createWithSpriteFrames(playerLiftSF, 0.5f)),1));
		}
		else if (pTouch->getDelta().x>0)
		{
			player->runAction(Repeat::create(Animate::create(Animation::createWithSpriteFrames(playerRightSF, 0.5f)), 1));
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
		/*auto target = static_cast<Sprite*>(pEvent->getCurrentTarget());
		target->setPosition(target->getPosition() + pTouch->getDelta());*/
	};
	listener->onTouchEnded = [=](Touch*pTouch, Event*pEvent){
		player->runAction(RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(playerSF, 0.1f))));
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

