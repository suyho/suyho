#include"global.h"

void initChars()
{
	for (int i = 0; i < GAMECHAR_NUM; i++)
	{
		gGamechars[i].kind = KIND_NONE;
	}
}

int findSpaceChar()
{
	for (int i = 0; i < GAMECHAR_NUM; i++)
	{
		switch (gGamechars[i].kind)
		{
		case KIND_NONE:
			return i;
		}
	}
	return -1;
}