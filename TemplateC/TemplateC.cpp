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



enum BitmapName
{
	kWarrior,
	kWarrior1,
	kLast
};
const char* filenames[] =
{
	"WarriorKillerBitmap.bmp",
	"WarriorKiller1Bitmap.bmp",
	"!ijefoiew"
};

BITMAP* bitmaps[kLast] = {0};

class Soldier2
{
public:
	Soldier2()
	{
		position_x=520;
		position_y=560;
		health =100;
		damage =200;
	}
	int getHealth(void)
	{
		return health;
	}
	int getPosition(char x)
	{
		if(x=='x')
		{
			return position_x;
		}
		if(x=='y')
		{
			return position_y;
		}
		else
		{
			return 0;
		}
	}
	int isShot(int x, int y)
	{
		int r_x;
		int r_y;
		r_x=position_x-x;
		r_y=position_y-y;
		if (((r_x<8)&&(r_x>-8))&&((r_y<45)&&(r_y>-45)))
		{
			health-=damage;
			return 1;
		}
		else
		{
			return 0;
		}
	}
private:
	int health;
	int position_x;
	int position_y;
	int damage;
};

//Structures
struct Soldier
{
	int health;
	int position_x;
	int position_y;
	int bullet_t;
	int bullet_1[2];
	int damage;
	//BitmapName bitmap;
	//void draw()
	//{
	//masked_blit(bitmaps[bitmap], buffer, 40,36,soldier_a.position_x,soldier_a.position_y, 31, 34);
	//}
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
int AiGenerator(void);
void update(void);
int main() 
{  /* start of main */
	unsigned seed = time(0);
	srand(seed);

	Matrix2 g_transform;
	std::vector<Matrix2> g_bulletTM;



	//Assets
	SAMPLE *Crash;
	SAMPLE *Slash;
	SAMPLE *Smash;
	SAMPLE *Music;


	for(int i =0; i < kLast; ++i)
	{
		bitmaps[i] =load_bitmap(filenames[i], 0);
	}

	//masked_blit(bitmaps[kWarrior], kjdpoqkfewpw, );

	BITMAP * warrior;
	BITMAP * warrior_1;
	BITMAP * warrior_2;
	BITMAP * warrior_3;
	BITMAP * soldier_f_bmp;
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
	int fc_bullet[6] = {0,0,0,0,0,0};
	int fc_collision[6]={0,0,0,0,0,0};
	//random-ness
	b_position_x =20;
	b_position_y =rand () %200+550;
	float base_x_position =0;
	int hit_base =1;
	int animationcount =0;
	int closest_x;
	int closest_y;
	//Bullet for Frank
	int bullet_x[1]={1200};
	int bullet_y[1]={1200};
	int bullet_t[6]={0,0,0,0,0,0};
	//Frank
	Soldier2 s_a_2;
	//init
	init();
	framecounter=0;
	install_int(update,5);
	warrior=load_bitmap("WarriorKillerBitmap.bmp",NULL);
	warrior_1=load_bitmap("Soldier-SpriteSheet.bmp",NULL);
	warrior_2=load_bitmap("WarriorKillerBitmap_2.bmp",NULL);
	warrior_3=load_bitmap("WarriorKillerBitmap_3.bmp",NULL);
	soldier_f_bmp=load_bitmap("Soldier-SpriteSheet-2.bmp",NULL);
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
	//textprintf_ex(screen, font, 15, 15, 15, 15, "Press Enter to Play!"); 
	//bool flag=false;
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

		blit(Background02, buffer, 0,0,0,0, Background02->w, Background02->h);
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
			soldier_a.position_y+=+1.0;
		}
		if(key[KEY_W])
		{
			soldier_a.position_y+=-1.0;
		}
		if(key[KEY_P])
		{
			int x=soldier_a.health + soldier_f.health;
		}

