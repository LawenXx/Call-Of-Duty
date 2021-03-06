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
	char pad_0000[44]; //0x0000
	Vector3 Origin; //0x002C
	Vector3 ViewAngles; //0x0038
	char pad_0044[272]; //0x0044
	int32_t Flags; //0x0154
	char pad_0158[88]; //0x0158
	int32_t PrimaryWeapon; //0x01B0
	int32_t SecondaryWepon; //0x01B4
	char pad_01B8[144]; //0x01B8
	uint16_t N0000034C; //0x0248
	uint16_t N0000038A; //0x024A
	char pad_024C[92]; //0x024C
	uint16_t eType; //0x02A8
	char pad_02AA[206]; //0x02AA
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
