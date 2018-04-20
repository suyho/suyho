#include"conlib.h"
#include"global.h"
#include"game.h"

int initTitle()
{
	gFrame = 0;
	return STATE_TITLE;
}

int stateTitle(char key)
{
	gFrame++;
	printxy(30, 10, "This is title.");
	if (gFrame % 10 < 5)
	{
		printxy(30, 20, "Push SPACE key!");
	}
	if (key == ' ')
	{
		return intoGame();
	}
	return STATE_TITLE;
}