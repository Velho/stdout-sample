#include "win-wrapper.h"

#include <Windows.h>
#include <synchapi.h>

void SystemSleep(unsigned int ms)
{
	Sleep(static_cast<DWORD>(ms));
}
