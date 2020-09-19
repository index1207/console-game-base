#include "../Header/console.h"

#define FRAME 60
#define delay Sleep(FRAME/10)

int x = ((X/2)-2);
int y = Y-2;

void location(void) {
  gotoxy(0,0);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DARKGRAY);
  printf("%d %d", x, y);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
}

void InputControl(void) {
  if(GetAsyncKeyState(IK_W)&0x8000) {
    y--;
    if(y < 0) y = 0;
    delay;
  }
  if(GetAsyncKeyState(IK_A)&0x8000) {
    x-=2;
    if(x < 0) x = 0;
    delay;
  }
  if(GetAsyncKeyState(IK_S)&0x8000) {
    y++;
    if(y>(Y-1)) y = Y-1;
    delay;
  }
  if(GetAsyncKeyState(IK_D)&0x8000) {
    x+=2;
    if(x > (X-1)) x = X-1;
    delay;
  }
}

int main()
{

  SetConsoleTitle("[Game Base]");
  SetConsoleSize(X,Y);
  CursorView(FALSE);

  while(1) {
    while(1){

      system("cls");
      gotoxy(x,y);
      printf("@");
      location();

      delay;
      break;
    }
    InputControl();
    Sleep(Frame(FRAME));
    if( GetAsyncKeyState(VK_ESCAPE) & 0x8000 ) {
      system("cls");
      break;
    }
  }
  return 0;
}
