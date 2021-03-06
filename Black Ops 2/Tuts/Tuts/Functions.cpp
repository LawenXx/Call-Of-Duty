#include "includes.h"

CG_DrawRotatedPic_t CG_DrawRotatedPic;
Material_RegisterHandle_t Material_RegisterHandle;
R_AddCmdDrawText_t R_AddCmdDrawText;
R_RegisterFont_t R_RegisterFont;
AimtTarget_GetTagPos_t AimtTarget_GetTagPos;
SL_GetString_t SL_GetString;
WorldToScreen_t WorldToScreen;

UIContext* CGDC;
Centity* cg_entitiesArray;
CGArray* cgsArray;

void FillAddresses()
{
	CG_DrawRotatedPic = CG_DrawRotatedPic_t(0x821C7F58);
	Material_RegisterHandle = Material_RegisterHandle_t(0x828B78F0);
	R_AddCmdDrawText = R_AddCmdDrawText_t(0x828B8BA0);
	R_RegisterFont = R_RegisterFont_t(0x828B6EC0);
	AimtTarget_GetTagPos = AimtTarget_GetTagPos_t(0x821E9C08);
	WorldToScreen = WorldToScreen_t(0x821DA808);
	SL_GetString = SL_GetString_t(0x825334F8);
}

void FillStructs()
{
	CGDC = (UIContext*)0x83BA29F0;
	cg_entitiesArray = *(Centity**)0x82BBC554;
	cgsArray = *(CGArray**)0x82BBAE68;
}

const float Vector3::Getdistance(Vector3 coords) {
	float x = this->x - coords.x;
	float y = this->y - coords.y;
	float z = this->z - coords.z;
	return sqrtf((x * x) + (y * y) + (z * z)) * 0.03048f;
}

Vector3 GetTagPos(Centity* Client, const char* Tag)
{
	Vector3 Pos;
	AimtTarget_GetTagPos(Client, SL_GetString(Tag, 0), Pos);
	return Pos;
}

void DrawShader(float x, float y, float width, float height, float* color, const char* shader)
{
	CG_DrawRotatedPic(ScrPlacement, x, y, width, height, 0, color, Material_RegisterHandle(shader, 0));
}

void DrawBox(float x, float y, float width, float height, float* color, float LineWidth)
{
	DrawShader(x - LineWidth, y - LineWidth, width + (LineWidth * 2), LineWidth, color);
	DrawShader(x - LineWidth, y + height, width + (LineWidth * 2), LineWidth, color);
	DrawShader(x - LineWidth, y - LineWidth, LineWidth, height + LineWidth, color);
	DrawShader(x + width, y - LineWidth, LineWidth, height + (LineWidth * 2), color);
}
