#include "includes.h"

float white[] = { 1,1,1,1 };

void Esp() {
	for (int i = 0; i < 18; i++)
	{ //1 is player 2 is player corpse
		//We need to get clientnum in centity too soon 
		if (!(cg_entitiesArray[i].eType == 1 && (cg_entitiesArray[i].eType != 2)))
			continue;
		if(!cg_entitiesArray[i].State & (1 << 6) != 0)
			continue;

		Vector2 Pos = Vector2();
		Vector2 Head = Vector2();
		Vector3 Origin = cg_entitiesArray[i].origin;
		Vector3 HeadPos = GetTagPos(&cg_entitiesArray[i], "j_head");
		HeadPos.z += 10;
		Origin.z -= 5;

		if (!WorldToScreen(0, Origin, &Pos))
			continue;
		if (!WorldToScreen(0, HeadPos, &Head))
			continue;

		float PlayerHeight = fabsf(Head.y - Pos.y);
		float PlayerWidth = (fabsf(Head.y - Pos.y) * 0.65f);
		float Distance = cg_entitiesArray[cgsArray->ClientNum].origin.Getdistance(cg_entitiesArray[i].origin);
		
		DrawBox(Pos.x - (PlayerWidth / 2.f) - 6.f, Head.y - 4.f, PlayerWidth, PlayerHeight, white, 1.f);
	}
}

void Menu_Paint_All(int LocalClient, int UiContext)
{//Not the best hook to do it in but it works
	Esp();
	MinHook[0].Stub(LocalClient, UiContext);
}

