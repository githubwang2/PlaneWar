#ifndef __PlaneGame__PlayerWeapon2__
#define __PlaneGame__PlayerWeapon2__

#include "cocos2d.h"
#include "Sprite/BodyParent.h"
USING_NS_CC;
class PlayerWeapon2 : public BodyParent
{
public:
	CREATE_FUNC(PlayerWeapon2);
private:
	PlayerWeapon2();
	virtual bool init();

	Sprite*playerWeapon;
	Vector<SpriteFrame*> playerWeaponSF;
};


#endif
