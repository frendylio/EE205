#ifndef KEYBUFFER_H
#define KEYBUFFER_H

#include "Graphics.hpp"

// This is from SFML fors keyyssss
namespace KeyBuffer {

    void processEvent(const sf::Event &e);
    sf::Keyboard::Key popKey();
    bool hasKeys();

}

#endif
