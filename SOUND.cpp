#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
using namespace std;

#pragma comment(lib, "winmm.lib")

void Color(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

int PickColor(int frequency)
{
	if (frequency < 21) return 12;
	else if (frequency < 100) return 6;
	else if (frequency > 2000) return 15;
	else if (frequency > 4000) return 9;
	else if (frequency > 8000) return 1;
	else return 14;

}

void Message(string text, int color)
{
	Color(color);
	cout << text;
	Color(7);
}

void Play_sound(int frequency, int time) {
	if (frequency % 2 == 1)  frequency++;

	if (frequency < 1)
	{
		Message("Error", 12); return;
	}
	Color(PickColor(frequency));
	cout << frequency;
	Color(7);
	Beep(frequency, time);
	system("cls");
}


void Task(int& frequency, int& time)
{
    cout << "Enter frequency\n";
    cin >> frequency;
    cout << "Enter length\n";
    cin >> time;
	Play_sound(frequency, time);
}

void ClassicRandom()
{
	for (int i = 1; i < 100; i++)
	{
		Play_sound(rand() * 0.1, 100 + rand() % 20);

	}
}



int main() {
    int frequency, time, mode;
	Message("Choose mode\n", 11);
	Message("\n1 - single sound, \n2 - group of sounds, \n3 - classic random composition, \n4 - random with parametres, \n0 - exit\n", 7);
	cin >> mode;
	switch (mode)
	{
	case 1: Task(frequency, time); break;
	//case 2: MultiTask(frequency, time); break;
	case 3: ClassicRandom(); break;
	//case 4: MultiTask(frequency, time); break;
	default: cout << "\nnothing to play";
	};


    

    return 0;
}