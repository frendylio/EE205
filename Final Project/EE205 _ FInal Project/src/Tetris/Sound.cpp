#include "Sound.hpp"
#include <iostream>
using namespace std;

// Find my sound files location :#
SoundTetrisCleaner::SoundTetrisCleaner()
{

    soundCleaner.loadFromFile("\res\music\Tetris\Tetris_Clean_Row.wav");

}

void SoundTetrisCleaner::playSoundTetrisCleaner()
{

    fire_sound.setBuffer(soundCleaner);
    fire_sound.play();
    cout << "Tetris Cleaning Sound \n";
}