#include <allegro.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "cgg/Matrix2.h"
#include "cgg/Transform2.h"
#include "SoldierClass.h"
#include "AI.h"
#include "Bullet.h"






//void play() 
//{  /* start of main */
//
//	//Player
//	Soldier2 s_p;
//	s_p.setPosition(1030,660);
//	//s_p.setPostion(rand () %700+500,rand () %1100+800);
//	//Jenkins
//	Soldier2 s_a_1;
//	s_a_1.setPosition(1160,200);
//	//s_a_1.setPostion(rand () %200+1,rand () %1100+800);
//	//Frank
//	Soldier2 s_a_2;
//	s_a_2.setPosition(1080,620);
//	//s_a_2.setPostion(rand()%200+550,rand () %1100+800);
//	//Frank
//	Soldier2 s_a_3;
//	s_a_3.setPosition(1000,580);
//	//s_a_2.setPostion(rand()%200+550,rand () %1100+800);
//	//Tony
//	Soldier2 s_f_1;
//	s_f_1.setPosition(100,510);
//	//s_f_1.setPostion(rand()%200+550,rand () %400+1);
//	//Rico
//	Soldier2 s_f_2;
//	s_f_2.setPosition(150,550);
//	//s_f_2.setPostion(rand()%200+550,rand () %400+1);
//	//Jeffery
//	Soldier2 s_f_3;
//	s_f_3.setPosition(200,540);
//	//s_f_3.setPostion(rand()%200+550,rand () %400+1);
//	//Gomez
//	Soldier2 s_f_4;
//	s_f_4.setPosition(150,610);
//	//s_f_4.setPostion(rand()%200+550,rand () %400+1);
//
//	//install_int(update,5);
//
//	warrior=load_bitmap("WarriorKillerBitmap.bmp",NULL);
//	warrior_1=load_bitmap("Soldier-SpriteSheet.bmp",NULL);
//	warrior_1right=load_bitmap("Soldier-SpriteSheetwalkright.bmp",NULL);
//	bullet_a=load_bitmap("bullet_a.bmp", NULL);
//	bullet_f=load_bitmap("bullet_f.bmp", NULL);
//	bullet_a=load_bitmap("bullet_a.bmp", NULL);
//	bullet_f=load_bitmap("bullet_f.bmp", NULL);
//	Background02=load_bitmap("BG-Style-1.bmp",NULL);
//	Background_2=load_bitmap("BG-Style-1",NULL);
//	blit(Background02, screen, 0,0,0,0, Background02->w, Background02->h);
//	rest(2500);
//
//	//textprintf_ex(screen, font, 15, 15, 15, 15, "Press Enter to Play!"); 
//	//bool flag=false;
//	/*
//	do
//	{
//
//	int test = readkey () & 0xFF;
//	if(test == 0x0D)
//	{
//	flag=true;
//	}
//	else
//	{
//	textprintf_ex(screen, font, 15, 15, 15, 1, "Press Enter to Play!"); 
//	}
//	}
//	while( flag==false);
//	*/
//
//
//	while (!key[KEY_ESC])
//	{
//
//		blit(Background02, buffer, 0,0,0,0, Background02->w, Background02->h);
//
//		//Key Presses
//		if(key[KEY_A])
//		{											//int &animatecounter, int &imagenum)
//			s_p.addPosition('x', -1);
//			animate(warrior_1, buffer, 75, 74, s_p.getPositionX(), s_p.getPositionY(), animatecounter[0], imagenum[0]);
//		}
//		else
//		if(key[KEY_D])
//		{
//			s_p.addPosition('x', 1);
//			animate(warrior_1right, buffer, 75, 74, s_p.getPositionX(), s_p.getPositionY(), animatecounter[0], imagenum[0]);
//		}
//		else
//		if(key[KEY_S])
//		{
//			s_p.addPosition('y',1);	
//			animate(warrior_1, buffer, 75, 74, s_p.getPositionX(), s_p.getPositionY(), animatecounter[0], imagenum[0]);
//		}
//		else
//		if(key[KEY_W])
//		{
//			s_p.2('y',-1);
//			animate(warrior_1, buffer, 75, 74, s_p.getPositionX(), s_p.getPositionY(), animatecounter[0], imagenum[0]);
//		}
//		else
//		if(key[KEY_P])
//		{
//		}	
//
//		if(!(key[KEY_A]) && !(key[KEY_D]) && !(key[KEY_W]) && !(key[KEY_S]))
//		{
//			am_i_moving(0);
//			masked_blit(warrior_1, buffer, 40, 74,s_p.getPositionX(),s_p.getPositionY(), 31, 34);
//		}
//
//		//Player System
//		if(s_p.getHealth() > 0)
//		{
//			if(fc_collision[0] >5)
//			{
//				fc_collision[0]=0;
//				for( int i=0; i<sizeof(bullet_x); i++)
//				{
//					if (s_p.isShot(bullet_x[i], bullet_y[i]) == 1)
//					{
//						fc_collision[0]=-15;
//					}
//				}
//			}
//			if(key[KEY_SPACE]) 
//			{
//				if ((bullet_t[0]==0)&&(fc_bullet[0]>20))
//				{
//					bullet_x[0]=s_p.getPositionX()+10;
//					bullet_y[0]=s_p.getPositionY();
//					bullet_t[0]=1;
//					fc_bullet[0]=0;
//				}
//			}
//		}
//		//ALLY NUM 1 System
//		
//		//ALLY System
//		if(s_a_2.getHealth() > 0)
//		{
//			if(fc_collision[1] >5)
//			{
//				fc_collision[1]=0;
//				for( int i=0; i<sizeof(bullet_x); i++)
//				{
//					if (s_a_2.isShot(bullet_x[i], bullet_y[i]) == 1)
//					{
//						fc_collision[1]=-15;
//					}
//				}
//			}
//			if(fc_bullet[2]>20)
//			{
//				int i =AiGenerator();
//				switch(i)
//				{
//				case 1 :
//				case 2: 
//					if (bullet_t[2]==0)
//					{
//						bullet_x[2]=s_a_2.getPositionX()-10;
//						bullet_y[2]=s_a_2.getPositionY();
//						bullet_t[2]=1;
//					}
//					break;
//				case 3: 
//					break;
//				case 4: 
//					break;
//				case 5: 
//					break;
//				case 6:
//					break;
//				default:
//					break;
//				}
//				fc_bullet[2]=0;
//			}
//			masked_blit(warrior_1, buffer, 40,36,s_a_2.getPositionX(),s_a_2.getPositionY(), 31, 34);
//		}
//		//ALLY BASIS 3
//		if(s_a_3.getHealth() > 0)
//		{
//			if(fc_collision[3] >5)
//			{
//				fc_collision[3]=0;
//				for( int i=0; i<sizeof(bullet_x); i++)
//				{
//					if (s_a_3.isShot(bullet_x[i], bullet_y[i]) == 1)
//					{
//						fc_collision[3]=-15;
//					}
//				}
//			}
//			if(fc_bullet[3]>20)
//			{
//				int i =AiGenerator();
//				switch(i)
//				{
//				case 1 :
//				case 2: 
//					if (bullet_t[3]==0)
//					{
//						bullet_x[3]=s_a_3.getPositionX()-10;
//						bullet_y[3]=s_a_3.getPositionY();
//						bullet_t[3]=1;
//					}
//					break;
//				case 3: 
//					break;
//				case 4: 
//					break;
//				case 5: 
//					break;
//				case 6:
//					break;
//				default:
//					break;
//				}
//				fc_bullet[3]=0;
//			}
//			masked_blit(warrior_1, buffer, 40,36,s_a_3.getPositionX(),s_a_3.getPositionY(), 31, 34);
//		}
//		//Enemy 1 BASIS
//		if(s_f_1.getHealth() > 0)
//		{
//			if(fc_collision[4] >5)
//			{
//				fc_collision[4]=0;
//				for( int i=0; i<sizeof(bullet_x); i++)
//				{
//					if (s_f_1.isShot(bullet_x[i], bullet_y[i]) == 1)
//					{
//						fc_collision[4]=-15;
//					}
//				}
//			}
//			if(fc_bullet[4]>20)
//			{
//				int i =AiGenerator();
//				switch(i)
//				{
//				case 1 :
//				case 2: 
//					if (bullet_t[4]==0)
//					{
//						bullet_x[4]=s_f_1.getPositionX()-10;
//						bullet_y[4]=s_f_1.getPositionY();
//						bullet_t[4]=1;
//					}
//					break;
//				case 3: 
//					break;
//				case 4: 
//					break;
//				case 5: 
//					break;
//				case 6:
//					break;
//				default:
//					break;
//				}
//				fc_bullet[4]=0;
//			}
//			masked_blit(warrior_1, buffer, 40,36,s_f_1.getPositionX(),s_f_1.getPositionY(), 31, 34);
//		}
//		//enemy 2
//		if(s_f_2.getHealth() > 0)
//		{
//			if(fc_collision[5] >5)
//			{
//				fc_collision[5]=0;
//				for( int i=0; i <sizeof(bullet_x); i++)
//				{
//					if (s_f_2.isShot(bullet_x[i], bullet_y[i]) == 1)
//					{
//						fc_collision[5]=-15;
//					}
//				}
//			}
//			if(fc_bullet[5]>20)
//			{
//				int i =AiGenerator();
//				switch(i)
//				{
//				case 1 :
//				case 2: 
//					if (bullet_t[5]==0)
//					{
//						bullet_x[5]=s_f_2.getPositionX()-10;
//						bullet_y[5]=s_f_2.getPositionY();
//						bullet_t[5]=1;
//					}
//					break;
//				case 3: 
//					break;
//				case 4: 
//					break;
//				case 5: 
//					break;
//				case 6:
//					break;
//				default:
//					break;
//				}
//				fc_bullet[5]=0;
//			}
//			masked_blit(warrior_1, buffer, 40,36,s_f_2.getPositionX(),s_f_2.getPositionY(), 31, 34);
//		}
//		//enemy 3
//		if(s_f_3.getHealth() > 0)
//		{
//			if(fc_collision[6] >5)
//			{
//				fc_collision[6]=0;
//				for( int i=0; i <sizeof(bullet_x); i++)
//				{
//					if (s_f_3.isShot(bullet_x[i], bullet_y[i]) == 1)
//					{
//						fc_collision[6]=-15;
//					}
//				}
//			}
//			if(fc_bullet[6]>20)
//			{
//				int i =AiGenerator();
//				switch(i)
//				{
//				case 1 :
//				case 2: 
//					if (bullet_t[6]==0)
//					{
//						bullet_x[6]=s_f_3.getPositionX()-10;
//						bullet_y[6]=s_f_3.getPositionY();
//						bullet_t[6]=1;
//					}
//					break;
//				case 3: 
//					break;
//				case 4: 
//					break;
//				case 5: 
//					break;
//				case 6:
//					break;
//				default:
//					break;
//				}
//				fc_bullet[6]=0;
//			}
//			masked_blit(warrior_1, buffer, 40,36,s_f_3.getPositionX(),s_f_3.getPositionY(), 31, 34);
//		}
//		//enemy 4 
//		if(s_f_4.getHealth() > 0)
//		{
//			if(fc_collision[7] >5)
//			{
//				fc_collision[7]=0;
//				for( int i=0; i <sizeof(bullet_x); i++)
//				{
//					if (s_f_4.isShot(bullet_x[i], bullet_y[i]) == 1)
//					{
//						fc_collision[7]=-15;
//					}
//				}
//			}
//			if(fc_bullet[7]>20)
//			{
//				int i =AiGenerator();
//				switch(i)
//				{
//				case 1:
//				case 2: 
//					if (bullet_t[7]==0)
//					{
//						bullet_x[7]=s_f_4.getPositionX()-10;
//						bullet_y[7]=s_f_4.getPositionY();
//						bullet_t[7]=1;
//					}
//					break;
//				case 3: 
//					break;
//				case 4: 
//					break;
//				case 5: 
//					break;
//				case 6:
//					break;
//				default:
//					break;
//				}
//				fc_bullet[7]=0;
//			}
//			masked_blit(warrior_1, buffer, 40,36,s_f_4.getPositionX(),s_f_4.getPositionY(), 31, 34);
//		}
//		//BulletSpeeder/Rendered
//		for( int i=0; i<8; i++)
//		{
//
//			if ((bullet_t[i]==1) && (bullet_x[i] < 1500)&&(bullet_x[i] > 0))
//			{
//				if(i<4)
//				{
//				bullet_x[i]--;
//				}
//				else
//				{
//				bullet_x[i]++;
//				}
//				masked_blit(bullet_a, buffer, 0,0,bullet_x[i],bullet_y[i], bullet_a->w, bullet_a->h);
//			}
//			else
//			{
//				bullet_t[i]=0;
//			}
//		}
//
//		blit(buffer, screen, 0,0,0,0, buffer->w, buffer->h);
//		clear_bitmap(buffer);
//		//FrameCounters -  Note May need to start at -1
//		for( int i=0; i<8; i++)
//		{
//			fc_collision[i]++;
//			fc_bullet[i]++;
//		}
//	}
//	return 0;
//} /* end of Normal main */
//
//*/