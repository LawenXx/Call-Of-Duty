#include "stdafx.h"

void NetDll_XNetGetTitleXnAddrHook(int xnc, XNADDR* pXna)
{
	MinHook[0].Stub(xnc, pXna);

	BYTE IP[] = { 0x2, 0x2, 0x33, 0x3 };
	pXna->inaOnline.S_un.S_addr = *(DWORD*)&IP;
}

std::uintptr_t CurrentId;
bool unloading, onDash, firstDash;
HANDLE Thread;
DWORD ThreadId;

DWORD CheckUnload()
{
	while (XamGetCurrentTitleId() == CurrentId && !unloading){/*meh*/}
	if (unloading)
	{
		StopHooks();
		CleanHooks();
	}
	else
		CleanHooks();

	return 0;
}
void checkTitleId(std::uintptr_t id)
{
	CurrentId = id;

	switch (id)
	{
	case DASHBOARD:
		goto nogame;
		break;
	case FREESTYLEDASH:
		goto nogame;
		break;
	case COD_BLACK_OPS_2:
		XNotify("IpSpoof [BO2] by kat");
		MinHook[0] = MinHook_t(0x8293E5C4, (std::uint64_t)NetDll_XNetGetTitleXnAddrHook, true);
		break;
	case COD_BLACK_OPS_3:
		XNotify("IpSpoof [BO2] by kat");
		MinHook[0] = MinHook_t(0x4156091D, (std::uint64_t)NetDll_XNetGetTitleXnAddrHook, true);
		break;
	case 0x41560817:

			break;
	default:
		goto done;
	nogame:
		if (!onDash)
		{
			if (!firstDash)
			{
				Sleep(200);
				firstDash = true;
			}
			onDash = true;
		}
		goto done;
		break;
	}

	StartHooks();

	ExCreateThread(&Thread, 0, &ThreadId, (PVOID)XapiThreadStartup, (LPTHREAD_START_ROUTINE)CheckUnload, 0, 2);
	XSetThreadProcessor(Thread, 4);
	ResumeThread(Thread);
	CloseHandle(Thread);

done:
	return;
}

DWORD TitleID()
{
	while (!unloading)
	{
		if (XamGetCurrentTitleId() != CurrentId)
			checkTitleId(XamGetCurrentTitleId());
	}
	return 0;
}

BOOL APIENTRY DllMain(HANDLE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		HANDLE hThread;
		DWORD dwThreadId;
		ExCreateThread(&hThread, NULL, &dwThreadId, (PVOID)XapiThreadStartup, (LPTHREAD_START_ROUTINE)TitleID, 0, 2 | CREATE_SUSPENDED);
		XSetThreadProcessor(hThread, 4);
		SetThreadPriority(hThread, THREAD_PRIORITY_NORMAL);
		ResumeThread(hThread);

		checkTitleId(XamGetCurrentTitleId());
	}
	if (dwReason == DLL_PROCESS_DETACH)
	{
		unloading = true;
		Sleep(250);
	}
	return true;
}