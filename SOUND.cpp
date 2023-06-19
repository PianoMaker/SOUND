#include <iostream>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

void play_sound(int frequency, int time) {
        std::cout << frequency;
        Beep(frequency, time);
}

int main() {
    // Play a sound with frequency 440 Hz
    for (int i=1; i<50; i++)
    {
        play_sound(20 + i, 2000);
        system("cls");
        Sleep(20);
    }
    return 0;
}