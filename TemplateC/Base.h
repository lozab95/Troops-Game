#include <allegro.h>

class Base
{
public:
	Base(void);
	~Base(void);
	int isShot(int x, int y);
	void Decon(void);
	bool isdead(void);
	void draw(BITMAP *buffer);
	int getHouseNo(void);
	void setHouseNo(int i);
	void setSpawn(int x, int y);
	int getSpawnX(void);
	int getSpawnY(void);
	void setPosition(int x, int y);
	void update(int x, int y);
	int getPositionX(void);
	int getPositionY(void);
	int getHealth(void);
	bool spawner(void);

private:
	int Pos_s_x;
	int Pos_s_y;
	int position_x;
	int position_y;
	int health;
	int damage;
	int houseNo;
	BITMAP *house;

};

