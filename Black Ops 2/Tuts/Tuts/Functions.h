#pragma once
//Typedefs
typedef void(*CG_DrawRotatedPic_t)(std::uintptr_t scrPlacement, float x, float y, float w, float h, float angle, float* color, Material* Material);
typedef Material* (*Material_RegisterHandle_t)(const char* Name, int ImgTrack);
typedef Font* (*R_RegisterFont_t)(const char* Font, int Img);
typedef void(*R_AddCmdDrawText_t)(const char* Text, int MaxChars, Font* font, float x, float y, float xScale, float yScale, float Rotate, float* color, int style);

//Externs
extern R_RegisterFont_t R_RegisterFont;
extern R_AddCmdDrawText_t R_AddCmdDrawText;
extern CG_DrawRotatedPic_t CG_DrawRotatedPic;
extern Material_RegisterHandle_t Material_RegisterHandle;

extern void FillStructs();
extern void FillAddresses();