#include <iostream>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

void play_sound(int frequency) {
    /*
    This function plays a sound with the specified frequency.

    Parameters:
    frequency (int): The frequency of the sound to be played

    Returns:
    None
    */
    try {
        // Check if frequency is within range
        if (frequency < 37 || frequency > 32767) {
            throw std::out_of_range("Frequency must be between 37 and 32767 Hz");
        }

        // Play the sound
        Beep(frequency, 1000);
    }
    catch (std::out_of_range& e) {
        // Log the error
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    // Play a sound with frequency 440 Hz
    play_sound(440);
    play_sound(660);
    return 0;
}