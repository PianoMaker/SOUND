#include <iostream>
#include <Windows.h>

void play_sound(int frequency, int time) {
        std::cout << frequency;
        Beep(frequency, time);
}

int main() {
    // Play a sound with frequency 440 Hz
    for (int i=1; i<100; i++)
    {
        play_sound(rand()*0.1, 100 + rand()%20);
        system("cls");
    }
    return 0;
}