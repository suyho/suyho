#include<stdlib.h>
#include"conlib.h"
#include"global.h"
#include"gamechars.h"

void initAWall()
{
	int height = rand()%13+6;
	int space = findSpaceChar();
	for (int i = space; i <space+height; i++)
	{
		gGamechars[i].kind = KIND_WALL;
		gGamechars[i].x = 78;
		gGamechars[i].y = i-space;
	}
}

void moveAWall(int index)
{
	printxy(gGamechars[index].x, gGamechars[index].y, "|");
}