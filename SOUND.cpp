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
    for (int i=1; i<100; i++)
    {
        play_sound(20 + i, 400 + rand()%20);
        system("cls");
    }
    return 0;
}