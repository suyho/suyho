#include"conlib.h"
#include"global.h"
#include"gamechars.h"

void initAground()
{
	int count=0;
	int space = findSpaceChar();
	for (int i = space; i < space + 79; i++)
	{
		gGamechars[i].kind = KIND_GROUND;
		gGamechars[i].x = count;
		gGamechars[i].y = 21;
		count++;
	}
}

void moveAground(int index)
{
	printxy(gGamechars[index].x, gGamechars[index].y, "=");
}