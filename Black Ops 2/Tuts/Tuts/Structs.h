#pragma once

#define ScrPlacement 0x82CBC168

struct Material
{
	const char* material;
};

struct Font
{
	const char* name;
	int pixelheight;
};

struct Vector3 {
	float x, y, z;
	const float Getdistance(Vector3 coords);
};

struct Vector2 {
	float x, y;
};

struct UIContext
{
	int32_t contextid; //0x0000
	char pad_0004[24]; //0x0004
	int32_t ScreenWidth; //0x001C
	int32_t ScreenHeight; //0x0020
	char pad_0024[8]; //0x0024
};

struct Centity
{
	char padding[3]; // 0x0
	char type; //0x3
	char padding2[40]; //0x4
	Vector3 origin; // 0x2C
	Vector3 angles; // 0x38
	char padding3[268]; // 0x38
	int isAlive2; // 0x150
	int flags; // 0x154
	char padding4[84]; // 0x158
	int teamDog; // 0x1AC
	int weaponId; // 0x1B0
	int secondaryWeaponId; // 0x1B4
	char padding5[0x18]; // 0x1B4
	int handle; // 0x1D0
	char padding6[0x74]; // 0x1D4
	short uknw; // 0x248
	short uknw1; // 0x24A 
	char padding7[92]; // 0x24C
	short eType; // 0x2A8
	char padding8[13]; // 0x2AA
	char weaponNum; // 0x2B7
	char padding9[0xB]; // 0x2B8
	char clientNum; // 0x2C3
	char padding10[168]; // 0x2B8 
	char State; // 0x36C
	char padding11[4]; // 0x36D
};

struct CGArray
{//Add rest of struct when needed
	int32_t ClientNum; //0x0000
	int32_t LocalClient; //0x0004
	char pad_0008[16]; //0x0008
	int32_t RenderScreen; //0x0018
	int32_t LatestSnapshotNum; //0x001C
	int32_t LatestSnapshotTime; //0x0020
	char pad_0024[28]; //0x0024
};

extern CGArray* cgsArray;
extern Centity* cg_entitiesArray;
extern UIContext* CGDC;