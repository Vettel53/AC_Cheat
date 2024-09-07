#include <stdio.h>
#include <windows.h>
#include "includes.h"

// int write(HANDLE hProcess, LPVOID lpBaseAddress, int lpBuffer, int nSize) { // WriteProcess

//     int overWrite = 0;

//     printf("\nEnter the value you would like to write:");
//     scanf("%d", &overWrite);

//     BOOL writeInt = WriteProcessMemory(hProcess, (LPVOID) lpBaseAddress, &overWrite, nSize, NULL);

//     if (!writeInt) {
//         printf("WriteProcessMemory failed. GetLastError() - %lu \n", GetLastError());
//         CloseHandle(hProcess);
//     } else {
//         printf("WriteProcessMemory success - Written value: %d", overWrite);
//     }
// }

int main() {

    DWORD pID, baseModule, localPlayerPtr;
    int health = 9999;

    pID = GetProcessID((const char *) "ac_client.exe");
    baseModule = GetModuleBaseAddress(pID, (const char*) "ac_client.exe");
    printf("PID : %lu\n", pID);
    printf("BASE MODULE : \n%lx", baseModule);


    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);
    if (hProcess == NULL) {

        printf("OpenProcess failed. GetLastError = %lu", GetLastError());

    } else {
        printf("OpenProcess success.\n");
    }

    BOOL readMemory = ReadProcessMemory(hProcess, (LPCVOID) (baseModule + 0x17E0A8), &localPlayerPtr, sizeof(localPlayerPtr), NULL);

    BOOL writeInt = WriteProcessMemory(hProcess, (LPVOID) (localPlayerPtr + 0xEC), &health, sizeof(health), NULL);

    if (!writeInt) {
        printf("WriteProcessMemory failed. GetLastError() - %lu \n", GetLastError());
        CloseHandle(hProcess);
    } else {
        printf("WriteProcessMemory success - Written value: %d", health);
    }

    return 0;
}
