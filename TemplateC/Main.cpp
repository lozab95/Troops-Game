/*Allegro Program Template.c */
#include <allegro.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "cgg/Matrix2.h"
#include "cgg/Transform2.h"
#include "SoldierClass.h"
#include "AI.h"
#include "Mainmenu.h"
#include "Base.h"
#include "Bullet.h"
float b_position_x;
float b_position_y;
int framecounter=0;
int position[2] = {0, 0};


//Global Variables

/* prototypes */
void init();
void deinit();
void Mmenu(void);
void update(void);
void play(void);

int main(void) 
{

	init(); 
	Mmenu();//Menu
	deinit();
	return 0;
}

END_OF_MAIN()    

	/* function definitions */

	void init() 
{
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0)
	{ 
		depth = 32;
	}
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1280, 720, 0, 0);
	if (res != 0) 
	{
		allegro_message(allegro_error);
		exit(-1);
	}
	install_sound( DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
	install_timer();
	install_keyboard();
	install_mouse();
	/* add other initializations here */
}

void Mmenu(void)
{
	SAMPLE *Music;
	Music = load_sample("Music.wav");
	if(Music == NULL)
	{
		allegro_message("Music Doesn't Work"); //Check that the music is correctly loaded
	}
	Mainm *Menu; //Creation of menu class object
	Menu = new Mainm();

	int gamestate=0; //show main menu screen

	do
	{
		if(gamestate==0)
			play_sample(Music, 128,128, 1000, 0); 
		{
			Menu->draw(screen, 1); //blit main menu
		}
		textprintf_ex(screen, font, 100, 100, makecol(20, 255, 20), 1, "X Score: %d", mouse_x);
		textprintf_ex(screen, font, 300, 100, makecol(20, 255, 20), 1, "Y Score: %d", mouse_y);
		if(Menu->ToMousePlay()==true) //If play button is pressed
		{
			gamestate =1;
		}	
		if(Menu->ToMouseHelpIn()==true) //If help button is pressed
		{	
			gamestate =2;
		}

		if (gamestate==1) //play game 
		{
			while((!key[KEY_ESC]))
			{

				play(); //start game

			}
			gamestate=0;
		}
		else if (gamestate==2)
		{
			while(Menu->ToMouseHelp()==false)//while the return button is not pressed
			{
				Menu->draw(screen,2);

			}
		}
		gamestate=0;//display menu

		if(Menu->ToMouseQuit()==true)//If quit button is pressed
		{	
			gamestate =3;//quit game variable set
		}
		show_mouse(screen);//display mouse on screen
	}
	while(gamestate !=3);//display menu while game state isnt 3
	delete Menu;//delete menu class object

}

void deinit() 
{

	clear_keybuf();
	/* add other deinitializations here */
}

void update(void)
{

}


