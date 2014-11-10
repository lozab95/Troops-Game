#include "Base.h"


Base::Base(void)
{
	Pos_s_x;
	Pos_s_y;
	position_x;
	position_y;
	health=2500;
	damage=20;
}
Base::~Base(void)
{
	
	destroy_bitmap(house);
}
bool Base::isdead(void)
{
	if (health<=0)
	{
		return true;
	}
	else 
	{
		return false;
	}
}
void Base::Decon(void)
{
	//destroy_bitmap(house);
	//delete this;
}
void Base::update(int x, int y)
{
	isShot(x, y);
}



int Base::isShot(int x, int y)
{
	int r_x;
	int r_y;
	r_x=position_x-x;
	r_y=position_y-y;
	if (((r_x<0)&&(r_x>-25))&&((r_y<25)&&(r_y>-55)))
	{
		health-=damage;
		return 1;
	}
	else
	{
		return 0;
	}
}

void Base::setHouseNo(int i)
{
	houseNo = i;

	switch(houseNo)
	{
	case 1: house = load_bitmap("house1.bmp", NULL);
		break;
	case 2: house = load_bitmap("house2.bmp", NULL);
		break;
	case 3: house = load_bitmap("house3.bmp", NULL);
		break;
	case 4: house = load_bitmap("house4.bmp", NULL);
		break;
	case 5: house = load_bitmap("house5.bmp", NULL);
		break;
	case 6: house = load_bitmap("house6.bmp", NULL);
		break;
	case 7: house = load_bitmap("house7.bmp", NULL);
		break;
	case 8: house = load_bitmap("house8.bmp", NULL);
		break;
	}
	if(house == NULL)
	{
		allegro_message("Warrior Doesn't Work");
	}
	
}

void Base::draw(BITMAP *buffer)
{
	if(health>0)
	{
		masked_blit(house, buffer, 0,0,position_x,position_y, house->w, house->h);
	}
}

void Base::setSpawn(int x , int y)
{
	Pos_s_x=x;
	Pos_s_y=y;
}
int Base::getSpawnX(void)
{
	return Pos_s_x;
}
int Base::getHouseNo(void)
{
	return houseNo;
}
int Base::getSpawnY(void)
{
	return Pos_s_y;
}

int Base::getHealth(void)
{
	return health;
}
void Base::setPosition(int x,int y)
{
	position_x=x;
	position_y=y;
}
int Base::getPositionX(void)
{
	return position_x;
}
int Base::getPositionY(void)
{
	return position_y;
}

bool Base::spawner(void)
{
	if(health>0)
	{
	return true;
	}
	else 
	{
	return false;
	}
}
