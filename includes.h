//
// Created by Javier on 9/5/2024.
//

#ifndef AC_CHEAT_INCLUDES_H
#define AC_CHEAT_INCLUDES_H


DWORD GetProcessID(const char *procName);
DWORD GetModuleBaseAddress(DWORD procId, const char *modName);

#endif //AC_CHEAT_INCLUDES_H
