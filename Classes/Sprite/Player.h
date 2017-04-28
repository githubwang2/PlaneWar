#ifndef __PlaneGame_Player__
#define __PlaneGame_Player__

#include"cocos2d.h"
USING_NS_CC;

class Player :public Sprite
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