#include "Sprite/PlayerWeapon2.h"

PlayerWeapon2::PlayerWeapon2()
{
	hp = 2;
	isWeapon = true;
}

bool PlayerWeapon2::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	playerWeapon = Sprite::create();
	playerWeaponSF.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bullet_o_0.png"));
	playerWeaponSF.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bullet_o_1.png"));
	playerWeapon->runAction(RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(playerWeaponSF, 0.1f))));
	addChild(playerWeapon);

	return true;
}
