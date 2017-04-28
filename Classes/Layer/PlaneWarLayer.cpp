#include "Layer/PlaneWarLayer.h"


bool PlaneWarLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	visibleSize = Director::getInstance()->getWinSize();

	//---------------------------��ӱ���------------------ 
	m_backgroudLayer = BackgroudLayer::create();
	this->addChild(m_backgroudLayer, -1);
	//---------------------------������------------------
	m_playerLayer = PlayerLayer::create();
	this->addChild(m_playerLayer, 1);

	return true;
}

void PlaneWarLayer::update(float dt)
{

}
