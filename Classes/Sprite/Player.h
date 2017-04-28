#ifndef __PlaneGame__Player__
#define __PlaneGame__Player__

#include"cocos2d.h"
USING_NS_CC;
#include"ConstUtil.h"
#include"Sprite/BodyParent.h"

class Player :public BodyParent
{
public:

	CREATE_FUNC(Player);

	virtual bool init();
private:

	void initPlayer();

	void movePlayer();

	Sprite* player;
	Size visibleSize;

	Vector<SpriteFrame*> playerSF;
	Vector<SpriteFrame*> playerLiftSF;
	Vector<SpriteFrame*> playerRightSF;
};

#endif