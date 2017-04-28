#ifndef __PlaneGame_PlaneWarlayer__
#define __PlaneGame_PlaneWarlayer__

#include"cocos2d.h"
USING_NS_CC;
#include"Layer/BackgroudLayer.h"
#include"Layer/PlayerLayer.h"

class PlaneWarLayer :public Layer
{
public:
	virtual bool init();
	virtual void update(float dt);

	CREATE_FUNC(PlaneWarLayer);

private:
	Size visibleSize;

	PlayerLayer*m_playerLayer;

	BackgroudLayer*m_backgroudLayer;
};

#endif  