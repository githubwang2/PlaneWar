#ifndef __PlaneGame_BackgroudLayer__
#define __PlaneGame_BackgroudLayer__

#include"cocos2d.h"
USING_NS_CC;


class BackgroudLayer :public Layer
{
public:
	virtual bool init();

	CREATE_FUNC(BackgroudLayer);

private:
	void addBackgroud();
	void moveBackground(float dt);

	Size visibleSize;
	Sprite*bg1;
	Sprite*bg2;
	Sprite*bgCloud1;
	Sprite*bgCloud2;
};

#endif 