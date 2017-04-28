#ifndef __PlaneGame_RedPlayer__
#define __PlaneGame_RedPlayer__

#include"cocos2d.h"
USING_NS_CC;

#include "Sprite/Player.h"
class RedPlane:public Player
{
public:

	CREATE_FUNC(RedPlane);

	virtual bool init();
private:

	 void createPlayer();

	 void movePlayer();

	 void runLift();
	 void runRight();

	Sprite* player;
	Size visibleSize;
};


#endif