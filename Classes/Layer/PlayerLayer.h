#ifndef __PlaneGame_PlayerLayer__
#define __PlaneGame_PlayerLayer__

#include"cocos2d.h"
USING_NS_CC;

#include"Sprite/Player.h"

class PlayerLayer :public Layer
{
public:
	virtual bool init();

	CREATE_FUNC(PlayerLayer);

private:
	void starPlane();
	Player*m_player;
};

#endif 