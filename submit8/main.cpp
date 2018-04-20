#include"conlib.h"
#include"global.h"
#include"title.h"
#include"game.h"
#include"gameover.h"

int gFrame;
struct GAMECHAR gGamechars[GAMECHAR_NUM];

void main()
{
	char key;
	int nowstate;

	nowstate = STATE_TITLE;
	gFrame = 0;
	init_lib();

	while (1)
	{
		cls();
		key = checkkey();
		switch (nowstate)
		{
		case STATE_TITLE:
			nowstate = stateTitle(key);
			break;
		case STATE_GAME:
			nowstate = stateGame(key);
			break;
		case STATE_GAMEOVER:
			nowstate = stateGameover(key);
			break;
		}
		wait();
	}
}