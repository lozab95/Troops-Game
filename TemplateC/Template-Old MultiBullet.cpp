/*Allegro Program Template.c */
#include <allegro.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "cgg/Matrix2.h"
#include "cgg/Transform2.h"

float b_position_x;
float b_position_y;
int framecounter=0;

int position[2] = {0, 0};




//Structures
struct Soldier
{
	int health;
	int position_x;
	int position_y;
	int bullet_t;
	int bullet_1[2];
	int bullet_2[2];
	int bullet_3[2];
	int damage;
};
struct Main_base
{
	int position_x;
	int position_y;
	int health;

};

//Global Variables


/* prototypes */
void init();
void deinit();
void update(void);
int main() 
{  /* start of main */
	
	Matrix2 g_transform;
	std::vector<Matrix2> g_bulletTM;

	//initialization
	Soldier soldier_a;
		soldier_a.position_x=520;
		soldier_a.position_y=560;
		soldier_a.bullet_t = 0;
		soldier_a.bullet_1[0]= 1200;
		soldier_a.bullet_1[1]= 1200;
		soldier_a.bullet_2[0]= 1200;
		soldier_a.bullet_2[1]= 1200;
		soldier_a.bullet_3[0]= 1200; 
		soldier_a.bullet_3[1]= 1200;
		
		
		
		
		soldier_a.health =100;
		soldier_a.damage =20;

	Soldier soldier_f;
		unsigned seed = time(0);
		srand(seed);
		soldier_f.position_x=20;
		soldier_f.position_y=rand () %200+450;
		soldier_f.bullet_t = 0;
		soldier_f.bullet_1[0]= 1200;
		soldier_f.bullet_1[1]= 1200;
		soldier_f.bullet_2[0]= 1200;
		soldier_f.bullet_2[1]= 1200;
		soldier_f.bullet_3[0]=1200; 
		soldier_f.bullet_3[1]= 0;
		
		
		
		soldier_f.health =100;
		soldier_f.damage =20;

		

	//Assets
	SAMPLE *Crash;
	SAMPLE *Slash;
	SAMPLE *Smash;
	SAMPLE *Music;

	BITMAP * warrior;
	BITMAP * warrior_1;
	BITMAP * warrior_2;
	BITMAP * warrior_3;

	BITMAP * soldier_f_1;

	BITMAP * Background02;
	BITMAP * Background_2;
	BITMAP * Background_3;
	BITMAP * Background_4;
	BITMAP * Background_5;
	BITMAP * Background_6;
	BITMAP * Background_7;
	BITMAP * Background_8;
	BITMAP * Background_9;
	BITMAP * Background_10;
	BITMAP * Background_11;

	BITMAP * bullet_a;
	BITMAP * bullet_f;
	BITMAP * boulder;
	BITMAP * buffer;

	//Local Variables
	float p_position_x =20;
	float p_position_y=560;
	int framecounter_soldier_f =0;
	int framecounter_bullet=0;
	int framecounter_bullet2=0;
	int fc_collision_a=0;
	int fc_collision_f=0;

	//random-ness

	srand(seed);
	b_position_x =20;
	b_position_y =rand () %200+550;


	float base_x_position =0;
	int hit_base =1;
	int animationcount =0;
	int closest_x;
	int closest_y;

	//init
	init();

	framecounter=0;
	install_int(update,5);


	warrior=load_bitmap("WarriorKillerBitmap.bmp",NULL);
	warrior_1=load_bitmap("WarriorKillerBitmap_1.bmp",NULL);
	warrior_2=load_bitmap("WarriorKillerBitmap_2.bmp",NULL);
	warrior_3=load_bitmap("WarriorKillerBitmap_3.bmp",NULL);

	soldier_f_1=load_bitmap("Soldier_f_Bitmap1.bmp",NULL);

	Background02=load_bitmap("BG-Style-1.bmp",NULL);
	Background_2=load_bitmap("BG-Style-1",NULL);
	Background_3=load_bitmap("Background_3.bmp",NULL);
	Background_4=load_bitmap("Background_4.bmp",NULL);
	Background_5=load_bitmap("Background_5.bmp",NULL);
	Background_6=load_bitmap("Background_6.bmp",NULL);
	Background_7=load_bitmap("Background_7.bmp",NULL);
	Background_8=load_bitmap("Background_8.bmp",NULL);
	Background_9=load_bitmap("Background_9.bmp",NULL);
	Background_10=load_bitmap("Background_10.bmp",NULL);
	Background_11=load_bitmap("Background_11.bmp",NULL);

	Music = load_sample("Music.wav");
	Slash = load_sample("Slash.wav");
	Smash = load_sample("Smash.wav");
	Crash = load_sample("Crash.wav");

	bullet_a=load_bitmap("bullet_a.bmp", NULL);
	bullet_f=load_bitmap("bullet_f.bmp", NULL);
	boulder=load_bitmap("boulder.bmp",NULL);
	buffer = create_bitmap( SCREEN_W, SCREEN_H);
	blit(Background02, screen, 0,0,0,0, Background02->w, Background02->h);

	rest(2500);
	//play_sample(Music, 255,128, 1000, 0);

	textprintf_ex(screen, font, 15, 15, 15, 15, "Press Enter to Play!"); 
	bool flag=false;
	/*
	do
	{
	
		int test = readkey () & 0xFF;
	    if(test == 0x0D)
		{
			flag=true;
		}
		else
		{
			textprintf_ex(screen, font, 15, 15, 15, 1, "Press Enter to Play!"); 
		}
	}
	while( flag==false);
	*/

	while ((!key[KEY_ESC])&&(hit_base<11))
	{


		animationcount=0;

		//Key Presses
		if(key[KEY_A])
		{
		soldier_a.position_x+=-1.0;
		}
		if(key[KEY_D])
		{
		soldier_a.position_x+=+1.0;
		}
		if(key[KEY_S])
		{
			if (p_position_y<740)
			{
			soldier_a.position_y+=+1.0;
			}
		}
		if(key[KEY_W])
		{
			if (p_position_y>470)
			{
			soldier_a.position_y+=-1.0;
			}
		}
		if(key[KEY_P])
		{
			int x=soldier_a.health + soldier_f.health;
		}

		switch (hit_base)
		{
		case 1 : blit(Background02, buffer, 0,0,0,0, Background02->w, Background02->h); 
			break;
		case 2 : blit(Background_2, buffer, 0,0,0,0, Background_2->w, Background_2->h);
			break;
		case 3 : blit(Background_3, buffer, 0,0,0,0, Background_3->w, Background_3->h);
			break;
		case 4 : blit(Background_4, buffer, 0,0,0,0, Background_4->w, Background_4->h);
			break;
		case 5 : blit(Background_5, buffer, 0,0,0,0, Background_5->w, Background_5->h);
			break;
		case 6 : blit(Background_6, buffer, 0,0,0,0, Background_6->w, Background_6->h);
			break;
		case 7 : blit(Background_7, buffer, 0,0,0,0, Background_7->w, Background_7->h);
			break;
		case 8 : blit(Background_8, buffer, 0,0,0,0, Background_8->w, Background_8->h);
			break;
		case 9 : blit(Background_9, buffer, 0,0,0,0, Background_9->w, Background_9->h);
			break;
		case 10 : blit(Background_10, buffer, 0,0,0,0, Background_10->w, Background_10->h);
			break;
		case 11 : blit(Background_11, buffer, 0,0,0,0, Background_11->w, Background_11->h);
			break;
		default:  blit(Background02, buffer, 0,0,0,0, Background02->w, Background02->h);
			break;
		}

		/*if(key[KEY_SPACE])
		{
			//begin slash
			animationcount++;
			//Sound
			//play_sample(Slash, 128,128, 1000, 0);

			//BulletAction
			soldier_a.bullet_t = 1; //activates render
			soldier_a.bullet_y = soldier_a.position_y;
			soldier_a.bullet_x = soldier_a.position_x- 1;
			//Collision 
			closest_x = soldier_a.position_x-b_position_x;
			closest_y = soldier_a.position_y-b_position_y;
				if (((closest_x<50)&&(closest_x>-50))&&((closest_y<50)&&(closest_y>-50)))
				{
				b_position_x =20;
				play_sample(Smash, 255,128, 1000, 0);
				b_position_y =rand () %200+550;
				}
		}*/

		//PLAYER BASIS

		if (soldier_a.health > 0)
		{//collision
				if(fc_collision_a>5)
				{
					fc_collision_a=0;
			closest_x = soldier_a.position_y-soldier_f.bullet_1[0];
			closest_y = soldier_a.position_y-soldier_f.bullet_1[1];
				if (((closest_x<8)&&(closest_x>-8))&&((closest_y<45)&&(closest_y>-45)))
				{
					//Deal Damage
					soldier_a.health =soldier_a.health- soldier_f.damage;
					fc_collision_a = -15;
				}
			closest_x = soldier_a.position_y-soldier_f.bullet_2[0];
			closest_y = soldier_a.position_y-soldier_f.bullet_2[1];
				if (((closest_x<8)&&(closest_x>-8))&&((closest_y<45)&&(closest_y>-45)))
				{
					//Deal Damage
					fc_collision_a = -15;
					soldier_a.health =soldier_a.health- soldier_f.damage;
				} 
			closest_x = soldier_a.position_y-soldier_f.bullet_3[0];
			closest_y = soldier_a.position_y-soldier_f.bullet_3[1];
				if (((closest_x<8)&&(closest_x>-8))&&((closest_y<45)&&(closest_y>-45)))
				{
					//Deal Damage 
					fc_collision_a = -15;
					soldier_a.health =soldier_a.health- soldier_f.damage;
				}
			}
			//Lets Shoot And Render
			if (framecounter_bullet >25)
			{
				if(key[KEY_SPACE]) 
				{
					//begin slash
					//animationcount++;
					//Sound
					//play_sample(Slash, 128,128, 1000, 0);
					//framecounter_bullet=0;
 					if (soldier_a.bullet_t < 3)
					{
					soldier_a.bullet_t++;
					int i = soldier_a.bullet_t;
					if(soldier_a.bullet_1[0] == 1001)
					{
						soldier_a.bullet_1[1] = soldier_a.position_y;
						soldier_a.bullet_1[0] = soldier_a.position_x + 1;
					}
					else
					{
						if(soldier_a.bullet_2[0] == 1001)
						{
						soldier_a.bullet_2[1] = soldier_a.position_y;
						soldier_a.bullet_2[0] = soldier_a.position_x + 1;
						}
						else
						{
							if(soldier_a.bullet_3[0] == 1001)
							{
							soldier_a.bullet_3[1] = soldier_a.position_y;
							soldier_a.bullet_3[0] = soldier_a.position_x + 1;
							}
							else
							{
								switch (i)
								{ 
								case 1 : soldier_a.bullet_1[1] = soldier_a.position_y;
										 soldier_a.bullet_1[0] = soldier_a.position_x + 1;
									break;
								case 2 : soldier_a.bullet_2[1] = soldier_a.position_y;
										 soldier_a.bullet_2[0] = soldier_a.position_x + 1;
									break;
								case 3 : soldier_a.bullet_3[1] = soldier_a.position_y;
										 soldier_a.bullet_3[0] = soldier_a.position_x + 1;
									break;
								}
							}
						}
					}
					framecounter_bullet=0;
					i=0;
				}
			}

		}	
		}
			
		masked_blit(warrior_1, buffer, 0,0,soldier_a.position_x,soldier_a.position_y, warrior_3->w, warrior_3->h);


		//Enemy BASIS
 		if (soldier_f.health > 0)
		{//collision
				if(fc_collision_f>5)
				{
					fc_collision_f=0;
			closest_x = soldier_f.position_y-soldier_a.bullet_1[0];
			closest_y = soldier_f.position_y-soldier_a.bullet_1[1];
				if (((closest_x<8)&&(closest_x>-8))&&((closest_y<45)&&(closest_y>-45)))
				{
					//Deal Damage
					soldier_f.health =soldier_f.health- soldier_a.damage;
					fc_collision_f = -15;
				}
			closest_x = soldier_f.position_y-soldier_a.bullet_2[0];
			closest_y = soldier_f.position_y-soldier_a.bullet_2[1];
				if (((closest_x<8)&&(closest_x>-8))&&((closest_y<45)&&(closest_y>-45)))
				{
					//Deal Damage
					soldier_f.health =soldier_f.health- soldier_a.damage;
					fc_collision_f = -15;
				} 
			closest_x = soldier_f.position_y-soldier_a.bullet_3[0];
			closest_y = soldier_f.position_y-soldier_a.bullet_3[1];
				if (((closest_x<8)&&(closest_x>-8))&&((closest_y<45)&&(closest_y>-45)))
				{
					//Deal Damage 
					soldier_f.health =soldier_f.health- soldier_a.damage;
					fc_collision_f = -15;
				}
			}
			//Lets Shoot And Render
			if (framecounter_bullet >25)
			{
				if(framecounter_bullet2 >50)
				{
					//begin slash
					//animationcount++;
					//Sound
					//play_sample(Slash, 128,128, 1000, 0);
					//framecounter_bullet=0;
 					if (soldier_f.bullet_t < 3)
					{
					soldier_f.bullet_t++;
					int i = soldier_f.bullet_t;
					if(soldier_f.bullet_1[0] == 1001)
					{
						soldier_f.bullet_1[1] = soldier_a.position_y;
						soldier_f.bullet_1[0] = soldier_a.position_x + 1;
					}
					else
					{
						if(soldier_f.bullet_2[0] == 1001)
						{
						soldier_f.bullet_2[1] = soldier_a.position_y;
						soldier_f.bullet_2[0] = soldier_a.position_x + 1;
						}
						else
						{
							if(soldier_f.bullet_3[0] == 1001)
							{
							soldier_f.bullet_3[1] = soldier_f.position_y;
							soldier_f.bullet_3[0] = soldier_f.position_x + 1;
							}
							else
							{
								switch (i)
								{ 
								case 1 : soldier_f.bullet_1[1] = soldier_f.position_y;
										 soldier_f.bullet_1[0] = soldier_f.position_x + 1;
									break;
								case 2 : soldier_f.bullet_2[1] = soldier_f.position_y;
										 soldier_f.bullet_2[0] = soldier_f.position_x + 1;
									break;
								case 3 : soldier_f.bullet_3[1] = soldier_f.position_y;
										 soldier_f.bullet_3[0] = soldier_f.position_x + 1;
									break;
								}
							}
						}
					}
					framecounter_bullet2=0;
					i=0;
				}
			}

		}	
		}

		masked_blit(soldier_f_1, buffer, 0,0,soldier_f.position_x,soldier_f.position_y, soldier_f_1->w, soldier_f_1->h);

		




		//ALLY BASIS

			//Enemy Spawn Point

			//Move the Enemy

			//Check for collision
				//Deal Damage 

			//Check Health
				//Kill Or Live
		
			//If Live - Render

			//Enemy to shoot or not
		if (soldier_f.bullet_t >-1)
		{
			soldier_f.bullet_1[0] += 1;
			masked_blit(bullet_f, buffer, 0,0,soldier_f.bullet_1[0],soldier_f.bullet_1[1], bullet_f->w, bullet_f->h);
		}
		if (soldier_f.bullet_t >2)
		{
			soldier_f.bullet_2[0] += 1;
			masked_blit(bullet_f, buffer, 0,0,soldier_f.bullet_2[0],soldier_f.bullet_2[1], bullet_f->w, bullet_f->h);
		}
		if (soldier_f.bullet_t >3)
		{
			soldier_f.bullet_3[0] += 1;
			masked_blit(bullet_f, buffer, 0,0,soldier_f.bullet_3[0],soldier_f.bullet_3[1], bullet_f->w, bullet_f->h);
		}
		//Player Bullet
		if (soldier_a.bullet_t >=1)
		{
			if (soldier_a.bullet_1[0] < 1000)
			{
 			soldier_a.bullet_1[0] += 1;
			masked_blit(bullet_a, buffer, 0,0,soldier_a.bullet_1[0],soldier_a.bullet_1[1], bullet_a->w, bullet_a->h);
			}
		}
		if (soldier_a.bullet_t >=2)
		{
			if (soldier_a.bullet_2[0] < 1000)
			{
			soldier_a.bullet_2[0] += 1;
			masked_blit(bullet_a, buffer, 0,0,soldier_a.bullet_2[0],soldier_a.bullet_2[1], bullet_a->w, bullet_a->h);
			}
		}
		if (soldier_a.bullet_t >=3)
		{
			if (soldier_a.bullet_3[0] < 1000)
			{
			soldier_a.bullet_3[0] += 1;
			masked_blit(bullet_a, buffer, 0,0,soldier_a.bullet_3[0],soldier_a.bullet_3[1], bullet_a->w, bullet_a->h);
			}
		}





		
			if (soldier_a.bullet_1[0] == 1000)
			{
				soldier_a.bullet_t--;
				soldier_a.bullet_1[0]++;

			}
			if (soldier_a.bullet_2[0] == 1000)
			{
 				soldier_a.bullet_t--;
				soldier_a.bullet_2[0]++;
			}
			if (soldier_a.bullet_3[0] == 1000)
			{
				soldier_a.bullet_t--;
				soldier_a.bullet_3[0]++;
			}
		








		

		/*
		for (int i=0; i<soldier_a.bullet_t; i++)
		{
			soldier_a.bullet_x[i]--; 
			masked_blit(bullet_a, buffer, 0,0,soldier_a.bullet_x[i],soldier_a.bullet_y[i], bullet_a->w, bullet_a->h);
		}
		for (int i=0; i<soldier_f.bullet_t; i++)
		{
			soldier_f.bullet_x[i]++; 
			masked_blit(bullet_f, buffer, 0,0,soldier_f.bullet_x[i],soldier_f.bullet_y[i], bullet_f->w, bullet_f->h);
		}*/
		


		//Base Collision Check
		/*
		if (b_position_x >700)
		{
			hit_base++;
			//play_sample(Crash, 255,128, 1000, 0);
			b_position_x =20;
			b_position_y =rand () %200+550;
		}
		else 
		{
			masked_blit(boulder, buffer, 0,0,b_position_x,b_position_y, boulder->w, boulder->h);
		}
		*/


		//ANIMATION SUITE
		switch (animationcount)
		{
		case 1 : masked_blit(warrior_3, buffer, 0,0,soldier_a.position_x,soldier_a.position_y, warrior_3->w, warrior_3->h);
			break;
		default : 
			break; 
		}
		//BULLET RENDERED

		/*if ( soldier_a.bullet_t == 1)
		{
			soldier_a.bullet_x = soldier_a.bullet_x - 1;
			masked_blit(bullet_a, buffer, 0,0,soldier_a.bullet_x,soldier_a.bullet_y, bullet_a->w, bullet_a->h);
		}*/
		
		//if ( soldier_f.bullet_t == 1)
		{
			//soldier_f.bullet_x = soldier_f.bullet_x + 1;
			//masked_blit(bullet_f, buffer, 0,0,soldier_f.bullet_x,soldier_f.bullet_y, bullet_f->w, bullet_f->h);
		}


		//Collision Checking
		blit(buffer, screen, 0,0,0,0, buffer->w, buffer->h);
		clear_bitmap(buffer);

		/*closest_x = soldier_a.bullet_x-b_position_x;
		closest_y = soldier_a.bullet_y-b_position_y;
		if (((closest_x<50)&&(closest_x>-50))&&((closest_y<50)&&(closest_y>-50)))
		{
			b_position_x =20;
			//play_sample(Smash, 255,128, 1000, 0);
			b_position_y =rand () %200+550;
			
		}
		*/
		framecounter_bullet++;
		framecounter_bullet2++;
		framecounter_soldier_f++;
		fc_collision_a++;
		fc_collision_f++;
	}


	blit(Background_11, screen, 0,0,0,0, Background_11->w, Background_11->h);
	rest(1500);


	
	deinit();
	return 0;
} /* end of Normal main */

END_OF_MAIN()     /* line must be included at the end of the nor 


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

void deinit() 
{
	clear_keybuf();
	/* add other deinitializations here */
}

void update(void)
{
	

	if(framecounter == 1)
	{
		//enemy move
		//b_position_x +=5;
		framecounter =0;
	} 
	else
	{
		framecounter++;

	}
}


/* End of Template.c */