		//PLAYER BASIS
		if (soldier_a.health > 0)
		{
			if (soldier_a.bullet_1[0] < 0)
			{
				bullet_t[1]=0;
			}
			if(fc_collision[0]>5)
			{
				fc_collision[0]=0;
				closest_x = soldier_a.position_y-soldier_f.bullet_1[0];
				closest_y = soldier_a.position_y-soldier_f.bullet_1[1];
				if (((closest_x<8)&&(closest_x>-8))&&((closest_y<45)&&(closest_y>-45)))
				{
					//Deal Damage
					soldier_a.health =soldier_a.health- soldier_f.damage;
					bullet_t[3]=0;
					fc_collision[0] = -15;
				}
				closest_x = soldier_a.position_y-soldier_f_1.bullet_1[0];
				closest_y = soldier_a.position_y-soldier_f_1.bullet_1[1];
				if (((closest_x<8)&&(closest_x>-8))&&((closest_y<45)&&(closest_y>-45)))
				{
					//Deal Damage
					soldier_a.health =soldier_a.health- soldier_f_1.damage;
					bullet_t[4]=0;
					fc_collision[0] = -15;
				}
				closest_x = soldier_a.position_y-soldier_f_2.bullet_1[0];
				closest_y = soldier_a.position_y-soldier_f_2.bullet_1[1];
				if (((closest_x<8)&&(closest_x>-8))&&((closest_y<45)&&(closest_y>-45)))
				{
					//Deal Damage
					soldier_a.health =soldier_a.health- soldier_f_2.damage;
					bullet_t[5]=0;
					fc_collision[0] = -15;
				}
			}
			//Lets Shoot And Render
			if (fc_bullet[0] >25)
			{
				if(key[KEY_SPACE]) 
				{
					if (bullet_t[1]==0)
					{
						bullet_t[1]=1;
						soldier_a.bullet_1[1] = soldier_a.position_y;
						soldier_a.bullet_1[0] = soldier_a.position_x + 1;			
						fc_bullet[0]=0;
					}
				}		
			}
			masked_blit(warrior_1, buffer, 40,36,soldier_a.position_x,soldier_a.position_y, 31, 34);
		}
		//ALLY BASIS
		if (soldier_a_1.health > 0)
		{ 
			if (soldier_a_1.bullet_1[0] < 0)
			{
				bullet_t[2]=0;
			}
			if(fc_collision[1] >5)
			{
				fc_collision[1]=0;
				closest_x = soldier_a_1.position_x-soldier_f.bullet_1[0];
				closest_y = soldier_a_1.position_y-soldier_f.bullet_1[1];
				if (((closest_x<8)&&(closest_x>-8))&&((closest_y<45)&&(closest_y>-45)))
				{
					//Collision with enemy 1 bullet
					soldier_a_1.health =soldier_a_1.health- soldier_f.damage;
					fc_collision[1] = -15;
					bullet_t[3]=0;
				}
				closest_x = soldier_a_1.position_x-soldier_f_1.bullet_1[0];
				closest_y = soldier_a_1.position_y-soldier_f_1.bullet_1[1];
				if (((closest_x<8)&&(closest_x>-8))&&((closest_y<45)&&(closest_y>-45)))
				{
					//Collision with enemy 2 bullet
					soldier_a_1.health =soldier_a_1.health- soldier_f_1.damage;
					fc_collision[1] = -15;
					bullet_t[4]=0;
				}
				closest_x = soldier_a_1.position_x-soldier_f_2.bullet_1[0];
				closest_y = soldier_a_1.position_y-soldier_f_2.bullet_1[1];
				if (((closest_x<8)&&(closest_x>-8))&&((closest_y<45)&&(closest_y>-45)))
				{
					//Collision with enemy 3 bullet
					soldier_a_1.health =soldier_a_1.health- soldier_f_2.damage;
					fc_collision[1] = -15;
					bullet_t[5]=0;
				}
			}
			if(fc_bullet[1]>50)
			{
				int i =AiGenerator();
				switch(i)
				{
				case 1:
				case 2:
				case 3:
					if (bullet_t[2]==0)
					{
						bullet_t[2]=1;
						soldier_a_1.bullet_1[1] = soldier_a_1.position_y;
						soldier_a_1.bullet_1[0] = soldier_a_1.position_x - 1;
					}
					break;
				case 4:
					break;
				case 5: //crouch
					break;
				default:
					break;
				}
				fc_bullet[1]=0;
			}
			masked_blit(warrior_1, buffer, 40,36,soldier_a_1.position_x,soldier_a_1.position_y, 31, 34);
		}


