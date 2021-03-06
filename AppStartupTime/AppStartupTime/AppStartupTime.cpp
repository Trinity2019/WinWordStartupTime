// AppStartupTime.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <tchar.h>

void _tmain(int argc, TCHAR *argv[])
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (argc != 2)
    {
        _tprintf(TEXT("Usage: %s [cmdline]\n"), argv[0]);
        return;
    }

    ULONGLONG start = GetTickCount64();

    // Start the child process. 
    if (!CreateProcess(NULL,
        argv[1],
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi)
        )
    {
        _tprintf(TEXT("CreateProcess failed (%d).\n"), GetLastError());
        return;
    }

    // Wait for the specified process has finished its initialization and
    // is waiting for user input with no input pending
    if (0 != WaitForInputIdle(pi.hProcess, INFINITE))
    {
        _tprintf(TEXT("Failed to wait for initialization of [%s].\n"), argv[1]);

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
        return;
    }

    ULONGLONG  stop = GetTickCount64();
    ULONGLONG  stopWatch = stop - start;
    _tprintf(TEXT("Startup Time for %s is: %d(ms)"), argv[1], stopWatch);

    // Comment out following code to prefer to close the application manually
    // (void)TerminateProcess(pi.hProcess, 0);

    // Close process and thread handles. 
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}
