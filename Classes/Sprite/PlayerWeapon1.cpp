#include "Sprite/PlayerWeapon1.h"


PlayerWeapon1::PlayerWeapon1()
{
	angles[0] = -120;
	angles[1] = -100;
	angles[2] = -90;
	angles[3] = -80;
	angles[4] = -60;

	hp = 1;
	isWeapon = true;
}

bool PlayerWeapon1::init()
{
    if (!Sprite::init() )
    {
        return false;
    }

	 playerWeapon = Sprite::create();
	
	playerWeaponSF.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bullet_s_0.png"));
	playerWeaponSF.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("bullet_s_1.png"));
	playerWeapon->runAction(RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(playerWeaponSF, 0.1f))));
	addChild(playerWeapon);

    return true;
}

void PlayerWeapon1::setAngleIndex(int i)
{
    if(i >= 0 && i <= 4)
    {
        setRotation(angles[i]);
    }
    else
    {
        setRotation(angles[2]);
    }
}

