#include"conlib.h"
#include"global.h"
#include"gamechars.h"

void initAJiki()
{
	int space = findSpaceChar();
	gGamechars[space].kind = KIND_JIKI;
	gGamechars[space].state = JIKI_STATE_IDLE;
	gGamechars[space].x = 40;
	gGamechars[space].y = 20;
}

int jikiStateIdle(char key, int index)
{
	if (key == 'w')
	{
		gGamechars[index].vy = -5;
		return JIKI_STATE_JUMP;
	}
	if (key == 'a')
	{
		return JIKI_STATE_BACKWARD;
	}
	if (key == 'd')
	{
		return JIKI_STATE_FORWARD;
	}
	return JIKI_STATE_IDLE;
}

int jikiStateJump(char key, int index)
{
	gGamechars[index].y += gGamechars[index].vy;
	gGamechars[index].vy++;
	if (key == 'd')
	{
		gGamechars[index].x++;
	}
	if (key == 'a')
	{
		gGamechars[index].x--;
	}
	if (gGamechars[index].y >= GROUND_Y)
	{
		gGamechars[index].y = GROUND_Y;
		return JIKI_STATE_IDLE;
	}
	return JIKI_STATE_JUMP;
}

int jikiStateForJump(char key, int index)
{
	if (key == 'a')
	{
		return JIKI_STATE_BACKJUMP;
	}
	else
	{
		gGamechars[index].x++;
		gGamechars[index].y += gGamechars[index].vy;
		gGamechars[index].vy++;
		if (gGamechars[index].y >= GROUND_Y)
		{
			gGamechars[index].y = GROUND_Y;
			return JIKI_STATE_IDLE;
		}
		return JIKI_STATE_FORJUMP;
	}
}

int jikiStateBackJump(char key, int index)
{
	if (key == 'd')
	{
		return JIKI_STATE_FORJUMP;
	}
	else {
		gGamechars[index].x--;
		gGamechars[index].y += gGamechars[index].vy;
		gGamechars[index].vy++;
		if (gGamechars[index].y >= GROUND_Y)
		{
			gGamechars[index].y = GROUND_Y;
			return JIKI_STATE_IDLE;
		}
		return JIKI_STATE_BACKJUMP;
	}
}

int jikiStateForward(char key, int index)
{
	gGamechars[index].x++;
	if (key == 'w')
	{
		gGamechars[index].vy = -5;
		return JIKI_STATE_FORJUMP;
	}
	if (key !='d')
	{
		return JIKI_STATE_IDLE;
	}
	return JIKI_STATE_FORWARD;
}

int jikiStateBackward(char key, int index)
{
	gGamechars[index].x--;
	if (key == 'w')
	{
		gGamechars[index].vy = -5;
		return JIKI_STATE_BACKJUMP;
	}
	if (key != 'a')
	{
		return JIKI_STATE_IDLE;
	}
	return JIKI_STATE_BACKWARD;
}

void moveAJiki(char key, int index)
{
	switch (gGamechars[index].state)
	{
	case JIKI_STATE_IDLE:
		gGamechars[index].state = jikiStateIdle(key, index);
		break;
	case JIKI_STATE_FORWARD:
		gGamechars[index].state = jikiStateForward(key, index);
		break;
	case JIKI_STATE_BACKWARD:
		gGamechars[index].state = jikiStateBackward(key, index);
		break;
	case JIKI_STATE_JUMP:
		gGamechars[index].state = jikiStateJump(key,index);
		break;
	case JIKI_STATE_FORJUMP:
		gGamechars[index].state = jikiStateForJump(key, index);
		break;
	case JIKI_STATE_BACKJUMP:
		gGamechars[index].state = jikiStateBackJump(key, index);
		break;
	}
	printxy(gGamechars[index].x, gGamechars[index].y-2, " O/");
	printxy(gGamechars[index].x, gGamechars[index].y-1, "/| ");
	printxy(gGamechars[index].x, gGamechars[index].y,   " @ ");
}