		//Enemy 1 BASIS
		if (soldier_f.health > 0)
		{ 
			if (soldier_f.bullet_1[0] > 1500)
			{
				bullet_t[3]=0;
			}
			if(fc_collision[2]>5)
			{
				fc_collision[2]=0;
				closest_x = soldier_f.position_x-soldier_a.bullet_1[0];
				closest_y = soldier_f.position_y-soldier_a.bullet_1[1];
				if (((closest_x<8)&&(closest_x>-8))&&((closest_y<45)&&(closest_y>-45)))
				{
					//collision with P bullet
					soldier_f.health =soldier_f.health- soldier_a.damage;
					bullet_t[1]=0;
					fc_collision[2] = -15;
				}
				closest_x = soldier_f.position_x-soldier_a_1.bullet_1[0];
				closest_y = soldier_f.position_y-soldier_a_1.bullet_1[1];
				if (((closest_x<8)&&(closest_x>-8))&&((closest_y<45)&&(closest_y>-45)))
				{
					//Collision with Ally Bullet
					soldier_f.health =soldier_f.health- soldier_a_1.damage;
					bullet_t[2]=0;
					fc_collision[2] = -15;
				}
			}
			if(fc_bullet[2]>20)
			{
				int i =AiGenerator();
				switch(i)
				{
				case 1 :
				case 2: 
					if (bullet_t[3]==0)
					{
						bullet_t[3]=1;
						soldier_f.bullet_1[1] = soldier_f.position_y;
						soldier_f.bullet_1[0] = soldier_f.position_x + 1;
					}
					break;
				case 3: soldier_f.position_x += 2;
					break;
				case 4: soldier_f.position_y += 1;
					break;
				case 5: soldier_f.position_x += 2;
					break;
				case 6: soldier_f.position_y += -1;
					break;
				default:
					break;
				}
				fc_bullet[2]=0;
			}
			masked_blit(soldier_f_bmp, buffer, 455,525,soldier_f.position_x,soldier_f.position_y, 47, 43);
		}

		//Enemy 2 BASIS
		if (soldier_f_1.health > 0)
		{ 
			if (soldier_f_1.bullet_1[0] > 2000)
			{
				bullet_t[4]=0;
			}
			if(fc_collision[3] >5)
			{
				fc_collision[3]=0;
				closest_x = soldier_f_1.position_x-soldier_a.bullet_1[0];
				closest_y = soldier_f_1.position_y-soldier_a.bullet_1[1];
				if (((closest_x<8)&&(closest_x>-8))&&((closest_y<45)&&(closest_y>-45)))
				{
					//Collision with P bullet
					soldier_f_1.health =soldier_f_1.health- soldier_a.damage;
					fc_collision[3] = -15;
					bullet_t[1]=0;
				}
				closest_x = soldier_f_1.position_x-soldier_a_1.bullet_1[0];
				closest_y = soldier_f_1.position_y-soldier_a_1.bullet_1[1];
				if (((closest_x<8)&&(closest_x>-8))&&((closest_y<45)&&(closest_y>-45)))
				{
					//Collision with ally bullet
					soldier_f_1.health =soldier_f_1.health- soldier_a_1.damage;
					fc_collision[3] = -15;
					bullet_t[2]=0;
				}
			}
			if(fc_bullet[3]>20)
			{
				int i =AiGenerator();
				switch(i)
				{
				case 1:
				case 2: 
					if (bullet_t[4]==0)
					{
						bullet_t[4]=1;
						soldier_f_1.bullet_1[1] = soldier_f_1.position_y;
						soldier_f_1.bullet_1[0] = soldier_f_1.position_x + 1;
					}
					break;
				case 3:	soldier_f_1.position_x += 1;
					break;
				case 4: soldier_f_1.position_y += 1;
					break;
				case 5: soldier_f_1.position_x += 1;
					break;
				case 6: soldier_f_1.position_y += -1;
					break;
				default:
					break;
				}
				fc_bullet[3]=0;
			}
			masked_blit(soldier_f_bmp, buffer, 455,525,soldier_f_1.position_x,soldier_f_1.position_y, 47, 43);
		}


