#include"conlib.h"
#include"global.h"
#include"gameover.h"
#include"gamechars.h"
#include"jiki.h"
#include"wall.h"
#include"ground.h"

int intoGame()
{
	gFrame = 0;
	initChars();
	initAJiki();
	initAground();
	return STATE_GAME;
}

int stateGame(char key)
{
	gFrame++;
	for (int i = 0; i < GAMECHAR_NUM; i++)
	{
		switch (gGamechars[i].kind)
		{
		case KIND_JIKI:
			moveAJiki(key, i);
			break;
		case KIND_GROUND:
			moveAground(i);
			break;
		case KIND_WALL:
			moveAWall(i);
			break;
		}
	}

	printxy(30, 22, "Push q to GAMEOVER");
	if (key == 'q')
	{
		return intoGameover();
	}
	return STATE_GAME;
}