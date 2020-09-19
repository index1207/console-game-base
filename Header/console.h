#include "stdio.h"
#include "Windows.h"
// text color def
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

// key kode
#define     IK_W    0x57
#define     IK_A    0x41
#define     IK_S    0x53
#define     IK_D    0x44
#define     IK_C    0x43
#define     IK_C    0x43


// console size
#define Y 40
#define X (Y*2)

// set FPS
double Frame(int fps) {
  return 1000/fps;
}
void Clear(void) {
  for(int i = 0; i < Y; i++) putchar('\n');
}

void CursorView(char show)//cursor
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(hConsole , &ConsoleCursor);
}
void gotoxy(short x, short y) {
  COORD pos={x,y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetConsoleSize(int x, int y) {
  char cmd[30];
  sprintf(cmd, "mode con cols=%d lines=%d", x, y);
  system(cmd);
}

void TextColor(int color, const char * string)
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
  printf(string);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
}
