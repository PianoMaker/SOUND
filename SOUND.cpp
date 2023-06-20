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
	else if (frequency > 4000) return 11;
	else if (frequency > 8000) return 9;
	else return 14;
}

void Message(string text, int color)
{
	Color(color);
	cout << text;
	Color(7);
}

void Play_sound(int frequency, int duration) {
	if (frequency % 2 == 1)  frequency++;

	if (frequency < 1)
	{
		Message("Error", 12); return;
	}
	Color(PickColor(frequency));
	cout << frequency;
	Color(7);
	Beep(frequency, duration);
	system("cls");
}


void Task(int& frequency, int& duration)
{
    cout << "Enter frequency\n";
    cin >> frequency;
    cout << "Enter duration\n";
    cin >> duration;
	Play_sound(frequency, duration);
}

void AddNote(int& length, int*& frequencies, int newfrequency)
{
	int* temp = new int[length + 1];
	for (int i = 0; i < length; i++)
		temp[i] = frequencies[i];
	temp[length] = newfrequency;
	delete[] frequencies;
	frequencies = temp;
	length++;
}

void Text2Numbers(char* freq, int& length, int*& frequencies)
{
	char* token = strtok(freq, " ");
	AddNote(length, frequencies, atoi(token));
	while (true)
	{
		token = strtok(NULL, " ,");
		AddNote(length, frequencies, atoi(token));
		if (token == NULL)
			break;
	}
}


void MultiTask()
{
	char freq[1000];
	int duration, length=0;
	int* frequency = new int[length]; 
	cout << "Enter frequencies (separate with comas or space)\n";
	cin.getline(freq, 1000);
	Text2Numbers();
	cout << "Enter duration\n";
	cin >> duration;
	for (int i=0; i<length; i++)
	Play_sound(frequency[i], duration);
	
}

void ClassicRandom()
{
	for (int i = 1; i < 100; i++)
	{
		Play_sound(rand() * 0.1, 100 + rand() % 20);

	}
}



int main() {
    int frequency, duration, mode;
	Message("Choose mode\n", 11);
	Message("\n1 - single sound, \n2 - group of sounds, \n3 - classic random composition, \n4 - random with parametres, \n0 - exit\n", 7);
	cin >> mode;
	switch (mode)
	{
	case 1: Task(frequency, duration); break;
	//case 2: MultiTask(frequency, duration); break;
	case 3: ClassicRandom(); break;
	//case 4: MultiTask(frequency, duration); break;
	default: cout << "\nnothing to play";
	};


    

    return 0;
}