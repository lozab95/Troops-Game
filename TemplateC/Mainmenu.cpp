#include "Mainmenu.h"
#include "allegro.h"

Mainm::Mainm(void)
{
	choice=0;
	GUIMain = load_bitmap("GUIMain.bmp", NULL);
	GUIHelp = load_bitmap("GUIHelp.bmp", NULL);
}
Mainm::~Mainm(void)
{
	destroy_bitmap(GUIMain);
	destroy_bitmap(GUIHelp);
}
void Mainm::Decon(void)
{
	//destroy_bitmap(GUIMain);
	//destroy_bitmap(GUIHelp);
	//delete this;
}
void Mainm::draw(BITMAP *screen,int i)
{
	if ( i ==1)
	{
	blit(GUIMain, screen, 0,0,0,0, GUIMain->w, GUIMain->h);
	}
	if ( i ==2)
	{
		blit(GUIHelp, screen, 0,0,0,0, GUIHelp->w, GUIHelp->h);
	}
}

bool Mainm::ToMousePlay(void)
{
	if(((mouse_x>388)&&(mouse_x<836))&&((mouse_y>311)&&(mouse_y<377)))
	{
		if (mouse_b & 1)
		{
			return true;
		}
	}
	return false;
}
bool Mainm::ToMouseHelp(void)
{
	if(((mouse_x>884)&&(mouse_x<1051))&&((mouse_y>607)&&(mouse_y<677)))
	{
		if (mouse_b & 1)
		{
			return true;
		}
	}
	return false;
}


bool Mainm::ToMouseQuit(void)
{
	if(((mouse_x>388)&&(mouse_x<836))&&((mouse_y>555)&&(mouse_y<620)))
	{
		if (mouse_b & 1)
		{
			return true;
		}
	}
	return false;
}
bool Mainm::ToMouseHelpIn(void)
{
	if(((mouse_x>388)&&(mouse_x<836))&&((mouse_y>430)&&(mouse_y<498)))
	{
		if (mouse_b & 1)
		{
			return true;
		}
	}
	return false;
}