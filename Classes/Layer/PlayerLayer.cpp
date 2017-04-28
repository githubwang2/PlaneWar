#include"Layer/PlayerLayer.h"

bool PlayerLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	starPlane();

	return true;
}

void PlayerLayer::starPlane()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	m_player = Player::create();
	Point startPos = Point(visibleSize.width / 2, 0);
	Point endPos = Point(visibleSize.width / 2, visibleSize.height / 4);
	m_player->setPosition(startPos);
	m_player->runAction(MoveTo::create(1.0f, endPos));
	addChild(m_player);

	auto playerWeapon1 = PlayerWeapon1::create();
	playerWeapon1->setAngleIndex(2);
	playerWeapon1->setPosition(endPos);
	addChild(playerWeapon1);

	auto playerWeapon2 = PlayerWeapon2::create();
	playerWeapon2->setPosition(400, 300);
	addChild(playerWeapon2);
}
