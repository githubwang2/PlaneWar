#include "Sprite/BodyParent.h"

BodyParent::BodyParent()
{
	hp = 1;
	maxHP = 1;
	selected = false;
	node = nullptr;
	missile = nullptr;
	isWeapon = false;
}

bool BodyParent::collide(int lethality)
{
    if(lethality >= hp)
    {
        explode();
        collide();
        
        return true;
    }
    else
    {
        hp -= lethality;
        return false;
    }
}
void BodyParent::collide()
{
 
}

void BodyParent::explode()
{
    
}

