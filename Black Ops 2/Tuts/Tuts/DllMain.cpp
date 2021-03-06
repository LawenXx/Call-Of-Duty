#include "includes.h"

std::uintptr_t CurrentTitleId;
bool unload, onDashboard, FirstTimeDash;
HANDLE Thread;
DWORD ThreadID;

DWORD CheckForUnload()
{
	while (XamGetCurrentTitleId() == CurrentTitleId && !unload) {/*Do Stuff later*/ }
	if (unload)
	{
		StopHooks();
		CleanHooks();
	}
	else
		CleanHooks();

	return 0;
}

void CheckTitleID(std::uintptr_t id)
{
	CurrentTitleId = id;

	switch (id)
	{
	case DASHBOARD:
		goto nogame;
		break;
	case FREESTYLEDASH: 
		goto nogame;
		break;
	case COD_BLACK_OPS_2:
		//XamInputGetState- checks to make sure the game is fully loaded before trying to inject our module
		while (*(int*)0x8293D884 == 0)
		{
			Sleep(100);
		}
		FillAddresses();
		FillStructs();
		MinHook[0] = MinHook_t(0x824744E0, (std::uint64_t)Menu_Paint_All, true);

		XNotify("BO2 Found tut xex", XNOTIFYUI_TYPE_SONGPLAYING);
		break;
	default:
		goto done;
	nogame:
		if (!onDashboard)
		{
			if (!FirstTimeDash)
			{
				Sleep(200);
				XNotify("Dashboard tut xex", XNOTIFYUI_TYPE_SONGPLAYING);
				FirstTimeDash = true;
			}
			onDashboard = true;
		}
		goto done;
		break;
	}
	StartHooks();
	ExCreateThread(&Thread, 0, &ThreadID, (PVOID)XapiThreadStartup, (LPTHREAD_START_ROUTINE)CheckForUnload, 0, 2);
	XSetThreadProcessor(Thread, 4);
	ResumeThread(Thread);
	CloseHandle(Thread);

done:
	return;

}

DWORD TitleID() {
	while (!unload) {
		if (XamGetCurrentTitleId() != CurrentTitleId)
			CheckTitleID(XamGetCurrentTitleId());
	}
	return 0;
}

BOOL APIENTRY DllMain(HANDLE hModule, DWORD dwReason, LPVOID lpReserved) {
	if (dwReason == DLL_PROCESS_ATTACH) {
		HANDLE hThread;
		DWORD dwThreadId;

		ExCreateThread(&hThread, NULL, &dwThreadId, (PVOID)XapiThreadStartup, (LPTHREAD_START_ROUTINE)TitleID, 0, 2 | CREATE_SUSPENDED);
		XSetThreadProcessor(hThread, 4);
		SetThreadPriority(hThread, THREAD_PRIORITY_NORMAL);
		ResumeThread(hThread);

		CheckTitleID(XamGetCurrentTitleId());
	}
	if (dwReason == DLL_PROCESS_DETACH) {
		unload = true;
		Sleep(250);
	}
	return true;
}