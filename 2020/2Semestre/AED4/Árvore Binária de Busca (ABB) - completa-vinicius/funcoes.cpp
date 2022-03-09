#include "funcoes.h"
#include <iostream>
#include <windows.h>

using namespace std;

//---------------------------------------------------------------------------------
void gotoxy( int x, int y )
{
   COORD coord;
   coord.X = (short)x;
   coord.Y = (short)y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

