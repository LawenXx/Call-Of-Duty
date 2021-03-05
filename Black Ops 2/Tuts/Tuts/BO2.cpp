#include "includes.h"

float white[] = { 1,1,1,1 };
void Menu_Paint_All(int LocalClient, int UiContext)
{
	CG_DrawRotatedPic(ScrPlacement, CGDC->ScreenWidth/2, CGDC->ScreenHeight/2, 50, 50, 0, white, Material_RegisterHandle("white", 0));
	R_AddCmdDrawText("Some text on screen yknow", INT_MAX, R_RegisterFont("fonts/720/normalfont", 0), 1080 / 2, 720 / 2, 1, 1, 0, white, 3);
	MinHook[0].Stub(LocalClient, UiContext);
}
