#include <allegro.h>
#include "SoldierClass.h"


Soldier2::Soldier2()
{
	position_x=520;
	position_y=560;
	health =1000;
	damage =20;
	speed = 1;
	direction = -1;
	firerate = 35;
	cooldown = firerate;
	warrior_1 = load_bitmap("Soldier1.bmp", NULL);
	if(warrior_1 == NULL)
	{
		allegro_message("Warrior_1 Doesn't Work"); //Check that the bitmap is correctly loaded
	}
	p_deathscore = 0;
}
Soldier2::~Soldier2()
{
	destroy_bitmap(warrior_1);
}
void Soldier2::Decon(void)
{
	//destroy_bitmap(warrior_1);
	//delete this;
}
int Soldier2::getHealth(void)
{
	return health;
}
void Soldier2::setPosition(int x,int y)
{
	position_x=x;
	position_y=y;
}
int Soldier2::getPositionY(void)
{
	return position_y;
}
int Soldier2::getPositionX(void)
{
	return position_x;
}
int Soldier2::getDirection(void)
{
	return direction;
}
int Soldier2::isShot(int x, int y)
{
	int r_x;	//These values are inputed and are from the bullet array
	int r_y;
	r_x=position_x-x;		//This produces values that can be checked for size to see if collision is true.
	r_y=position_y-y;		//the position of the solider has the position of the bullet subtracked from it
	if (((r_x<6)&&(r_x>-6))&&((r_y<25)&&(r_y>-25)))
	{
		health-=damage;
		return 1;
	}
	else
	{
		return 0;
	}
}

void Soldier2::update(int x, int y)//This is a wrapper for functions that can be wrapped for every frame
{
	isShot(x, y);

	if(health < 0)
	{
		health = 0; //This stops health declining below 0
	}
}

bool Soldier2::keyboardInput() //Keyboard input is read here
{
	if(health>0)
	{
		if(key[KEY_A])
		{
			direction = -1;		//Face left
			position_x -= speed;//move left  by speed variable
			animX++;			//begin animation
			animY = 0;			//select animation row for moving left
		}
		else if(key[KEY_D])
		{
			direction = 1;
			position_x += speed;
			animX++;
			animY = 1;
		}
		else if(key[KEY_S])
		{
			position_y += speed;
			animX++;
		}
		else if(key[KEY_W])
		{
			position_y -= speed;
			animX++;
		}
		else if(key[KEY_P])
		{
		}
		else
		{
			animX =0;
		}


		if(animX >= 6)
		{
			animX = 0; //stops number of animations from going over 6, which is the number of animations I have
		}

		if(key[KEY_SPACE])
		{
			return true; //This is for the shooting of bullets
		}
		else
		{
			return false;
		}
	}
}

void Soldier2::draw(BITMAP *buffer)
{
	textprintf_ex(buffer, font, position_x - 10, position_y - 10, makecol(43, 135, 255), 1, "Health: %d", health);//Displays the Health of the player in blue
	textprintf_ex(buffer, font, 100, 100, makecol(20, 255, 20), 1, "Ally Score: %d", p_deathscore);//displays the players score

	if(health>0)
	{

		masked_blit(warrior_1, buffer, animX * 32,animY * 34,position_x,position_y, 32, 34);//Blit the player!
	}
}

int Soldier2::getDeathScore()
{
	return p_deathscore;
}
void Soldier2::setDeathScore(int i)
{
	p_deathscore +=  i;
}
void Soldier2::takeDeathScore(void)
{
	p_deathscore -=  20;
}
bool Soldier2::scoring(void)
{
	if(p_deathscore>20)
	{
		return true; //This allows for respawn of player!
	}
	else 
	{
		return false;
	}

}

int Soldier2::getfirerate()
{
	return firerate;
}

int Soldier2::getcooldown()
{
	return cooldown;
}

void Soldier2::setcooldown(int i)
{
	cooldown = i;
}