#pragma once

#ifndef AI_H
#define AI_H

#include <allegro.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <stdlib.h>

class AI
{
private:
	int team; 
	int deathcounter;//Ai score counter
	int health;
	int position_x;			
	int position_y;
	int damage;	//damage that is applyied upon collision of bullet
	int speed;//Speed controls the speed of movement
	int a_deathscore;//Death counter
	int decision;//variable that controls the AI's behaviour
	int change_decision;//this variable controls how long the decision of the AI movement goes on for
	int direction;//direction of the soldier
	int firerate;//rate of fire for bullets
	int shooter;//Whether the soldier is to shoot or not
	int cooldown;//cooldown for shooting
	int animX, animY; //These variables control the postition of the bitmap animation sequence

	BITMAP *warrior;       //Bitmap for soldier 
	BITMAP *warrior_right; //Right is for the enemy team

public:
	AI(void);//Constructor
	~AI(void);//deconstructor
	void Decon(void);//additional deconstructor
	bool update(int x, int y);//wrapper for other functions to be called

	void setTeam(int i);//sets team
	bool scoring(void);//manages score

	int getHealth(void);
	void setHealth(int i);
	
	void setPosition(int x,int y);
	
	int getPositionY(void);
	void subCooldown(void);//minus's down a cooldown value
	int getPositionX(void);
	int getDeathScore();
	void setDeathScore(int i);
	void takeDeathScore(void);
	int getDirection(void);
	void addPosition(char x, int i);
	bool isShot(int x, int y);//collision function for bullets

	void movement(BITMAP *buffer);//AI movement control and shooting decision
	int bulletTime(void);//controls when bullet is shot
};

#endif

