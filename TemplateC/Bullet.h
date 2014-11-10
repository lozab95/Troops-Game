#pragma once
class Bullet
{
public:
	Bullet(int i);

	int getX();

	int getY();
	int getDirection();
	void setX(int i);
	void setY(int i);
	void setDirection(int i);
	int getFirer();

private:
	int x, y;
	int direction;
	int whoFired;
};

