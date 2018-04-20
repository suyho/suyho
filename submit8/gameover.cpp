#include"conlib.h"
#include"global.h"
#include"title.h"

int intoGameover()
{
	gFrame = 0;
	return STATE_GAMEOVER;
}

int stateGameover(char key)
{
	gFrame++;
	if (gFrame % 10 < 5)
	{
		printxy(30, 10, "GAME OVER");
	}
	if ((key != 0) || (gFrame>20))
	{
		gFrame = 0;
		return STATE_TITLE;
	}
	return STATE_GAMEOVER;
}
