#include <cstdlib>
#include "Game.h"

int main()
{
	system("mode con cols=120 lines=36");
	SetConsoleTitle(L"̰���߾��̰�2.0");
	printByxy(FRAME_X + FRAME_L + 25, FRAME_Y + 32, "by��");
	hide_cursor();
	PlaySound((L"sounds/hello.wav"), NULL, SND_ASYNC | SND_LOOP);
	Sleep(200);
	frame();
	hello();
	SetPosition(FRAME_X + FRAME_L + 2, FRAME_Y + FRAME_L / 2);
	system("pause");
}