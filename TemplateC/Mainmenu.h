#include <allegro.h>

class Mainm
{
public:
	Mainm(void);
	~Mainm(void);
	void Decon(void);
	void draw(BITMAP *screen, int i);
	bool ToMousePlay(void);
	bool ToMouseHelp(void);
	bool ToMouseHelpIn(void);
	bool ToMouseQuit(void);
	
private:
	int choice;
	BITMAP *GUIMain;
	BITMAP *GUIHelp;
	int x;
};

