#include <iostream>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

int main() {
    // Play a sound with frequency 440 Hz
    for (int i=1; i<500; i++)
    {
        Beep(rand()*0.1, 100 + rand()%20);
        system("cls");
    }
    return 0;
}