#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
using namespace std;
#pragma warning(disable:4996)

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

void Message(string text, int color=7)
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
	system("cls");
	cout << "frequency = ";
	Color(PickColor(frequency));
	cout << frequency;
	Color(7);
	cout << "\nduration = ";
	cout << duration;
	Beep(frequency, duration);
	system("cls");
}


void Task()
{
	int frequency, duration;
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

int EnterValue(string text, int min=0, int max=INT_MAX)
{
	int value;
	cout << "Enter " << text << endl;
	do
	{
		cin >> value;
		if (value < min || value > max) Message("Incorrect value, try again!\n", 12);
	} while (value < min || value > max);
	return value;
}

void Text2Numbers(char* freq, int& length, int*& frequencies)
{
	char* token = strtok(freq, " ,,");
	AddNote(length, frequencies, atoi(token));
	
	while (true)
	{
		token = strtok(NULL, " ,");
		if (token == NULL) break;
		AddNote(length, frequencies, atoi(token));
	}
}

bool CheckNumbers(char* text)
{
	int length = strlen(text);
	for (int i = 0; i < length; i++)
		if (isdigit(text[i]) == 0 && text[i] != 32 && text[i] != ',') return false;
	return true;
}


void MultiTask()
{
	char freq[1000];
	int duration, length=0;
	int* frequencies = new int[length]; 
	cout << "Enter frequencies (separate with comas or space)\n";
	do
	{
	cin.ignore();
	cin.getline(freq, 1000);
	if (!CheckNumbers(freq)) Message("Incorrect symbols, try again\n", 12);
	} while (!CheckNumbers(freq));

	Text2Numbers(freq, length, frequencies);
	duration = EnterValue("duration", 1);
	for (int i=0; i<length; i++)
	Play_sound(frequencies[i], duration);
	
}

void ClassicRandom()
{
	for (int i = 1; i < 100; i++)
	{
		Play_sound(rand() * 0.1, 100 + rand() % 20);

	}
}

void MultiRandom()
{
	int fmin, fmax, tmin, tmax, sounds;
	fmin = EnterValue("mininal frequency (>20)", 20, 20000);
	fmax = EnterValue("maximum frequency", fmin, 20000);
	tmin = EnterValue("minimum duration (>10)", 10);
	tmax = EnterValue("maximum duration", tmin);
	sounds = EnterValue("number of notes", 1);
	
	for (int i = 0; i < sounds; i++) 
	{
		Play_sound(rand()%(fmax - fmin) + fmin, rand()%(tmax - tmin) + tmin);
		//cout << rand() % (tmax - tmin) + fmin;
	}
}




int main() {
    int mode, oncemore;
	do
	{
		Message("Choose mode\n", 11);
		Message("\n1 - single sound, \n2 - group of sounds, \n3 - classic random composition, \n4 - random with parametres, \n5 - gradual, \n0 - exit\n", 7);
		cin >> mode;
		switch (mode)
		{
		case 1: Task(); break;
		case 2: MultiTask(); break;
		case 3: ClassicRandom(); break;
		case 4: MultiRandom(); break;
		default: Message("\nnothing to play", 4);
		};
		Message("\nDo you want to try again?", 11);
		cout << "\n1 - yes, 0 - exit\n";
		cin >> oncemore;
	}while(oncemore);

	Message("\nThank you for using our programm!", 10);
    return 0;
}