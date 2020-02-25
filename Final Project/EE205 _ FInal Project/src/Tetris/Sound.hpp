#pragma once
#include "Audio.hpp"

//Class for the Sound
// Thanks SFML documentation for teaching me THIS :#
class SoundTetrisCleaner
{
private:
    sf::SoundBuffer soundCleaner;
    sf::Sound fire_sound;
public:
    SoundTetrisCleaner();
    void playSoundTetrisCleaner();

};