		//Enemy 3 BASIS
		if (soldier_f_2.health > 0)
		{ 
			if (soldier_f_2.bullet_1[0] > 2000)
			{
				bullet_t[5]=0;
			}
			if(fc_collision[4] >5)
			{
				fc_collision[4]=0;
				closest_x = soldier_f_2.position_x-soldier_a.bullet_1[0];
				closest_y = soldier_f_2.position_y-soldier_a.bullet_1[1];
				if (((closest_x<8)&&(closest_x>-8))&&((closest_y<45)&&(closest_y>-45)))
				{
					//Collision with P bullet
					soldier_f_2.health =soldier_f_1.health- soldier_a.damage;
					fc_collision[4] = -15;
					bullet_t[1]=0;
				}
				closest_x = soldier_f_2.position_x-soldier_a_1.bullet_1[0];
				closest_y = soldier_f_2.position_y-soldier_a_1.bullet_1[1];
				if (((closest_x<8)&&(closest_x>-8))&&((closest_y<45)&&(closest_y>-45)))
				{
					//Collision with ally bullet
					soldier_f_2.health =soldier_f_2.health- soldier_a_1.damage;
					fc_collision[4] = -15;
					bullet_t[5]=0;
				}
			}
			if(fc_bullet[4]>20)
			{
				int i =AiGenerator();
				switch(i)
				{
				case 1 :
				case 2: 
					if (bullet_t[5]==0)
					{
						bullet_t[5]=1;
						soldier_f_2.bullet_1[1] = soldier_f_2.position_y;
						soldier_f_2.bullet_1[0] = soldier_f_2.position_x + 1;
					}
					break;
				case 3: soldier_f_2.position_x += 1;
					break;
				case 4: soldier_f_2.position_y += 1;
					break;
				case 5: soldier_f_2.position_x += 1;
					break;
				case 6: soldier_f_2.position_y += -1;
					break;
				default:
					break;
				}
				fc_bullet[4]=0;
			}
			masked_blit(soldier_f_bmp, buffer, 455,525,soldier_f_2.position_x,soldier_f_2.position_y, 47, 43);
		}
		//Enemy 4 BASIS
		if (soldier_f_3.health > 0)
		{ 
			if (soldier_f_3.bullet_1[0] > 2000)
			{
				bullet_t[6]=0;
			}
			if(fc_collision[5] >5)
			{
				fc_collision[5]=0;
				closest_x = soldier_f_3.position_x-soldier_a.bullet_1[0];
				closest_y = soldier_f_3.position_y-soldier_a.bullet_1[1];
				if (((closest_x<8)&&(closest_x>-8))&&((closest_y<45)&&(closest_y>-45)))
				{
					//Collision with P bullet
					soldier_f_3.health =soldier_f_3.health- soldier_a.damage;
					fc_collision[5] = -15;
					bullet_t[1]=0;
				}
				closest_x = soldier_f_3.position_x-soldier_a_1.bullet_1[0];
				closest_y = soldier_f_3.position_y-soldier_a_1.bullet_1[1];
				if (((closest_x<8)&&(closest_x>-8))&&((closest_y<45)&&(closest_y>-45)))
				{
					//Collision with ally bullet
					soldier_f_3.health =soldier_f_3.health- soldier_a_1.damage;
					fc_collision[5] = -15;
					bullet_t[6]=0;
				}
			}
			if(fc_bullet[4]>20)
			{
				int i =AiGenerator();
				switch(i)
				{
				case 1 :
				case 2: 
					if (bullet_t[6]==0)
					{
						bullet_t[6]=1;
						soldier_f_3.bullet_1[1] = soldier_f_3.position_y;
						soldier_f_3.bullet_1[0] = soldier_f_3.position_x + 1;
					}
					break;
				case 3: soldier_f_3.position_x += 1;
					break;
				case 4: soldier_f_3.position_y += 1;
					break;
				case 5: soldier_f_3.position_x += 1;
					break;
				case 6: soldier_f_3.position_y += -1;
					break;
				default:
					break;
				}
				fc_bullet[4]=0;
			}
			masked_blit(soldier_f_bmp, buffer, 455,525,soldier_f_3.position_x,soldier_f_3.position_y, 47, 43);
		}


