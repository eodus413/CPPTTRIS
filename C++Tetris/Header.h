#pragma once
#include<Windows.h>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#include <string>



typedef int Block;
typedef char* Image;


typedef struct _Rect
{
	int top;
	int left;
	int bottom;
	int right;

	int height;
	int width;

}Rect;

struct Position
{
	int x;
	int y;

	Position(int p_x, int p_y)
	{
		x = p_x;
		y = p_y;
	}
};

enum Square
{
	NONE, 
	LINE, 
	WALL, 
	FLOOR, 
	CORNER, 
	STACKBLOCK 
};

enum  //¾ðÁ¨°¡ ¾ø¾Ù°Å¿©
{
	WIDTH = 10,
	HEIGHT = 20
};	

enum Color
{
	black,
	darkblue,
	darkgreen,
	darkcyan,
	darkred,
	darkpurple,
	darkyellow,
	darkwhite,
	gray,
	blue,
	green,
	cyan,
	red,
	purple,
	yellow,
	white
};

enum State { NORMAL, STACK, MOVEABLE, ROTATABLE };

enum { VIEWER_WIDTH = 6, VIEWER_HEIGHT = 6 };

enum {CREATEDX = 10,CREATEDY = 0};

enum Direction{kup,kdown,kleft,kright};