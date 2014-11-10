#include "AI.h"

AI::AI()
{
	deathcounter=0;
	direction = -1;
	a_deathscore=0;
	health =100;
	damage =5;
	firerate = 35;
	cooldown = firerate;
}

AI::~AI()
{
	destroy_bitmap(warrior);
}
void AI::Decon(void)  
{
	//destroy_bitmap(warrior);
	//delete this;
}
bool AI::scoring(void)
{
	if(deathcounter>20)
	{
		return true; //This allows for respawn of player!
	}
	else 
	{
		return false;
	}

}
void AI::setHealth(int i)
{
	health=i;
}
bool AI::update(int x, int y)
{
	if(health>0)
	{
		if(isShot(x, y)) // the inputed X & Y are from the bullet array and are for the bullet collision detection
		{
			return true; //Soldier is Shot
		}
		else
		{
			return false;
		}
	}
}

void AI::setTeam(int i)
{
	team = i;
	unsigned seed = time(0);
	srand(seed);
	speed = 1;
	decision = rand() % 9 + 1;  //A random decision is called
	animX = animY = 0;

	change_decision = 0;		//reset varaible for the timer for AI behaviour
			
	if(team > 0)
	{
		warrior = load_bitmap("Soldier1.bmp", NULL); //Left hand facing Solider
	}
	else
	{
		warrior = load_bitmap("Soldier1.bmp", NULL); //Right hand facing solider
	}

	if(warrior == NULL)
	{
		allegro_message("Warrior Doesn't Work"); //hopefully not
	}

}

int AI::getHealth(void)
{
	return health;
}

int AI::getDirection(void)
{
	return direction;
}
void AI::setPosition(int x,int y)
{
	position_x = x;
	position_y = y;
}
void AI::subCooldown(void)
{
	cooldown=cooldown-1;
}

int AI::bulletTime(void)
{
	if(((cooldown<= 0) && (shooter ==1)) && (health>0))
	{
		cooldown=firerate; //ready to shoot!
		return 1;//Shooting is now permitted
	}
	return 0;
}
int AI::getPositionY(void)
{
	return position_y;
}

int AI::getPositionX(void)
{
	return position_x;
}

bool AI::isShot(int x, int y)
{
	int r_x;//These values are inputed and are from the bullet array
	int r_y;
	r_x=position_x-x; //This produces values that can be checked for size to see if collision is true.
	r_y=position_y-y;//the position of the solider has the position of the bullet subtracked from it
	if (((r_x<6)&&(r_x>-6))&&((r_y<25)&&(r_y>-25)))//Is collision true
	{
		health-=damage;//takes away health
		deathcounter++;//Adds to score
		return true;
	}
	else
	{
		return false;
	}
}

void AI::movement(BITMAP *buffer)
{

	/*
	1 - Stand Still
	2 - Shoot
	3 - Move Up
	4 - Move Down
	5 - Move Right
	6 - Move Left
	7 - Stand Still
	8 - Stand Still
	9 - Stand Still
	*/

	if(team == -1)
	{
		animY = 0;//enemy team
	}
	else
	{
		animY = 34;//ally team
	}

	if(health<0)
	{
		shooter=0; //Cannot shoot when dead
	}
	if(change_decision >= 600)//decision runs for 600 frames before changing
	{
		change_decision = 0; //This will now allow a new decision to be made
		decision = rand() % 9 + 1;
	}
	if(health>0)
	{
		//------------ AI FOR ALLY--------			//	masked_blit(warrior, buffer, 40, animY,position_x,position_y, 32, 34);
		switch(decision)
		{
		case 1:
			shooter = 0;		//no shots
			direction =team;	//Face towards team
			animX = 0;			//First element of bitmap
			masked_blit(warrior, buffer, animX * 32, animY, position_x, position_y, 32, 34);
			change_decision += 150;
			break;
		case 2:
			shooter = 0;		//no shots
			direction =team;	//Face towards team
			animX = 0;			//First element of bitmap
			masked_blit(warrior, buffer, animX * 32, animY, position_x, position_y, 32, 34);
			change_decision += 10;
			break;
		case 3:
			shooter = 0;			//no shots
			direction=team;			//Face towards team
			masked_blit(warrior, buffer, animX * 32, animY, position_x, position_y, 32, 34);
			change_decision += 10;
			position_y -= speed;
			animX++;				//select next animation
			break;
		case 4:
			shooter = 0;		//no shots
			direction=team;		//Face towards team
			masked_blit(warrior, buffer, animX * 32, animY, position_x, position_y, 32, 34);
			change_decision += 10;//This action adds 10 to the change decision, once at 600 a new position is called
			position_y += speed;
			animX++;
			break;
		case 5:
			direction=1;		//no shots
			shooter = 0;		//Face towards enemy
			masked_blit(warrior, buffer, animX * 32, animY, position_x, position_y, 32, 34);
			change_decision += 10;//This action adds 10 to the change decision, once at 600 a new position is called
			position_x += speed * team;//transform x by speed (1) and in the direction of team (-1||1)
			animX++;			//select next animation
			break;
		case 6:
			direction=team;
			shooter = 0;
			change_decision += 10;//This action adds 10 to the change decision, once at 600 a new position is called
			masked_blit(warrior, buffer, animX * 32, animY, position_x, position_y, 32, 34);//Masked blit to buffer of the warrior bitmap on the element of the row (animX) and on the collum of AnimY
			break;
		case 7:
			direction=team;
			shooter = 0;
			change_decision += 10;//This action adds 10 to the change decision, once at 600 a new position is called
			masked_blit(warrior, buffer, animX * 32, animY, position_x, position_y, 32, 34);//Masked blit to buffer of the warrior bitmap on the element of the row (animX) and on the collum of AnimY
			break;
		case 8:
			direction=team;
			shooter = 0;
			change_decision += 10;//This action adds 10 to the change decision, once at 600 a new position is called
			masked_blit(warrior, buffer, animX * 32, animY, position_x, position_y, 32, 34); //Masked blit to buffer of the warrior bitmap on the element of the row (animX) and on the collum of AnimY
			break;
		case 9:
			direction=team;
			shooter = 1;//Shooting will now be permitted
			change_decision += 10;//This action adds 10 to the change decision, once at 600 a new position is called
			masked_blit(warrior, buffer, animX * 32, animY, position_x, position_y, 32, 34);
			break;

		}

		change_decision++; 

		if(animX >= 6)
		{
			animX = 0; //this stops the row of animation elements going off the end. As there are only 6 animation images
		}
	}

	//--------------Text------------
	if(health>0)				//This displays the health of the soliders, with varying colours depending on the team
	{
		if(team==1)
		{
			textprintf_ex(buffer, font, position_x - 10, position_y - 10, makecol(255, 0,0 ), 1, "Health: %d", health);
		}
		if(team==-1)
		{
			textprintf_ex(buffer, font, position_x - 10, position_y - 10, makecol(20, 255,20 ), 1, "Health: %d", health);
		}
	}
}
int AI::getDeathScore()
{
	return a_deathscore;
}
void AI::setDeathScore(int i)
{
	a_deathscore +=  i;
}
void AI::takeDeathScore(void)
{
	a_deathscore -=  20;
}