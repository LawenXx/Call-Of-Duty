#include "includes.h"

CG_DrawRotatedPic_t CG_DrawRotatedPic;
Material_RegisterHandle_t Material_RegisterHandle;
R_AddCmdDrawText_t R_AddCmdDrawText;
R_RegisterFont_t R_RegisterFont;
UIContext* CGDC;
Centity* cg_entitiesArray;

void FillAddresses()
{
	CG_DrawRotatedPic = CG_DrawRotatedPic_t(0x821C7F58);
	Material_RegisterHandle = Material_RegisterHandle_t(0x828B78F0);
	R_AddCmdDrawText = R_AddCmdDrawText_t(0x828B8BA0);
	R_RegisterFont = R_RegisterFont_t(0x828B6EC0);
}

void FillStructs()
{
	CGDC = (UIContext*)0x83BA29F0;
	cg_entitiesArray = *(Centity**)0x82BBC554;
}

