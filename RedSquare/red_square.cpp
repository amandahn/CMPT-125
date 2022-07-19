// red_square.cpp
// Amanda Ngo
// May 27, 2021
// Create a rotating red square

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "draw.h"

using namespace std;

int main()
{   // create window
    sf::RenderWindow win(sf::VideoMode(500, 500), "Assignment 1");
    win.setFramerateLimit(60);
    
    // define a red square and set its origin
    sf::RectangleShape square(sf::Vector2f(300, 300));
    square.setFillColor(sf::Color::Red);
    square.setPosition(250,250);
    square.setOrigin(150,150);
    	
    // main animation loop
    while (win.isOpen()) {
        // check all window events that were triggered; always check for
        // sf::Event::Closed so that the window can be closed
        sf::Event event;
        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                win.close();
            }
        }
	
	// rotate with mouse movement
	double cursor = sf::Mouse::getPosition(win).x;
   	if (cursor < 100){
   			square.rotate(1);
   	}
   	if (cursor >= 100 && cursor< 400){
   		double rotate_speed = cursor/100;
   		square.rotate(rotate_speed);
   	}
   	if (cursor >= 400){
   		square.rotate(4);
   	}
   	// reverse mouse movement with left click
	if(event.mouseButton.button == sf::Mouse::Left){
		if (cursor < 0){
			cursor = cursor*-1;
		}
   			if (cursor < 100){
   				square.rotate(-2);
   			}
   			if (cursor >= 400){
   				square.rotate(-8);
   			}
   			if (cursor >=100 && cursor <400){
   				double rotate_speed = cursor/-50;
   				square.rotate(rotate_speed);
   			}
   	}

  	win.clear();
  	win.draw(square);
        // end the current frame and display the window
        win.display();
    } // while
} // main

/* Websites used
https://www.sfml-dev.org/tutorials/2.4/graphics-shape.php for working with shapes
https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RectangleShape.php
for working with rectangles *
https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Mouse.php for working with mouse
https://www.sfml-dev.org/tutorials/2.5/graphics-transform.php for working with shape rotations
https://www.sfml-dev.org/tutorials/2.5/window-events.php for working with events */

