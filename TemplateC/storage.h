int storesoldier_x = 0;
int storesoldier_y = 0;

bool bullet_fired = false;

void collison();

int main() 
{  /* start of main */
	

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
		
		soldier_f.position_x=20;
		soldier_f.position_y= 100;
		soldier_f.bullet_t = 0;
		soldier_f.bullet_1[0]= 1200;
		soldier_f.bullet_1[1]= 1200;
		soldier_f.bullet_2[0]= 1200;
		soldier_f.bullet_2[1]= 1200;
		soldier_f.bullet_3[0]=1200; 
		soldier_f.bullet_3[1]= 0;
		
		
		
		soldier_f.health =100;
		soldier_f.damage =20;
}

void collison()
{
	if(storesoldier_x > soldier_f.position_x);
}

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