void play(void) 
{  /* start of main */
	unsigned seed = time(0); 
	srand(seed);

	//Assets

	BITMAP * Background02;
	BITMAP * bullet_a;
	BITMAP * bullet_f;
	BITMAP * buffer;
	//Local Variables
	int baselives =0;
	std::vector<Bullet> bullet; //std vectors for bullets
	//Player
	Soldier2 *s_p;   //player class object creation
	s_p = new Soldier2();
	s_p->setPosition(1030,660);
	//-----------------------BASES--Object Creation----
	Base *House1;
	House1 = new Base();
	Base *House2;
	House2 = new Base();
	Base *House3;
	House3 = new Base();
	Base *House4;
	House4 = new Base();
	Base *House5;
	House5 = new Base();
	Base *House6;
	House6 = new Base();
	Base *House7;
	House7 = new Base();
	Base *House8;
	House8 = new Base();

	//-----Soldiers----Object Creation----
	AI *Frank;
	Frank = new AI();
	AI *Steve;
	Steve = new AI();
	AI *Dusty;
	Dusty = new AI();
	AI *Rico;
	Rico = new AI();
	AI *Stella;
	Stella = new AI();
	AI *Diablo;
	Diablo = new AI();
	AI *Jimmy;
	Jimmy = new AI();

	//Setting teams of the soldiers
	Steve->setTeam(-1);
	Dusty->setTeam(-1);
	Frank->setTeam(-1);
	Rico->setTeam(1);
	Stella->setTeam(1);
	Diablo->setTeam(1);
	Jimmy->setTeam(1);


	//Load in relevant bitmap images
	bullet_a=load_bitmap("bullet_a.bmp", NULL);
	if(bullet_a == NULL)
	{
		allegro_message("bullet_a Doesn't Work"); //Check that the bitmap is correctly loaded
	}
	bullet_f=load_bitmap("bullet_f.bmp", NULL);
	if(bullet_f == NULL)
	{
		allegro_message("bullet_f Doesn't Work"); //Check that the bitmap is correctly loaded
	}
	Background02=load_bitmap("cf-base.bmp",NULL);
	if(Background02 == NULL)
	{
		allegro_message("Background02 Doesn't Work"); //Check that the bitmap is correctly loaded
	}
	buffer = create_bitmap(SCREEN_W, SCREEN_H);

	//---------LEVEL CREATION-------------
	//This sets the house numbers so that they can be referenced later
	House1->setHouseNo(1);
	House2->setHouseNo(2);
	House3->setHouseNo(3);
	House4->setHouseNo(4);
	House5->setHouseNo(5);
	House6->setHouseNo(6);
	House7->setHouseNo(7);
	House8->setHouseNo(8);
	//This sets the position of the house for blitting and collision
	House1->setPosition(1100,512);
	House2->setPosition(1111,480);
	House3->setPosition(1066,312);
	House4->setPosition(1043,142);
	House5->setPosition(-1,325);
	House6->setPosition(0,400);
	House7->setPosition(3,512);
	House8->setPosition(-2,155);
	//This sets the location for the soldiers to spawn at
	House1->setSpawn(1076,634);
	House2->setSpawn(1114,502);
	House3->setSpawn(1060,502);
	House4->setSpawn(1067,246);
	House5->setSpawn(130,390);
	House6->setSpawn(124,474);
	House7->setSpawn(125,602);
	House8->setSpawn(140,245);
	//Sets the postions of the soldiers to their relevant houses
	Steve->setPosition(House2->getSpawnX(),House2->getSpawnY());
	Dusty->setPosition(House3->getSpawnX(),House3->getSpawnY());
	Frank->setPosition(House4->getSpawnX(),House4->getSpawnY());
	Rico->setPosition(House5->getSpawnX(),House5->getSpawnY());
	Stella->setPosition(House6->getSpawnX(),House6->getSpawnY());
	Diablo->setPosition(House7->getSpawnX(),House7->getSpawnY());
	Jimmy->setPosition(House8->getSpawnX(),House8->getSpawnY());

	
	//-----------Play Loop-------------
	//while(((!key[KEY_ESC])) && ((Rico->getHealth()!=0) && (Stella->getHealth()!=0) && (Diablo->getHealth()!=0) && (Jimmy->getHealth()!=0)));
	while((!key[KEY_ESC]))
	{
		
			//blit landscape
			blit(Background02, buffer, 0,0,0,0, Background02->w, Background02->h);

			//This calls the AI movement function for each soldier
			Frank->movement(buffer);
			Steve->movement(buffer);
			Dusty->movement(buffer);
			Rico->movement(buffer);
			Stella->movement(buffer);
			Diablo->movement(buffer);
			Jimmy->movement(buffer);



			//-----------Respawner-------------
			if((((House2->spawner())) || ((House3->spawner())) || ((House4->spawner()))))
			{
				if(s_p->scoring()==true) //If user has enough points 
				{
					if(Steve->getHealth()<=0)//If a soldier is dead (has 0 health)
					{
						Steve->setPosition(House2->getSpawnX(),House2->getSpawnY()); //reset position
						Steve->setHealth(100);	//reset health
						s_p->takeDeathScore();	//take away 20 points from user score
					}
					if(Dusty->getHealth()<=0)
					{
						Dusty->setPosition(House3->getSpawnX(),House3->getSpawnY());
						Dusty->setHealth(100);
						s_p->takeDeathScore();
					}
					if(Frank->getHealth()<=0)
					{
						Frank->setPosition(House4->getSpawnX(),House4->getSpawnY());
						Frank->setHealth(100);
						s_p->takeDeathScore();
					}
				}
			}
			
			//-----------Respawner-------------

			/*------------------------COLLISION-----------------------*/				
			//---------------------------&&--------------------------//
			/*------------------------BULLETS-----------------------*/				
			//Move Bullets
			for(int i=0; i < bullet.size();) //Lops for the amount of bullets in scene
			{
				bullet[i].setX(bullet[i].getX() + bullet[i].getDirection()*2);//moves bullet in its direction

				if(bullet[i].getX() > 1280 || bullet[i].getX() < 0)
				{
					bullet.erase(bullet.begin() + i); //if bullets leaves screen space then erase it
				}
				else
				{
					i++; // if not off screen check next
				}
			}

			//AI and Player Boundary Killer

			if((Frank->getPositionX() > 1280 ||Frank->getPositionY() < 0) || (Frank->getPositionY() > 720 ||Frank->getPositionY() < 0))
			{
				Frank->setHealth(0);
			}
			if((Steve->getPositionX() > 1280 ||Steve->getPositionY() < 0) || (Steve->getPositionY() > 720 ||Steve->getPositionY() < 0))
			{
				Steve->setHealth(0);
			}
			if((Dusty->getPositionX() > 1280 ||Dusty->getPositionY() < 0) || (Dusty->getPositionY() > 720 ||Dusty->getPositionY() < 0))
			{
				Dusty->setHealth(0);
			}
			if((Diablo->getPositionX() > 1280 ||Diablo->getPositionY() < 0) || (Diablo->getPositionY() > 720 ||Diablo->getPositionY() < 0))
			{
				Diablo->setHealth(0);
			}
			if((Jimmy->getPositionX() > 1280 ||Jimmy->getPositionY() < 0) || (Jimmy->getPositionY() > 720 ||Jimmy->getPositionY() < 0))
			{
				Jimmy->setHealth(0);
			}
			if((Stella->getPositionX() > 1280 ||Stella->getPositionY() < 0) || (Stella->getPositionY() > 720 ||Stella->getPositionY() < 0))
			{
				Stella->setHealth(0);
			}
			if((Rico->getPositionX() > 1280 ||Rico->getPositionY() < 0) || (Rico->getPositionY() > 720 ||Rico->getPositionY() < 0))
			{
				Rico->setHealth(0);
			}
			//BulletUpdater
			for(int i=0; i < bullet.size(); i++) //For each bullet...
			{
				s_p->update(bullet[i].getX(), bullet[i].getY());	//Check for collision & scoring
				if(Frank->update(bullet[i].getX(), bullet[i].getY()))//Check for collision & scoring
				{
					if(bullet[i].getFirer() == -1)//if the bullet was from enemy
					{
						Frank->setDeathScore(1);
					}
				}
				if(Steve->update(bullet[i].getX(), bullet[i].getY()))
				{
					if(bullet[i].getFirer() == -1)
					{
						Frank->setDeathScore(1);
					}
				}
				if(Dusty->update(bullet[i].getX(), bullet[i].getY()))
				{
					if(bullet[i].getFirer() == -1)
					{
						Frank->setDeathScore(1);
					}
				}
				if(Stella->update(bullet[i].getX(), bullet[i].getY()))//Check for collision & scoring
				{
					if(bullet[i].getFirer() == 1)
					{
						s_p->setDeathScore(1);

					}
				}
				if(Jimmy->update(bullet[i].getX(), bullet[i].getY()))
				{
					if(bullet[i].getFirer() == 1)
					{
						s_p->setDeathScore(1);

					}
				}																		
				if(Diablo->update(bullet[i].getX(), bullet[i].getY()))
				{
					if(bullet[i].getFirer() == 1)
					{
						s_p->setDeathScore(1);

					}
				}
				if(Rico->update(bullet[i].getX(), bullet[i].getY()))
				{
					if(bullet[i].getFirer() == 1)
					{
						s_p->setDeathScore(1);
					}
				}
				//Checks collision on buidlings
				House1->update(bullet[i].getX(), bullet[i].getY());
				House2->update(bullet[i].getX(), bullet[i].getY());
				House3->update(bullet[i].getX(), bullet[i].getY());
				House4->update(bullet[i].getX(), bullet[i].getY());
				House5->update(bullet[i].getX(), bullet[i].getY());
				House6->update(bullet[i].getX(), bullet[i].getY());
				House7->update(bullet[i].getX(), bullet[i].getY());
				House8->update(bullet[i].getX(), bullet[i].getY());

			}

			if(Frank->bulletTime()==1) //if Bullet is to be permitted to shot
			{
				Bullet newbullet(1); //Ally is the shooter
				newbullet.setX(Frank->getPositionX() + (Frank->getDirection() * 10)); //starts the bullet 10 units away from the player in the correct direction
				newbullet.setY(Frank->getPositionY() + 5); //start the bullet 5 units down from the soldier
				newbullet.setDirection(Frank->getDirection());//fire bullet from the right direciton
				bullet.push_back(newbullet);//Create new bullet
			}
			Frank->subCooldown();//Bullet cooldown
			if(Steve->bulletTime()==1)
			{
				Bullet newbullet(1);
				newbullet.setX(Steve->getPositionX() + (Steve->getDirection() * 10));
				newbullet.setY(Steve->getPositionY() + 5);
				newbullet.setDirection(Steve->getDirection());
				bullet.push_back(newbullet);
			}
			Steve->subCooldown();
			if(Dusty->bulletTime()==1)
			{
				Bullet newbullet(1);
				newbullet.setX(Dusty->getPositionX() + (Dusty->getDirection() * 10));
				newbullet.setY(Dusty->getPositionY() + 5);
				newbullet.setDirection(Dusty->getDirection());
				bullet.push_back(newbullet);
			}
			Dusty->subCooldown();
			if(Jimmy->bulletTime()==1)
			{
				Bullet newbullet(-1);//Enemy is the shooter
				newbullet.setX(Jimmy->getPositionX() + (Jimmy->getDirection() * 10));
				newbullet.setY(Jimmy->getPositionY() + 5);
				newbullet.setDirection(Jimmy->getDirection());
				bullet.push_back(newbullet);
			}
			Jimmy->subCooldown();
			if(Stella->bulletTime()==1)
			{
				Bullet newbullet(-1);
				newbullet.setX(Stella->getPositionX() + (Stella->getDirection() * 10));
				newbullet.setY(Stella->getPositionY() + 5);
				newbullet.setDirection(Stella->getDirection());
				bullet.push_back(newbullet);
			}
			Stella->subCooldown();

			//BulletSpawnerFor Player
			if(s_p->keyboardInput() && s_p->getcooldown() <= 0 && (s_p->getHealth()>0)) //allows for bullet to be fired
			{
				Bullet newbullet(1);
				newbullet.setX(s_p->getPositionX() + (s_p->getDirection() * 10));
				newbullet.setY(s_p->getPositionY() + 5);
				newbullet.setDirection(s_p->getDirection());

				bullet.push_back(newbullet);

				s_p->setcooldown(s_p->getfirerate()); //sets the cooldown time from the firerate
			}
			s_p->setcooldown(s_p->getcooldown() - 1); //reduces cooldown
			//Draws the houses
			House1->draw(buffer);
			House2->draw(buffer);
			House3->draw(buffer);
			House4->draw(buffer);
			House5->draw(buffer);
			House6->draw(buffer);
			House7->draw(buffer);
			House8->draw(buffer);

			if ((House5->isdead()) && (House6->isdead()) && (House7->isdead()) && (House8->isdead()))
			{
			 textprintf_ex(buffer, font, 420, 350, makecol(255, 0, 0), 1, "Level Complete - Press 'ESC' to Quit");
			}
			 
		

			//BulletDirection-er
			for(int i=0; i < bullet.size(); i++)
			{
				if(bullet[i].getDirection() > 0) // If its direction is -1 draw the bullet_f bullet image
				{
					masked_blit(bullet_f, buffer, 0, 0, bullet[i].getX(), bullet[i].getY(),bullet_f->w, bullet_f->h); 
				}
				else								// else draw the bullet_a bullet image
				{
					masked_blit(bullet_a, buffer, 0, 0, bullet[i].getX(), bullet[i].getY(),bullet_a->w, bullet_a->h); 
				}
			}
			/*------------------------END OF BULLETS-----------------------*/	
			//------------------------TEXT------------------------------

			textprintf_ex(buffer, font, 500, 100, makecol(255, 0, 0), 1, "Death Score: %d", Frank->getDeathScore());//draw score
			s_p->draw(buffer); //draw buffer
			blit(buffer, screen, 0,0,0,0, buffer->w, buffer->h);//draw buffer to screen
			clear_bitmap(buffer);//clear buffer
		
	}
	//----------Destroy Elements----------
	//---And clear pointers
	delete House1;			
	delete House2;
	delete House3;
	delete House4;
	delete House5;
	delete House6;
	delete House7;
	delete House8;
	delete Steve;
	delete Dusty;
	delete Frank;
	delete Rico;
	delete Stella;
	delete Diablo;
	delete Jimmy;
	delete s_p;
	House1= NULL;	
	House2= NULL;	
	House3= NULL;	
	House4= NULL;	
	House5= NULL;	
	House6= NULL;	
	House7= NULL;	
	House8= NULL;	
	Steve= NULL;	
	Dusty= NULL;	
	Frank= NULL;	
	Rico = NULL;	
	Stella= NULL;	
	Diablo= NULL;	
	Jimmy= NULL;	
	s_p	= NULL;	
	destroy_bitmap(bullet_a);
	destroy_bitmap(bullet_f);
	destroy_bitmap(Background02);


} /* end of Normal main */

