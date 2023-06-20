#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
using namespace std;

#pragma comment(lib, "winmm.lib")

void Play_sound(int frequency, int time) {
        std::cout << frequency;
        Beep(frequency, time);
}

void Task(int& frequency, int& time)
{
    cout << "\nEnter frequency";
    cin >> frequency;
    cout << "\nEnter length";
    cin >> time;

}

int main() {
    int frequency, time;
    Task(frequency, time);
    Play_sound(frequency, time);

    return 0;
}