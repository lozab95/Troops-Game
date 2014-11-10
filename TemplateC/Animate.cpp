
#include <allegro.h>



void main()
{
if(s_a_1.getHealth() > 0)
		{
			if(fc_collision[1] >5)
			{
				fc_collision[1]=0;
				for( int i=0; i<sizeof(bullet_x); i++)
				{
					if (s_a_1.isShot(bullet_x[i], bullet_y[i]) == 1)
					{
						fc_collision[1]=-15;
					}
				}
			}
	
			if(ally1 >= 300) //ally1 is a counter variable for Ally number 1. It incriments everytime you come through main (see just after the switch below).
			{
				allycounter1 = AiGenerator();	//Get a random number from AiGenerator
				ally1 = 0;						//Set the timer to zero. The timer is basically 'How long do I do an instruction for'.
			}

			switch(allycounter1)	//Using the random number (results are from 1-9)
			{
			case 1 :																						//If random number = 1, then stand still.
				am_i_moving(1);																				//Set animation to zero
				masked_blit(warrior_1, buffer, 40, 36,s_a_1.getPositionX(),s_a_1.getPositionY(), 31, 34);	//blit standing picture.
				break;	
			case 2:																							//If random number = 2, then shoot a bullet.
				if (bullet_t[1]==0)
				{
					bullet_x[1]=s_a_1.getPositionX()-10;													//I have not touched this bullet code
					bullet_y[1]=s_a_1.getPositionY();
					bullet_t[1]=1;
				}	
				masked_blit(warrior_1, buffer, 40, 36,s_a_1.getPositionX(),s_a_1.getPositionY(), 31, 34);	//This blits a standing picture whilst the random number has selected this option.
				ally1 = 299;																				//Set the counter up to 1 below the 'change over time' so we only fire one bullet.
				break;
			case 3:																							//If random number = 3, then move up.
				s_a_1.addPosition('y',-1);																	//Our standard move up procedure
				animate(1, warrior_1, buffer, 75, 36, s_a_1.getPositionX(), s_a_1.getPositionY());			//Calls animate
				ally1 += 10;																				//This shortens the time that the soldier is actually moving
				allycounter1 = 3;																			//This ensures that the switch keeps coming into here for the duration of the timer (ally1)
				break;
			case 4:																							//Same as above
				s_a_1.addPosition('y',+1);
				animate(1, warrior_1, buffer, 75, 36, s_a_1.getPositionX(), s_a_1.getPositionY());
				ally1 += 10;
				allycounter1 = 4;
				break;
			case 5:																							//Same as above
				s_a_1.addPosition('x',-1);
				animate(1, warrior_1, buffer, 75, 36, s_a_1.getPositionX(), s_a_1.getPositionY());
				ally1 += 10;
				allycounter1 = 5;
				break;
			case 6:																							//Same as above
				s_a_1.addPosition('x',-2);
				animate(1, warrior_1, buffer, 75, 36, s_a_1.getPositionX(), s_a_1.getPositionY());
				ally1 += 10;
				allycounter1 = 6;
				break;
			case 7 :																						//Same as case 1, standing still. Got 4 cases of standing still so more likely to do nothing than to move.
				am_i_moving(1);
				masked_blit(warrior_1, buffer, 40, 36,s_a_1.getPositionX(),s_a_1.getPositionY(), 31, 34);
				break;
			case 8 :																						//Same as case 1
				am_i_moving(1);	
				masked_blit(warrior_1, buffer, 40, 36,s_a_1.getPositionX(),s_a_1.getPositionY(), 31, 34);
				break;
			case 9 :																						//Same as case 1
				am_i_moving(1);
				masked_blit(warrior_1, buffer, 40, 36,s_a_1.getPositionX(),s_a_1.getPositionY(), 31, 34);
				break;
			default:
				break;
			}
			ally1++;																						//This is where we incriment the counter every time we pass.
	
		}

}
