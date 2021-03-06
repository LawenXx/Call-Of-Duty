#pragma once
//Typedefs
typedef void(*CG_DrawRotatedPic_t)(std::uintptr_t scrPlacement, float x, float y, float w, float h, float angle, float* color, Material* Material);
typedef Material* (*Material_RegisterHandle_t)(const char* Name, int ImgTrack);
typedef Font* (*R_RegisterFont_t)(const char* Font, int Img);
typedef void(*R_AddCmdDrawText_t)(const char* Text, int MaxChars, Font* font, float x, float y, float xScale, float yScale, float Rotate, float* color, int style);
typedef bool(*AimtTarget_GetTagPos_t)(Centity* Cen, unsigned int Tag, Vector3& Pos);
typedef int(*SL_GetString_t)(const char* String, int forgot);
typedef bool(*WorldToScreen_t)(int LocalClient, Vector3& World, Vector2* Screen);

//Externs
extern WorldToScreen_t WorldToScreen;
extern SL_GetString_t SL_GetString;
extern R_RegisterFont_t R_RegisterFont;
extern R_AddCmdDrawText_t R_AddCmdDrawText;
extern CG_DrawRotatedPic_t CG_DrawRotatedPic;
extern Material_RegisterHandle_t Material_RegisterHandle;
extern AimtTarget_GetTagPos_t AimtTarget_GetTagPos;

extern void FillStructs();
extern void FillAddresses();
extern Vector3 GetTagPos(Centity* Client, const char* Tag);
extern void DrawShader(float x, float y, float width, float height, float* color, const char* shader = "white");
extern void DrawBox(float x, float y, float width, float height, float* color, float LineWidth);
