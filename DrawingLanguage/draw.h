// draw.h
// Amanda Ngo
// May 28, 2021
// Create a program which creates shapes according to a text file

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

// screen dimensions
const int WIDTH  = 500;
const int HEIGHT = 500; 

std::string colour;
std::string shape;
int width;
int height;
int radius;
int x_coord;
int y_coord;
void process_lines(sf::RenderWindow& win) {
	while (!(std::cin.eof())){
	std::cin >> colour;
	std::cin >> shape;
		if (shape == "rectangle"){
			std::cin >> width;
			std::cin >> height;
			std::cin >> x_coord;
			std::cin >> y_coord;
			sf::RectangleShape rectangle(sf::Vector2f(width, height));
			rectangle.setFillColor(sf::Color::Red);
    			rectangle.setPosition(x_coord,y_coord);
    			rectangle.setOrigin(width/2,height/2);
    			if (colour == "black"){
    				rectangle.setFillColor(sf::Color::Black);
    				win.draw(rectangle);
    			}
    			if (colour == "white"){
    				rectangle.setFillColor(sf::Color::White);
    				win.draw(rectangle);
    			}
    			if (colour == "red"){
    				rectangle.setFillColor(sf::Color::Red);
    				win.draw(rectangle);
    			}
    			if (colour == "green"){
    				rectangle.setFillColor(sf::Color::Green);
    				win.draw(rectangle);
    			}
    			if (colour == "blue"){
    				rectangle.setFillColor(sf::Color::Blue);
    				win.draw(rectangle);
    			}
    			if (colour == "yellow"){
    				rectangle.setFillColor(sf::Color::Yellow);
    				win.draw(rectangle);
    			}
    			if (colour == "magenta"){
    				rectangle.setFillColor(sf::Color::Magenta);
    				win.draw(rectangle);
    			}
    			if (colour == "cyan"){
    				rectangle.setFillColor(sf::Color::Cyan);
    				win.draw(rectangle);
    			}
    		}
    		if (shape == "circle"){
			std::cin >> radius;
			std::cin >> x_coord;
			std::cin >> y_coord;
			sf::CircleShape circle;
			circle.setRadius(radius);
    			circle.setPosition(x_coord,y_coord);
    			circle.setOrigin(radius,radius);
    			if (colour == "black"){
    				circle.setFillColor(sf::Color::Black);
    				win.draw(circle);
    			}
    			if (colour == "white"){
    				circle.setFillColor(sf::Color::White);
    				win.draw(circle);
    			}
    			if (colour == "red"){
    				circle.setFillColor(sf::Color::Red);
    				win.draw(circle);
    			}
    			if (colour == "green"){
    				circle.setFillColor(sf::Color::Green);
    				win.draw(circle);
    			}
    			if (colour == "blue"){
    				circle.setFillColor(sf::Color::Blue);
    				win.draw(circle);
    			}
    			if (colour == "yellow"){
    				circle.setFillColor(sf::Color::Yellow);
    				win.draw(circle);
    			}
    			if (colour == "magenta"){
    				circle.setFillColor(sf::Color::Magenta);
    				win.draw(circle);
    			}
    			if (colour == "cyan"){
    				circle.setFillColor(sf::Color::Cyan);
    				win.draw(circle);
    			}
  
		}
	}
    	
}

/* Websites used:
https://www.sfml-dev.org/tutorials/2.4/graphics-shape.php for working with shapes
https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1CircleShape.php for working with circles
https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RectangleShape.php
for working with rectangles */

