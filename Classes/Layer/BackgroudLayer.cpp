#include "Layer/BackgroudLayer.h"

bool BackgroudLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	visibleSize = Director::getInstance()->getWinSize();


	addBackgroud();
	this->schedule(schedule_selector(BackgroudLayer::moveBackground, 0.1f));

	return true;
}

void BackgroudLayer::addBackgroud()
{
	bg1 = Sprite::create("game_background.jpg");
	bg2 = Sprite::create("game_background.jpg");
	bg1->setAnchorPoint(Point::ZERO);
	bg2->setAnchorPoint(Point::ZERO);
	bg1->setPosition(Point::ZERO);
	bg2->setPosition(Point(0, visibleSize.height));
	bg1->setScaleX(visibleSize.width / bg1->getContentSize().width);
	bg2->setScaleX(visibleSize.width / bg1->getContentSize().width);
	bg1->setScaleY(visibleSize.height / bg1->getContentSize().height);
	bg2->setScaleY(visibleSize.height / bg1->getContentSize().height);
	this->addChild(bg1, -2);
	this->addChild(bg2, -2);

	bgCloud1 = Sprite::create("cloud_background.png");
	bgCloud2 = Sprite::create("cloud_background.png");
	bgCloud1->setAnchorPoint(Point::ZERO);
	bgCloud2->setAnchorPoint(Point::ZERO);
	bgCloud1->setPosition(Point::ZERO);
	bgCloud2->setPosition(Point(0, visibleSize.height));
	bgCloud1->setScaleX(visibleSize.width / bg1->getContentSize().width);
	bgCloud2->setScaleX(visibleSize.width / bg1->getContentSize().width);
	bgCloud1->setScaleY(visibleSize.height / bg1->getContentSize().height);
	bgCloud2->setScaleY(visibleSize.height / bg1->getContentSize().height);
	this->addChild(bgCloud1, -1);
	this->addChild(bgCloud2, -1);
}

void BackgroudLayer::moveBackground(float dt)
{
	if (bg1->getPositionY() <= -visibleSize.height)
	{
		bg1->setPositionY(visibleSize.height);
		bgCloud1->setPositionY(visibleSize.height);
	}
	else if (bg2->getPositionY() <= -visibleSize.height)
	{
		bg2->setPositionY(visibleSize.height);
		bgCloud2->setPositionY(visibleSize.height);
	}
	else
	{
		bg1->setPositionY(bg1->getPositionY() - 5);
		bg2->setPositionY(bg2->getPositionY() - 5);

		bgCloud1->setPositionY(bgCloud1->getPositionY() - 10);
		bgCloud2->setPositionY(bgCloud2->getPositionY() - 10);
	}
}


