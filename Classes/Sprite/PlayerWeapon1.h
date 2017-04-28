#ifndef __PlaneGame__PlayerWeapon1__
#define __PlaneGame__PlayerWeapon1__

#include "cocos2d.h"
#include "Sprite/BodyParent.h"
USING_NS_CC;

class PlayerWeapon1 : public BodyParent
{
public:
	CREATE_FUNC(PlayerWeapon1);
	void setAngleIndex(int i);
private:
	PlayerWeapon1();
	virtual bool init();

	int angles[5];

	Sprite*playerWeapon;
	Vector<SpriteFrame*> playerWeaponSF;
};

#endif
