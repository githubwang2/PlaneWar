#ifndef __PlaneGame__BodyParent__
#define __PlaneGame__BodyParent__
#include "cocos2d.h"

USING_NS_CC;
class BodyParent : public Sprite
{
protected:
	BodyParent();
	int hp;
	int maxHP;
	bool selected;
	BodyParent* node;
	BodyParent* missile;
	bool isWeapon;
public:
    virtual void explode();
   
    virtual bool collide(int lethality);

    virtual void collide();

};



#endif
