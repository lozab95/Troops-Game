#pragma once

#ifndef _SoldierClass_H_
#define _SoldierClass_H_

#include <allegro.h>
#include "Bullet.h"

class Soldier2
{
public:
	Soldier2();
	~Soldier2();
	void Decon(void);
	
	int getHealth(void);
	
	void setPosition(int x,int y);
	
	int getPositionY(void);
	
	int getPositionX(void);

	int getDirection(void);
	
	void addPosition(char x, int i);
	
	int isShot(int x, int y);

	bool keyboardInput();

	void update(int x, int y);

	int getfirerate();

	int getcooldown();
	int getDeathScore();

	void setcooldown(int i);
	void setDeathScore(int i);
	void takeDeathScore(void);
	void draw(BITMAP *buffer);

	bool scoring(void);

	
private:
	int health;
	int position_x;
	int position_y;
	int damage;
	int p_deathscore;
	int speed;
	int animX, animY;
	int direction;
	int firerate;
	int cooldown;

	BITMAP *warrior_1;
};

#endif