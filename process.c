#include <stdio.h>
#include <windows.h>
#include "includes.h"
#include <tlhelp32.h>


DWORD GetProcessID(const char *procName) {
    DWORD procID = 0;
    HANDLE hSnap = (CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0));

    size_t newSize = strlen(procName) + 1;

    wchar_t wcstring[20];
    size_t convertedChars = 0;
    errno_t err;

    err = mbstowcs_s(&convertedChars, wcstring, 20, procName, 19);

    if (err == 0) {
        wprintf(L"Converted String %ls\n", wcstring); // L states that it's a wide character string
        printf("Number of wide characters converted = %zu\n", convertedChars);
    } else {
        printf("Conversation Failed: %d\n", err);
    }


    if (hSnap != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32 procEntry;
        procEntry.dwSize = sizeof(procEntry);

        if (Process32First(hSnap, &procEntry)) {
            do {
                if (!_stricmp(procEntry.szExeFile, procName)) {
                    procID = procEntry.th32ProcessID;
                    break;
                }
            } while (Process32Next(hSnap, &procEntry));
        }
    }

    CloseHandle(hSnap);
    return procID;
}

DWORD GetModuleBaseAddress(DWORD procId, const char *modName) {
    DWORD modBaseAddr = 0;
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);

    if (hSnap != INVALID_HANDLE_VALUE) {
        MODULEENTRY32 modEntry;
        modEntry.dwSize = sizeof(modEntry);

        if(Module32First(hSnap, &modEntry)) {
            do {
                if (!_stricmp(modEntry.szModule, modName)) {
                    modBaseAddr = (DWORD) modEntry.modBaseAddr;
                    break;
                }
            } while (Module32Next(hSnap, &modEntry));
        }
    }

    CloseHandle(hSnap);
    return modBaseAddr;
}