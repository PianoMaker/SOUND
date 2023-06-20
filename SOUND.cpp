#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
using namespace std;

#pragma comment(lib, "winmm.lib")

void Play_sound(double frequency, int time) {
        std::cout << frequency;
        Beep(frequency, time);
}

void Task(double& frequency, int& time)
{
    cout << "Enter frequency\n";
    cin >> frequency;
    cout << "Enter length\n";
    cin >> time;

}

int main() {
    double frequency;
        int time;

    Task(frequency, time);
    Play_sound(frequency, time);
    return 0;
}