		if(s_a_2.getHealth() > 0)
		{
			if (s_a_2.isShot(bullet_x[0], bullet_y[0]) == 1)
			{
				//Shot
			}
			if(fc_bullet[5]>20)
			{
				int i =AiGenerator();
				switch(i)
				{
				case 1 :
				case 2: 
					if (bullet_t[0]==0)
					{
						bullet_x[0]=s_a_2.getPosition('x');
						bullet_y[0]=s_a_2.getPosition('y');
						bullet_t[0]=1;
					}
					break;
				case 3: soldier_f_3.position_x += 1;
					break;
				case 4: soldier_f_3.position_y += 1;
					break;
				case 5: soldier_f_3.position_x += 1;
					break;
				case 6: soldier_f_3.position_y += -1;
					break;
				default:
					break;
				}
				fc_bullet[5]=0;
			}
		}


			for( int i=0; i<sizeof(bullet_t); i++)
			{
				if ((bullet_t[i]==1) && (bullet_x[i] < 1500))
				{
					bullet_x[i]++;
					masked_blit(bullet_a, buffer, 0,0,bullet_x[i],bullet_y[0], bullet_f->w, bullet_f->h);
				}
			}








			//Bullet System
			if ((bullet_t[1]==1) && (soldier_a.bullet_1[0] < 1500))
			{
				soldier_a.bullet_1[0]+=-2;
				masked_blit(bullet_a, buffer, 0,0,soldier_a.bullet_1[0],soldier_a.bullet_1[1], bullet_f->w, bullet_f->h);
			}
			if ((bullet_t[2]==1) && (soldier_a_1.bullet_1[0] < 1500))
			{
				soldier_a_1.bullet_1[0]+=-2;
				masked_blit(bullet_a, buffer, 0,0,soldier_a_1.bullet_1[0],soldier_a_1.bullet_1[1], bullet_f->w, bullet_f->h);
			}
			if ((bullet_t[3]==1) && (soldier_f.bullet_1[0] < 1500))
			{
				soldier_f.bullet_1[0] +=2;
				masked_blit(bullet_f, buffer, 0,0,soldier_f.bullet_1[0],soldier_f.bullet_1[1], bullet_f->w, bullet_f->h);
			}
			if ((bullet_t[4]==1) && (soldier_f_1.bullet_1[0] < 1500))
			{
				soldier_f_1.bullet_1[0] +=2;
				masked_blit(bullet_f, buffer, 0,0,soldier_f_1.bullet_1[0],soldier_f_1.bullet_1[1], bullet_f->w, bullet_f->h);
			}
			if ((bullet_t[5]==1) && (soldier_f_2.bullet_1[0] < 1500))
			{
				soldier_f_2.bullet_1[0] +=2;
				masked_blit(bullet_f, buffer, 0,0,soldier_f_2.bullet_1[0],soldier_f_2.bullet_1[1], bullet_f->w, bullet_f->h);
			}
			if ((bullet_t[6]==1) && (soldier_f_3.bullet_1[0] < 1500))
			{
				soldier_f_3.bullet_1[0] +=2;
				masked_blit(bullet_f, buffer, 0,0,soldier_f_3.bullet_1[0],soldier_f_3.bullet_1[1], bullet_f->w, bullet_f->h);
			}

			//Base Collision Check

			//if (b_position_x >700)
			//{
			//	hit_base++;
			//	//play_sample(Crash, 255,128, 1000, 0);
			//	b_position_x =20;
			//	b_position_y =rand () %200+550;
			//}
			//else 
			//{
			//	masked_blit(boulder, buffer, 0,0,b_position_x,b_position_y, boulder->w, boulder->h);
			//}
			//ANIMATION SUITE



			blit(buffer, screen, 0,0,0,0, buffer->w, buffer->h);
			clear_bitmap(buffer);
			//FrameCounters -  Note May need to start at -1
			for( int i=0; i<sizeof(fc_collision); i++)
			{
				fc_collision[i]++;
				fc_bullet[i]++;
			}
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

	int AiGenerator()
	{
		int i =0;
		unsigned seed = time(NULL);
		i =	rand() % 5 + 1;
		return i;
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
