#pragma once
#include "Global.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

class Pacman
{
    Position position;
public:
    Pacman();
    void draw(sf::RenderWindow& i_window); 
    void set_position(unsigned short i_x, unsigned short i_y);
    void handle_input();
};