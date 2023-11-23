#pragma once
#include <SFML/Graphics.hpp>
#include "Global.hpp"

class Pacman
{
private:
    sf::CircleShape player;
    float speed;
    sf::Vector2f direction;

public:
    Pacman();
    void initShape();
    void respawn();
    void move(std::vector<std::string>& map);
    void handleInput(sf::Event& event);
    void draw(sf::RenderWindow& window);
};
