// draw.cpp
// Written by Toby Donaldson for CMPT 125; modified by Amanda Ngo

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "draw.h"

using namespace std;

int main()
{
    sf::RenderWindow win(sf::VideoMode(WIDTH, HEIGHT));
    win.setFramerateLimit(60);
    bool drawn = false;

    // main animation loop
    while (win.isOpen()) {

        sf::Event event;
        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                win.close();
            }
        }

        if (!drawn) {
            win.clear(sf::Color::Black);
            process_lines(win);
            drawn = true;
        }

        win.display();
    } 
} // main
