# GAME MEMORY MANIPULATION IN C

This program allows the user to read/write memory values of the game Assault Cube to modify values. The program utilizes the Windows API functions such as **ReadProcessMemory**, **WriteProcessMemory**, and **OpenProcess**. 

In the program, the games **processID** and **ModuleBaseAddress** is obtained using **CreateToolhelp32Snapshot** Windows API function.

## FEATURES:
  > Read Memory Values <br/> Write Memory Values <br/> Process Handling <br/> Module Base Address

## Requirements: 
  > Windows OS <br/> C Compiler <br/> AssaultCube

## Credit:
  > [Reverse Engineer Assault Cube / GetProcessId / GetModuleBaseAddress Help](https://www.youtube.com/watch?v=GwP6QZDIfyg&list=LL&index=1) <br/>
  > [Read / Write / Windows API Help](https://www.unknowncheats.me/forum/programming-for-beginners/267073-coding-hacking-introduction-guide-practical-external-game-hacking.html)
