#include "Bullet.h"


Bullet::Bullet(int i)
{
	whoFired = i;
}



int Bullet::getX()
{
	return x;
}

int Bullet::getY()
{
	return y;
}

int Bullet::getDirection()
{
	return direction;
}

void Bullet::setX(int i)
{
	x = i;
}

void Bullet::setY(int i)
{
	y = i;
}


void Bullet::setDirection(int i)
{
	direction = i;
}

int Bullet::getFirer()
{
	return whoFired;
}

