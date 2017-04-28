#ifndef __PlaneGame_PlaneWarScene__
#define __PlaneGame_PlaneWarScene__

#include "cocos2d.h"
USING_NS_CC;

#include"Layer/PlaneWarLayer.h"

class PlaneWarScene:public Scene
{
public:
	void run();

	virtual bool init();
	CREATE_FUNC(PlaneWarScene);
private:

};

#endif 